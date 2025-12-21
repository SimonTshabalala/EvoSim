#include "World.h"
#include "Entity.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"

#include <iostream>
#include <algorithm>
#include <typeinfo>

World::World(const std::string& csvFilePath) : tick(0), csvFile(csvFilePath) {
    if (!csvFile.empty()) {
        csvStream.open(csvFile, std::ios::out);
        csvStream << "Tick,Total,Plants,Herbivores,Carnivores,Omnivores\n";
    }
}

World::~World() {
    if (csvStream.is_open()) csvStream.close();
}

void World::addEntity(std::unique_ptr<Entity> entity) {
    newEntities.push_back(std::move(entity));
}

void World::update() {
    ++tick;

    for (auto& e : entities) {
        if (e->isAlive()) e->update(*this);
    }

    entities.erase(
        std::remove_if(entities.begin(), entities.end(),
            [](const std::unique_ptr<Entity>& e){ return !e->isAlive(); }),
        entities.end()
    );

    entities.insert(
        entities.end(),
        std::make_move_iterator(newEntities.begin()),
        std::make_move_iterator(newEntities.end())
    );
    newEntities.clear();

    logStats();
}

void World::logStats() {
    if (!csvFile.empty() && csvStream.is_open()) {
        csvStream << tick << ","
                  << population() << ","
                  << countPlants() << ","
                  << countHerbivores() << ","
                  << countCarnivores() << ","
                  << countOmnivores() << "\n";
    }
}

// --- Existing functions remain unchanged ---
