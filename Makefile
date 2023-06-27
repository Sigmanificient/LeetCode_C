SRC :=

MAKEFILES += 0000-hello

define include-me
include src/$(strip $(1))/local.mk

endef

$(eval $(foreach m, $(MAKEFILES), $(call include-me, $m)))
$(info : included $(words $(MAKEFILES)) mks)

include ./global.mk
