# EvoSim

**EvoSim** is a simple C++ ecosystem simulation.  
It models a `World` with entities that can **grow, reproduce, and die**. Current entities include:

- `Plant` — grows energy and reproduces.
- `Herbivore` — consumes energy (simulated), reproduces, and dies if energy runs out.

The simulation demonstrates:

- Polymorphism using a base `Entity` class.
- Safe memory management using `std::unique_ptr`.
- Emergent behavior: population growth and interactions.

## How to Build

```bash
rm -f evosim
g++ src/main.cpp \
    src/world/World.cpp \
    src/entities/Entity.cpp \
    src/entities/Plant.cpp \
    src/entities/Herbivore.cpp \
    -Iinclude -o evosim && ./evosim

