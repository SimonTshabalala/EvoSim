#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>

class Entity;
class Plant;
class Herbivore;
class Carnivore;
class Omnivore;

class World {
public:
    explicit World(const std::string& csvFile = "");
    ~World();

    void addEntity(std::unique_ptr<Entity> entity);
    void update();

    unsigned long long getTick() const;
    std::size_t population() const;

    std::unique_ptr<Plant> consumePlant();
    std::unique_ptr<Entity> consumeHerbivore();

    std::size_t countPlants() const;
    std::size_t countHerbivores() const;
    std::size_t countCarnivores() const;
    std::size_t countOmnivores() const;

private:
    unsigned long long tick;
    std::vector<std::unique_ptr<Entity>> entities;
    std::vector<std::unique_ptr<Entity>> newEntities;

    // CSV logging
    std::string csvFile;
    std::ofstream csvStream;
    void logStats();
};

#endif
