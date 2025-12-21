#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <cstddef>

class Entity;

class World {
public:
    World();
    ~World();

    // Adds an entity to the world (queued if during update)
    void addEntity(std::unique_ptr<Entity> entity);
    void update();

    unsigned long long getTick() const;
    std::size_t population() const;

private:
    unsigned long long tick;
    std::vector<std::unique_ptr<Entity>> entities;

    // Temporary storage for new entities added during update
    std::vector<std::unique_ptr<Entity>> newEntities;
};

#endif
