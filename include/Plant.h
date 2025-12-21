#ifndef PLANT_H
#define PLANT_H

#include "Entity.h"

class Plant : public Entity {
public:
    Plant(double initialEnergy);

    void update(World& world) override;
    bool isAlive() const override;

private:
    double energy;
};

#endif
