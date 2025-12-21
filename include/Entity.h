#ifndef ENTITY_H
#define ENTITY_H

class World;

class Entity {
public:
    virtual ~Entity() = default;
    virtual void update(World& world) = 0;
    virtual bool isAlive() const = 0;
};

#endif
