START_TIME := $(shell date +%s%3N)

# ↓ Remove builtin rules
.SUFFIXES:

# ↓ Config
CC := gcc
NAME = 42sh

CFLAGS := -W -Wall -Wextra
CFLAGS += -U_FORTIFY_SOURCE
CFLAGS += -iquote ./include

ifeq ($(FORCE_DEBUG),1)
    CFLAGS += -D DEBUG_MODE
endif

BUILD_DIR ?= .build

TESTS := run_tests

BINS := $(TESTS)
vpath %.c $(VPATH)

# ↓ `touch .fast` to force multi-threading
ifneq ($(shell find . -name ".fast"),)
    MAKEFLAGS += -j
endif

# ↓ Quiet
V ?=
ifeq ($(V), 1)
    $(info Verbose mode enabled)
    Q :=
else
    Q := @
endif

# ↓ Generators
TSRC := $(subst //,/,$(SRC))

TEST_OBJ := $(TSRC:%.c=$(BUILD_DIR)/%.o)

OBJS += $(TEST_OBJ)
ALL_OBJS := $(TEST_OBJ)

CMD_NOT_FOUND = $(error $(strip $(1)) is required for this rule)
CHECK_CMD = $(if $(shell command -v $(1)),, $(call CMD_NOT_FOUND, $(1)))

# ↓ Utils
ifneq ($(shell tput colors),0)
    C_RESET := \033[00m
    C_BOLD := \e[1m
    C_RED := \e[31m
    C_GREEN := \e[32m
    C_YELLOW := \e[33m
    C_BLUE := \e[34m
    C_PURPLE := \e[35m
    C_CYAN := \e[36m
endif

_SOLVE_COLORS = $(subst :r,$(C_RED), \
    $(subst :c,$(C_CYAN),            \
    $(subst :p,$(C_PURPLE),          \
    $(subst :y,$(C_YELLOW),          \
    $(subst :b,$(C_BLUE),            \
    $(subst :g,$(C_GREEN),           \
    $(subst *,$(C_BOLD),             \
    $(subst ~,$(C_RESET),            \
    $(addprefix $(call _UNQUOTE,$(1)),~)))))))))

_UNQUOTE = $(subst ",,$(subst ',,$(1)))##") ## <- Hack to make highlighter happy
_QUOTE = "$(strip $(1))"

COLORIZE = $(call _QUOTE, $(call _SOLVE_COLORS, $(1)))

CURRENT_TIME_MS = $(shell date +%s%3N)
TIME = $(shell expr $(call CURRENT_TIME_MS) - $(START_TIME))

HEADER := ":p"
LOG = @ echo -e $(call COLORIZE,$(2) ~$(TIME_BOX) $(HEADER)~ $(1)~)
TIME_BOX = "[ :b"$(call TIME)"~\t]"

# ↓ Rules
all: tests_run

.PHONY: all

CLEAN += $(TEST_OBJ)
FCLEAN := $(shell find . -type f -name run_tests)
FCLEAN += $(BUILD_DIR)

clean:
	$(call _FIND_LOG, $(CLEAN))

ifneq ($(CLEAN),)
	$Q $(RM) $(CLEAN)
endif

fclean:
	$(call _FIND_LOG, $(FCLEAN))

	$Q $(RM) -f vgcore.*
ifneq ($(FCLEAN),)
	$Q $(RM) -r $(FCLEAN)
endif

_FIND_LOG = $(if                                             \
	$(shell find $(1) 2> /dev/null),                         \
	$(call LOG,"Removed:r" $(shell find $(1) 2> /dev/null)), \
)

.PHONY: clean fclean

re: fclean
	+ $Q $(call RECURSE, all)

.PHONY: re

$(BUILD_DIR)/%.o: %.c
	$Q mkdir -p $(dir $@)
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$(call LOG,":c" $(notdir $@))

ifneq ($(NO_COV),1)
$(TESTS): CFLAGS += -g3 --coverage
$(TESTS): LDFLAGS += -fprofile-arcs -ftest-coverage
endif
$(TESTS): LDLIBS += -lcriterion -lasan
$(TESTS): LDFLAGS += -fsanitize=address,leak,undefined
$(TESTS): $(TEST_OBJ)
	$Q $(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) $(LDFLAGS)
	$(call LOG,":g$@")

tests_run: $(TESTS)
	@ ./$(TESTS) -j 8 --verbose=1

.PHONY: tests_run

cov: tests_run
	$(call CHECK_CMD, gcovr)
	$Q $(call CHECK_CMD, gcovr)
	$Q gcovr . -e "src/[-\w\d]+/tests.c" --exclude-directories .direnv

.PHONY: cov

# ↓ Utils
RECURSE = $(MAKE) $(1) --no-print-directory START_TIME=$(START_TIME)

# ↓ file & rules guard
SENTINEL = $(error Missing $(if $(findstring .,$(1)),file,rule) $(1))

# ↓ User override
ifneq ($(shell find . -name override.mk),)
-include override.mk
endif
