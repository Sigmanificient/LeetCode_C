D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/two_sum.c
SRC += $D/tests.c
