/* 
 * File:   Model.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:29
 */

#include "Model.h"
#include "Carnivore.h"

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

void Model::updateAnimalsPosition() {
    for(auto animal : animalList_)
        animal->doMove();
}

void Model::createHerbivore(const Animal* father, const Animal* mother) {
    if(father == nullptr && mother == nullptr) {
        // Tutaj nie tworzymy dziecka, a juz doroslego osobnika
//        animalList_.push_back(new Herbivore());
    }
    else if(father == nullptr || mother == nullptr) {
        // Rzucic wyjatkiem
    }
    
    Animal* newHerbivore;
//  newHerbivore = new Herbivore(father, mother);
    animalList_.push_back(newHerbivore);
}

std::vector<const Animal::LocationData*> Model::getAnimalsLocationData() {
    std::vector<const Animal::LocationData*> vectorToReturn;
    for(auto animal : animalList_) 
        vectorToReturn.push_back(&animal->returnLocationData());
    
    return vectorToReturn;
}

/*
std::vector<const Animal*> Model::getAnimalsInTriangle(double, double) const {
    //TODO: ...
}
*/


// FUNKCJE DO TESTOW !!!
void Model::createCarnivore(unsigned x, unsigned y) {
    animalList_.push_back(new Carnivore(x,y));
}

void Model::createHerbivore(unsigned x, unsigned y) {   
    animalList_.push_back(new Herbivore(x,y));
}

/*****************************************/