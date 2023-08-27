BUILD_DIR := ../../.build/src/$(notdir $(CURDIR))
D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/tests.c
SRC += $D/solution.c

ifndef DELAY_GLOBAL_IMPORT
  include ../../global.mk
endif
