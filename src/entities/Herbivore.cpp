#include "Herbivore.h"
#include "World.h"
#include "Plant.h"

#include <memory>
#include <algorithm>

// Energy constants
static constexpr double MAINTENANCE_COST       = 0.3;
static constexpr double REPRODUCTION_THRESHOLD = 3.0;
static constexpr double REPRODUCTION_COST      = 1.5;
static constexpr double OFFSPRING_ENERGY       = 1.0;
static constexpr double ENERGY_FROM_PLANT      = 1.0;

Herbivore::Herbivore(double initialEnergy)
    : energy(initialEnergy) {}

void Herbivore::update(World& world) {
    // Gain energy from plants (simplified for now)
    energy += ENERGY_FROM_PLANT;

    // Maintenance cost
    energy -= MAINTENANCE_COST;

    // Reproduce if energy is high enough
    if (energy >= REPRODUCTION_THRESHOLD) {
        energy -= REPRODUCTION_COST;
        world.addEntity(std::make_unique<Herbivore>(OFFSPRING_ENERGY));
    }
}

bool Herbivore::isAlive() const {
    return energy > 0;
}
