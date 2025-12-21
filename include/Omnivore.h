#ifndef OMNIVORE_H
#define OMNIVORE_H

#include "Entity.h"

class World;

class Omnivore : public Entity {
public:
    explicit Omnivore(double initialEnergy);

    void update(World& world) override;
    bool isAlive() const override;

private:
    double energy;
};

#endif
