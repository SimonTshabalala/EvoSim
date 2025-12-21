# 🌱 EvoSim – Ecosystem Simulation in C++

Welcome to **EvoSim**, a tiny but lively C++ ecosystem simulator!  
Watch your world grow and evolve as **Plants** and **Herbivores** live, reproduce, and interact. 🌿🦌

---

## 🎯 What It Does

- `Plant` 🌱: grows energy each tick, reproduces when strong enough.  
- `Herbivore` 🦌: consumes energy (simulated eating), reproduces, and dies if it runs out.  
- `World` 🌍: the master controller — updates entities, adds new ones, and removes the dead safely.  

**Polymorphism** + **smart pointers** = a safe, extensible ecosystem!

---

## ⚡ How to Build

```bash
rm -f evosim
g++ src/main.cpp \
    src/world/World.cpp \
    src/entities/Entity.cpp \
    src/entities/Plant.cpp \
    src/entities/Herbivore.cpp \
    -Iinclude -o evosim && ./evosim
