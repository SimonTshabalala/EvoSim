#include "Plant.h"
#include "World.h"
#include <iostream>

static constexpr double GROWTH = 0.5;
static constexpr double MAINTENANCE_COST = 0.2;
static constexpr double REPRODUCTION_THRESHOLD = 2.0;
static constexpr double REPRODUCTION_COST = 1.0;
static constexpr double OFFSPRING_ENERGY = 1.0;

Plant::Plant(double initialEnergy) : energy(initialEnergy) {}

void Plant::update(World& world) {
    energy += GROWTH;
    energy -= MAINTENANCE_COST;

    if (energy >= REPRODUCTION_THRESHOLD) {
        energy -= REPRODUCTION_COST;
        world.addEntity(std::make_unique<Plant>(OFFSPRING_ENERGY));
        std::cout << "[Plant] Reproduced!\n";
    }
}

bool Plant::isAlive() const {
    return alive && energy > 0;
}
