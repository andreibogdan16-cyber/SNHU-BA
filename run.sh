#!/usr/bin/env bash
set -e
g++ -std=c++17 -O2 -Wall -Wextra -o grocer main.cpp
./grocer
