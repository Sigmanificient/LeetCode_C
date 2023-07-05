SRC :=

MAKEFILES += 0000-hello
MAKEFILES += 0001-two-sum
MAKEFILES += 0002-add-two-numbers
MAKEFILES += 0003-longest-substring-without-repeating-characters
MAKEFILES += 0004-median-of-two-sorted-arrays

define include-me
include src/$(strip $(1))/local.mk

endef

$(eval $(foreach m, $(MAKEFILES), $(call include-me, $m)))
$(info : included $(words $(MAKEFILES)) mks)

include ./global.mk
