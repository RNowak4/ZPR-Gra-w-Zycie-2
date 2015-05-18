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
	for (auto animalPtr : animalList_)
		delete animalPtr;
}

//Model(const Model& orig) {
//}

Coordinates Model::getCoordinates(const Animal* animalToGet) const {
	for (auto animalPtr : animalList_) {
		if (animalPtr == animalToGet)
			return animalPtr->returnCoodtinates();

		// Albo niech rzuca wyjatek.
		return Coordinates(0, 0);
	}
}

void Model::updateAnimalsStatuses() {
	for (auto animalPtr : animalList_) {
		animalPtr->updateStatus();
	}
}

void Model::updateAnimalsPosition() {
	for (auto animal : animalList_)
		animal->doMove();
}

void Model::createHerbivore(const Animal* father, const Animal* mother) {
	if (father == nullptr && mother == nullptr) {
		// Tutaj nie tworzymy dziecka, a juz doroslego osobnika
//        animalList_.push_back(new Herbivore());
	} else if (father == nullptr || mother == nullptr) {
		// Rzucic wyjatkiem
	}

	Animal* newHerbivore;
//  newHerbivore = new Herbivore(father, mother);
	animalList_.push_back(newHerbivore);
}

std::vector<const LocationData*> Model::getAnimalsLocationData() {
	std::vector<const LocationData*> vectorToReturn;
	for (auto animal : animalList_)
		vectorToReturn.push_back(animal->returnLocationData());

	return vectorToReturn;
}

// FUNKCJE DO TESTOW !!!
void Model::createCarnivore(unsigned x, unsigned y) {
	animalList_.push_back(new Carnivore(x, y));
}

void Model::createHerbivore(unsigned x, unsigned y) {
	animalList_.push_back(new Herbivore(x, y));
}

bool Model::registerAnimal(unsigned x, unsigned y) {
	Animal* animalPtr = findAnimal(x, y);
	if (animalPtr == nullptr)
		return false;

	registeredAnimalList_.push_back(animalPtr);
	return true;
}

bool Model::registerAnimal(Animal* animalPtr) {
	registeredAnimalList_.push_back(animalPtr);

	return false;
}

bool Model::deregisterAnimal(unsigned x, unsigned y) {
	Animal* animalPtr = findAnimal(x, y);
	if (animalPtr == nullptr)
		return false;

	return deregisterAnimal(animalPtr);
}

bool Model::deregisterAnimal(Animal* animalToErase) {
	for (auto it = registeredAnimalList_.begin();
			it != registeredAnimalList_.end(); ++it) {
		if (*it == animalToErase) {
			registeredAnimalList_.erase(it);
			return true;
		}
	}

	return false;
}

Animal* Model::findAnimal(unsigned x, unsigned y) {
	for (auto animal : animalList_) {
		/*if (animal->isThatMe(x, y)) {
		 animalPtr = animal;
		 break;
		 }*/
		return animal;
	}
	return nullptr;
}

bool Model::isRegistered(Animal* animalPtr) const {
	for (auto it = registeredAnimalList_.begin();
			it != registeredAnimalList_.end(); ++it) {
		if (*it == animalPtr) {
			return true;
		}
	}

	return false;
}
/*
std::vector<pair<const LocationData*, const AnimalData*> >& Model::getAnimalsData() const {
	std::vector<pair<const LocationData*, const AnimalData*> >* vectorToReturn =
			new std::vector<pair<const LocationData*, const AnimalData*> >();

	for (auto animal : animalList_) {
		if (isRegistered(animal))
			vectorToReturn->push_back(
					pair<const LocationData*, const AnimalData*>(
							animal->returnLocationData(),
							animal->getAnimalData()));
		else
			vectorToReturn->push_back(
					pair<const LocationData*, const AnimalData*>(
							animal->returnLocationData(), nullptr));
	}

	return *vectorToReturn;
}*/

shared_ptr<std::vector<pair<const LocationData*, const AnimalData*> > > Model::getAnimalsData() const {
	shared_ptr<std::vector<pair<const LocationData*, const AnimalData*> > > vectorToReturn(
			new std::vector<pair<const LocationData*, const AnimalData*> >());

	for (auto animal : animalList_) {
		if (isRegistered(animal))
			vectorToReturn->push_back(
					pair<const LocationData*, const AnimalData*>(
							animal->returnLocationData(),
							animal->getAnimalData()));
		else
			vectorToReturn->push_back(
					pair<const LocationData*, const AnimalData*>(
							animal->returnLocationData(), nullptr));
	}

	return vectorToReturn;
}

bool Model::switchAnimalRegister(unsigned x, unsigned y) {
	Animal* animalPtr = findAnimal(x, y);
	if (animalPtr == nullptr)
		return false;

	if (isRegistered(animalPtr))
		deregisterAnimal(animalPtr);
	else
		registerAnimal(animalPtr);

	return true;
}

/*****************************************/
