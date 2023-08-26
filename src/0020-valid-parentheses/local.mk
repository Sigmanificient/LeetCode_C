D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/solution.c
SRC += $D/tests.c
