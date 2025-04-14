#!/bin/sh
clang++ backend/main.cpp utils/*
mv a.out backend.out
clang++ frontend/main.cpp utils/*
mv a.out frontend.out

