/* 
 * File:   Model.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:29
 */

#include "Model.h"

Model::Model() {
}

Model::~Model() {
    for(auto animalPtr : animalList_)
        delete animalPtr;
}

//Model(const Model& orig) {
//}

Animal::Coordinates Model::getCoordinates(const Animal* animalToGet) const {
    for(auto animalPtr : animalList_) {
        if(animalPtr == animalToGet) 
            return animalPtr->returnCoodtinates();
        
    // Albo niech rzuca wyjatek.
    return Animal::Coordinates(0.0, 0.0);
    }
}

void Model::updateAnimalsStatuses() {
    for(auto animalPtr : animalList_) {
        animalPtr->updateStatus();
    }
}

void Model::createHerbivore(const Animal* father, const Animal* mother) {
    if(father == nullptr && mother == nullptr) {
        // Tutaj nie tworzymy dziecka, a juz doroslego osobnika
        animalList_.push_back(new Herbivore());
    }
    else if(father == nullptr || mother == nullptr) {
        // Rzucic wyjatkiem
    }
    
    Animal* newHerbivore = new Herbivore(father, mother);
    animalList_.push_back(newHerbivore);
}

std::vector<const Animal*> Model::getAnimalsInTriangle(double, double) const {
    //TODO: ...
}