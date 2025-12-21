#include "World.h"
#include "Entity.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"

#include <iostream>
#include <algorithm>
#include <typeinfo>

World::World() : tick(0) {}
World::~World() = default;

void World::addEntity(std::unique_ptr<Entity> entity) {
    newEntities.push_back(std::move(entity));
}

void World::update() {
    ++tick;

    for (auto& e : entities) {
        if (e->isAlive()) {
            e->update(*this);
        }
    }

    // Remove dead entities safely
    entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [](const std::unique_ptr<Entity>& e){ return !e->isAlive(); }),
        entities.end()
    );

    // Add queued entities
    entities.insert(
        entities.end(),
        std::make_move_iterator(newEntities.begin()),
        std::make_move_iterator(newEntities.end())
    );
    newEntities.clear();
}

unsigned long long World::getTick() const { return tick; }
std::size_t World::population() const { return entities.size(); }

std::unique_ptr<Plant> World::consumePlant() {
    for (auto& e : entities) {
        Plant* plant = dynamic_cast<Plant*>(e.get());
        if (plant && plant->isAlive()) {
            plant->kill();
            std::cout << "[World] Plant consumed!\n";
            return std::make_unique<Plant>(*plant);
        }
    }
    return nullptr;
}

std::unique_ptr<Entity> World::consumeHerbivore() {
    for (auto& e : entities) {
        Herbivore* herb = dynamic_cast<Herbivore*>(e.get());
        if (herb && herb->isAlive()) {
            herb->kill();
            std::cout << "[World] Herbivore consumed!\n";
            return std::make_unique<Herbivore>(*herb);
        }
    }
    return nullptr;
}

// --- Statistics functions ---
std::size_t World::countPlants() const {
    return std::count_if(entities.begin(), entities.end(),
        [](const std::unique_ptr<Entity>& e){ return dynamic_cast<Plant*>(e.get()) && e->isAlive(); });
}

std::size_t World::countHerbivores() const {
    return std::count_if(entities.begin(), entities.end(),
        [](const std::unique_ptr<Entity>& e){ return dynamic_cast<Herbivore*>(e.get()) && e->isAlive(); });
}

std::size_t World::countCarnivores() const {
    return std::count_if(entities.begin(), entities.end(),
        [](const std::unique_ptr<Entity>& e){ return dynamic_cast<Carnivore*>(e.get()) && e->isAlive(); });
}

std::size_t World::countOmnivores() const {
    return std::count_if(entities.begin(), entities.end(),
        [](const std::unique_ptr<Entity>& e){ return dynamic_cast<Omnivore*>(e.get()) && e->isAlive(); });
}
