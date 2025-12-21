#include <iostream>
#include <memory>

#include "World.h"
#include "Plant.h"

int main() {
    World world;

    world.addEntity(std::make_unique<Plant>(0.1));
    world.addEntity(std::make_unique<Plant>(1.0));

    for (int i = 0; i < 10; ++i) {
        world.update();
        std::cout << "Tick: " << world.getTick()
                  << " | Population: " << world.population()
                  << std::endl;
    }

    return 0;
}
