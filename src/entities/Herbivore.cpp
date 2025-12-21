#include "Herbivore.h"
#include "World.h"
#include "Plant.h"
#include <iostream>

static constexpr double MAINTENANCE_COST = 0.3;
static constexpr double REPRODUCTION_THRESHOLD = 3.0;
static constexpr double REPRODUCTION_COST = 1.5;
static constexpr double OFFSPRING_ENERGY = 1.0;
static constexpr double ENERGY_FROM_PLANT = 1.0;

Herbivore::Herbivore(double initialEnergy) : energy(initialEnergy) {}

void Herbivore::update(World& world) {
    auto plant = world.consumePlant();
    if (plant) {
        energy += ENERGY_FROM_PLANT;
        std::cout << "[Herbivore] Ate a Plant!\n";
    }

    energy -= MAINTENANCE_COST;

    if (energy >= REPRODUCTION_THRESHOLD) {
        energy -= REPRODUCTION_COST;
        world.addEntity(std::make_unique<Herbivore>(OFFSPRING_ENERGY));
        std::cout << "[Herbivore] Reproduced!\n";
    }

    if (energy <= 0) {
        kill();
        std::cout << "[Herbivore] Died!\n";
    }
}

bool Herbivore::isAlive() const {
    return alive && energy > 0;
}
