BUILD_DIR := ../../.build/src/$(notdir $(CURDIR))
D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/hashmap.c
SRC += $D/single_linked_list.c
SRC += $D/two_sum.c
SRC += $D/tests.c

ifndef DELAY_GLOBAL_IMPORT
  include ../../global.mk
endif
