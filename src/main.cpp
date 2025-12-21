#include <iostream>
#include <memory>

#include "World.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"

int main() {
    World world;

    // Plants
    world.addEntity(std::make_unique<Plant>(1.0));
    world.addEntity(std::make_unique<Plant>(0.8));
    world.addEntity(std::make_unique<Plant>(0.5));

    // Herbivores
    world.addEntity(std::make_unique<Herbivore>(2.0));
    world.addEntity(std::make_unique<Herbivore>(1.5));

    // Carnivores
    world.addEntity(std::make_unique<Carnivore>(4.0));

    // Omnivores
    world.addEntity(std::make_unique<Omnivore>(3.0));
    world.addEntity(std::make_unique<Omnivore>(2.0));

    // Simulation
    for (int i = 0; i < 30; ++i) {
        world.update();
        std::cout << "Tick: " << world.getTick()
                  << " | Population: " << world.population() << "\n";
    }

    return 0;
}
