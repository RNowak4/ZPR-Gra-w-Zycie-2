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
		;
	//animal->doMove();
}

std::vector<const LocationData*> Model::getAnimalsLocationData() {
	std::vector<const LocationData*> vectorToReturn;
	for (auto animal : animalList_)
		vectorToReturn.push_back(animal->returnLocationData());

	return vectorToReturn;
}

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
		if (animal->isThatMe(x, y)) {
			return animal;
		}
		//return animal;
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

pairVectorPtr Model::getAnimalsData() const {
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

void Model::setModelParameters(unsigned adultWidth, unsigned adultHeigth,
		unsigned youngWidth, unsigned youngHeigth, unsigned mapWidth,
		unsigned mapHeight) {
	Constants::setParameters(adultWidth, adultHeigth, youngWidth, youngHeigth,
			mapWidth, mapHeight);
}

static const double PI = 3.1415;

double countDistance(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;

	return (sqrt(LenX * LenX + LenY * LenY));
}

unsigned countAngle(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;
	double przeciwProstokatna = countDistance(first, second);
	unsigned angle = asin(LenX / przeciwProstokatna) * 180.0 / PI;

	if (LenX >= 0 && LenY < 0)
		return angle;
	else if (LenX < 0 && LenY < 0)
		return angle + 90;
	else if (LenX < 0 && LenY >= 0)
		return angle + 180;
	else if (LenX >= 0 && LenY >= 0)
		return angle + 270;
}

std::vector<AnimalPtr> Model::getAnimalsInSight(Coordinates coordinates,
		unsigned sightLen, unsigned sightAngle, unsigned lookingAngle) const {
	std::vector<AnimalPtr> vectorToReturn;
	Coordinates tempCoords;
	unsigned angle;

	for (auto animal : animalList_) {
		tempCoords = animal->returnLocationData()->coordinates_;
		if (tempCoords == coordinates)
			continue;
		else if (countDistance(coordinates, tempCoords) <= sightLen) {
			angle = countAngle(coordinates, tempCoords);
			if ((sightAngle + lookingAngle / 2) <= angle
					&& (sightAngle - lookingAngle / 2) >= angle) {
				vectorToReturn.push_back(AnimalPtr(animal));
			}
		}
	}

	return vectorToReturn;
}
