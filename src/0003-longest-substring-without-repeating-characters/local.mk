D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/tests.c
SRC += $D/longest_substring.c