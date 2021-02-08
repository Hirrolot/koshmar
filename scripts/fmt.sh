#!/bin/bash

find include tests examples bench -iname *.h -o -iname *.c \
    -path examples/build -prune \
    -path tests/build -prune | xargs clang-format -i
