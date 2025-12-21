#include <iostream>
#include <memory>

#include "World.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"

int main() {
    World world;

    // Add entities
    world.addEntity(std::make_unique<Plant>(1.0));
    world.addEntity(std::make_unique<Plant>(0.8));
    world.addEntity(std::make_unique<Plant>(0.5));

    world.addEntity(std::make_unique<Herbivore>(2.0));
    world.addEntity(std::make_unique<Herbivore>(1.5));

    world.addEntity(std::make_unique<Carnivore>(4.0));

    world.addEntity(std::make_unique<Omnivore>(3.0));
    world.addEntity(std::make_unique<Omnivore>(2.0));

    // Simulation loop
    for (int i = 0; i < 30; ++i) {
        world.update();

        std::cout << "Tick: " << world.getTick()
                  << " | Total: " << world.population()
                  << " | Plants: " << world.countPlants()
                  << " | Herbivores: " << world.countHerbivores()
                  << " | Carnivores: " << world.countCarnivores()
                  << " | Omnivores: " << world.countOmnivores()
                  << "\n";
    }

    return 0;
}
