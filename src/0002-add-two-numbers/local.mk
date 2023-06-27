D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/tests.c
SRC += $D/add_two_numbers.c
