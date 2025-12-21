#include <iostream>
#include <memory>

#include "World.h"
#include "Plant.h"

int main() {
    World world;

    world.addEntity(std::make_unique<Plant>(1.0));
    world.addEntity(std::make_unique<Plant>(0.2));

    for (int i = 0; i < 10; ++i) {
        world.update();
        std::cout << "Tick: " << world.getTick() << std::endl;
    }

    return 0;
}
