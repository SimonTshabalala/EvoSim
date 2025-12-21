#include "Plant.h"
#include "World.h"

static constexpr double PHOTOSYNTHESIS_RATE = 0.5;
static constexpr double DEATH_THRESHOLD = 0.0;

Plant::Plant(double initialEnergy)
    : energy(initialEnergy) {}

void Plant::update(World&) {
    energy += PHOTOSYNTHESIS_RATE;
}

bool Plant::isAlive() const {
    return energy > DEATH_THRESHOLD;
}
