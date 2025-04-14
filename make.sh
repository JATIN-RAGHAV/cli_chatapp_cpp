#!/bin/sh
echo "compiling backend"
clang++ backend/main.cpp utils/*.cpp
mv a.out backend.out
echo "compiling fronend"
clang++ frontend/main.cpp utils/*.cpp
mv a.out frontend.out
