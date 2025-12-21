#include "Omnivore.h"
#include "World.h"
#include "Plant.h"
#include "Herbivore.h"
#include <iostream>

static constexpr double MAINTENANCE_COST = 0.4;
static constexpr double REPRODUCTION_THRESHOLD = 4.0;
static constexpr double REPRODUCTION_COST = 2.0;
static constexpr double OFFSPRING_ENERGY = 2.0;
static constexpr double ENERGY_FROM_PLANT = 1.0;
static constexpr double ENERGY_FROM_HERBIVORE = 3.0;

Omnivore::Omnivore(double initialEnergy) : energy(initialEnergy) {}

void Omnivore::update(World& world) {
    bool ateSomething = false;

    // Try to eat a herbivore first
    auto prey = world.consumeHerbivore();
    if (prey) {
        energy += ENERGY_FROM_HERBIVORE;
        ateSomething = true;
        std::cout << "[Omnivore] Ate a Herbivore!\n";
    } else {
        // Otherwise try to eat a plant
        auto plant = world.consumePlant();
        if (plant) {
            energy += ENERGY_FROM_PLANT;
            ateSomething = true;
            std::cout << "[Omnivore] Ate a Plant!\n";
        }
    }

    energy -= MAINTENANCE_COST;

    if (energy >= REPRODUCTION_THRESHOLD) {
        energy -= REPRODUCTION_COST;
        world.addEntity(std::make_unique<Omnivore>(OFFSPRING_ENERGY));
        std::cout << "[Omnivore] Reproduced!\n";
    }

    if (energy <= 0) {
        kill();
        std::cout << "[Omnivore] Died!\n";
    }
}

bool Omnivore::isAlive() const {
    return alive && energy > 0;
}
