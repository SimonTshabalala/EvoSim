#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

class Entity;

class World {
public:
    World();
    ~World();  // <-- THIS LINE FIXES THE ERROR

    void addEntity(std::unique_ptr<Entity> entity);
    void update();
    unsigned long long getTick() const;

private:
    unsigned long long tick;
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif
