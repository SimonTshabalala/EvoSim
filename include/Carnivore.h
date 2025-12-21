#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "Entity.h"

class World;

class Carnivore : public Entity {
public:
    explicit Carnivore(double initialEnergy);

    void update(World& world) override;
    bool isAlive() const override;

private:
    double energy;
};

#endif
