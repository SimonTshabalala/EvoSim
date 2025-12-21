#include <iostream>
#include <memory>

#include "World.h"
#include "Plant.h"
#include "Herbivore.h"

int main() {
    World world;

    // Add initial plants
    world.addEntity(std::make_unique<Plant>(1.0));
    world.addEntity(std::make_unique<Plant>(0.5));
    world.addEntity(std::make_unique<Plant>(0.8));

    // Add initial herbivores
    world.addEntity(std::make_unique<Herbivore>(2.0));
    world.addEntity(std::make_unique<Herbivore>(1.5));

    // Run simulation for 30 ticks
    for (int i = 0; i < 30; ++i) {
        world.update();
        std::cout << "Tick: " << world.getTick()
                  << " | Population: " << world.population()
                  << std::endl;
    }

    return 0;
}
