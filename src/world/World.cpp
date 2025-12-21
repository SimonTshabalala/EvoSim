#include "World.h"
#include "Entity.h"

#include <algorithm>

World::World() : tick(0) {}

World::~World() = default;

// During update, we add to a separate vector to avoid modifying the main vector mid-loop
void World::addEntity(std::unique_ptr<Entity> entity) {
    newEntities.push_back(std::move(entity));
}

void World::update() {
    ++tick;

    // Update living entities
    for (auto& e : entities) {
        if (e->isAlive()) {
            e->update(*this);  // safe: addEntity goes to newEntities
        }
    }

    // Remove dead entities
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

    // Move newly added entities into the main vector
    entities.insert(
        entities.end(),
        std::make_move_iterator(newEntities.begin()),
        std::make_move_iterator(newEntities.end())
    );
    newEntities.clear();
}

unsigned long long World::getTick() const {
    return tick;
}

std::size_t World::population() const {
    return entities.size();
}
