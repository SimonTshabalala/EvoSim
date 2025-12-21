#!/bin/bash
# Simple build & test script for EvoSim

echo "Cleaning old binaries..."
rm -f evosim tests/test

echo "Compiling main simulation..."
g++ src/main.cpp \
    src/world/World.cpp \
    src/entities/Entity.cpp \
    src/entities/Plant.cpp \
    src/entities/Herbivore.cpp \
    -Iinclude -o evosim

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running main simulation..."
./evosim

echo "Compiling tests..."
g++ tests/test_main.cpp \
    src/world/World.cpp \
    src/entities/Entity.cpp \
    src/entities/Plant.cpp \
    src/entities/Herbivore.cpp \
    -Iinclude -o tests/test

if [ $? -ne 0 ]; then
    echo "Test compilation failed!"
    exit 1
fi

echo "Running tests..."
./tests/test

if [ $? -eq 0 ]; then
    echo "All tests passed!"
else
    echo "Some tests failed!"
    exit 1
fi
