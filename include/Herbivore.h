#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Entity.h"

class World;

class Herbivore : public Entity {
public:
    explicit Herbivore(double initialEnergy);

    void update(World& world) override;
    bool isAlive() const override;

private:
    double energy;
};

#endif
