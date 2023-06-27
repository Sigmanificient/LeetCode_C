D := $(dir $(lastword $(MAKEFILE_LIST)))

SRC += $D/hello.c
SRC += $D/tests.c
