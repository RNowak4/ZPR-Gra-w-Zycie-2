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
		vectorToReturn.push_back(&animal->returnLocationData());

	return vectorToReturn;
}

// FUNKCJE DO TESTOW !!!
void Model::createCarnivore(unsigned x, unsigned y) {
	animalList_.push_back(new Carnivore(x, y));
}

void Model::createHerbivore(unsigned x, unsigned y) {
	animalList_.push_back(new Herbivore(x, y));
}

shared_ptr<AnimalData> Model::getAnimalData(int x, int y) {
	Animal *animalPtr = nullptr;

	// TODO nie ustalilismy jeszcze tego jakie rozmiary maja zwierzaki
	//		wiec zwracany bedzie pierwszy, lepszy zwierzak do testu wyswietlania
	for (auto animal : animalList_) {
		/*if (animal->isThatMe(x, y)) {
			animalPtr = animal;
			break;
		}*/
		animalPtr = animal; //chuj
	}

	// Nie znaleziono
	if (animalPtr == nullptr)
		return nullptr;

	return animalPtr->getAnimalData();
}

/*****************************************/
