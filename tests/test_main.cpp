#include "World.h"
#include "Plant.h"
#include "Herbivore.h"
#include <cassert>
#include <memory>

int main() {
    World world;
    world.addEntity(std::make_unique<Plant>(1.0));
    world.addEntity(std::make_unique<Herbivore>(2.0));

    unsigned long long initialTick = world.getTick();
    std::size_t initialPopulation = world.population();

    world.update();

    // Simple sanity checks
    assert(world.getTick() == initialTick + 1);
    assert(world.population() >= initialPopulation);

    return 0;
}
