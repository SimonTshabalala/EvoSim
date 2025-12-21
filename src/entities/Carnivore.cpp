#include "Carnivore.h"
#include "World.h"
#include "Herbivore.h"
#include <iostream>

static constexpr double MAINTENANCE_COST = 0.5;
static constexpr double REPRODUCTION_THRESHOLD = 5.0;
static constexpr double REPRODUCTION_COST = 2.0;
static constexpr double OFFSPRING_ENERGY = 2.0;
static constexpr double ENERGY_FROM_HERBIVORE = 3.0;

Carnivore::Carnivore(double initialEnergy) : energy(initialEnergy) {}

void Carnivore::update(World& world) {
    auto prey = world.consumeHerbivore();
    if (prey) {
        energy += ENERGY_FROM_HERBIVORE;
        std::cout << "[Carnivore] Ate a Herbivore!\n";
    }

    energy -= MAINTENANCE_COST;

    if (energy >= REPRODUCTION_THRESHOLD) {
        energy -= REPRODUCTION_COST;
        world.addEntity(std::make_unique<Carnivore>(OFFSPRING_ENERGY));
        std::cout << "[Carnivore] Reproduced!\n";
    }

    if (energy <= 0) {
        kill();
        std::cout << "[Carnivore] Died!\n";
    }
}

bool Carnivore::isAlive() const {
    return alive && energy > 0;
}
