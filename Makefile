SRC :=

MAKEFILES += 0000-hello
MAKEFILES += 0001-two-sum
MAKEFILES += 0002-add-two-numbers
MAKEFILES += 0003-longest-substring-without-repeating-characters
MAKEFILES += 0004-median-of-two-sorted-arrays
MAKEFILES += 0007-reverse-integer
MAKEFILES += 0009-palindrome-number
MAKEFILES += 0013-roman_to_integer
MAKEFILES += 0014-longest-common-prefix
MAKEFILES += 0020-valid-parentheses
MAKEFILES += 0021-merge-two-sorted-lists
MAKEFILES += 0024-swap-nodes-in-pairs

export DELAY_GLOBAL_IMPORT := 1

define include-me
include src/$(strip $(1))/Makefile

endef

$(eval $(foreach m, $(MAKEFILES), $(call include-me, $m)))
$(info : included $(words $(MAKEFILES)) mks)

include ./global.mk
