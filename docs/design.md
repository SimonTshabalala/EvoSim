
---

## 2️⃣ `design.md`

```markdown
# EvoSim Design Document

## Overview

EvoSim is a simple C++ ecosystem simulator.  
It models a `World` containing **entities** that act autonomously according to simple rules.

## Core Concepts

### World
- Owns all entities (`std::unique_ptr<Entity>`)
- Updates each entity every tick
- Safely handles adding new entities during updates
- Removes dead entities

### Entity (Base Class)
- Pure virtual base class
- Requires derived classes to implement:
  - `void update(World&)`
  - `bool isAlive() const`

### Plant (Derived Class)
- Has `energy`
- Gains energy per tick (photosynthesis)
- Pays maintenance cost
- Reproduces if energy > threshold

### Herbivore (Derived Class)
- Has `energy`
- Gains energy (simulated plant consumption)
- Pays maintenance cost
- Reproduces if energy > threshold
- Dies if energy ≤ 0

## Ownership and Memory
- Entities are stored in `std::unique_ptr` to manage lifetime
- Safe iteration: new entities are queued and appended after each tick
- Dead entities are removed using `erase–remove_if`

## Future Extensions
- Actual plant consumption by herbivores
- Predator-prey dynamics
- Multi-threaded updates
- Logging and statistics
