# EvoSim Usage Guide

1. Compile:

```bash
g++ src/main.cpp \
    src/world/World.cpp \
    src/entities/Entity.cpp \
    src/entities/Plant.cpp \
    src/entities/Herbivore.cpp \
    -Iinclude -o evosim
