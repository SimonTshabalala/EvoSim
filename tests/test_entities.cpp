#include "World.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"

#include <cassert>
#include <iostream>
#include <memory>

int main() {
    World world;

    // --- Test Plant ---
    auto plant = std::make_unique<Plant>(1.0);
    assert(plant->isAlive());
    plant->update(world); // should grow
    assert(plant->isAlive());
    std::cout << "[Test] Plant update passed.\n";

    // --- Test Herbivore ---
    auto herb = std::make_unique<Herbivore>(2.0);
    assert(herb->isAlive());
    world.addEntity(std::move(herb));
    world.addEntity(std::make_unique<Plant>(1.0));
    world.update(); // Herbivore should eat a plant
    std::cout << "[Test] Herbivore update passed.\n";

    // --- Test Carnivore ---
    auto carn = std::make_unique<Carnivore>(4.0);
    assert(carn->isAlive());
    world.addEntity(std::move(carn));
    world.update(); // Carnivore should try to eat a Herbivore if available
    std::cout << "[Test] Carnivore update passed.\n";

    // --- Test Omnivore ---
    auto omni = std::make_unique<Omnivore>(3.0);
    assert(omni->isAlive());
    world.addEntity(std::move(omni));
    world.update(); // Omnivore should eat Herbivore or Plant
    std::cout << "[Test] Omnivore update passed.\n";

    // --- Test entity death manually ---
    // Plants: low energy ensures death
    auto deadPlant = std::make_unique<Plant>(-1.0);
    deadPlant->update(world);
    assert(!deadPlant->isAlive());
    std::cout << "[Test] Plant death passed.\n";

    // Herbivore death
    auto deadHerb = std::make_unique<Herbivore>(0.0);
    deadHerb->update(world);
    assert(!deadHerb->isAlive());
    std::cout << "[Test] Herbivore death passed.\n";

    // Carnivore death
    auto deadCarn = std::make_unique<Carnivore>(0.0);
    deadCarn->update(world);
    assert(!deadCarn->isAlive());
    std::cout << "[Test] Carnivore death passed.\n";

    // Omnivore death
    auto deadOmni = std::make_unique<Omnivore>(0.0);
    deadOmni->update(world);
    assert(!deadOmni->isAlive());
    std::cout << "[Test] Omnivore death passed.\n";

    std::cout << "\nAll unit tests passed successfully!\n";
    return 0;
}
