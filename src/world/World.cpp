#include "World.h"
#include "Entity.h"   // full type is known here

World::World() : tick(0) {}

World::~World() = default;

void World::addEntity(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void World::update() {
    ++tick;
    for (auto& e : entities) {
        if (e->isAlive()) {
            e->update(*this);
        }
    }
}

unsigned long long World::getTick() const {
    return tick;
}
