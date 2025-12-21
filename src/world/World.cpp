#include "World.h"
#include "Entity.h"

#include <algorithm>

World::World() : tick(0) {}

World::~World() = default;

void World::addEntity(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void World::update() {
    ++tick;

    // Update living entities
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
            [](const std::unique_ptr<Entity>& e) {
                return !e->isAlive();
            }
        ),
        entities.end()
    );
}

unsigned long long World::getTick() const {
    return tick;
}

std::size_t World::population() const {
    return entities.size();
}
