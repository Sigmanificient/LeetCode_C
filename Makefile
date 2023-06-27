SRC :=

MAKEFILES += 0000-hello
MAKEFILES += 0001-two-sum

define include-me
include src/$(strip $(1))/local.mk

endef

$(eval $(foreach m, $(MAKEFILES), $(call include-me, $m)))
$(info : included $(words $(MAKEFILES)) mks)

include ./global.mk
