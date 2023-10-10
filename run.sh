#! /usr/bin/env bash

set -xe

CC=gcc
CFLAGS="-Wall -Wextra -Werror -masm=intel"
SRCS=main.c
OUTPUT=main

$CC $CFLAGS -o $OUTPUT $SRCS
./$OUTPUT