/**
 * @file Model.cpp
 * @brief Implementation of the Model
 *
 * @author Radoslaw Nowak
 */

#include "Model.h"

#include <cmath>
#include <iostream>

#include "Actions/RandomWalking.h"
#include "Actions/TestAction.h"
#include "Carnivore.h"
#include "Constants.h"
#include "Herbivore.h"

Model::Model() {
	Action::setDefaultModel(this);
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
	}

	return Coordinates(0, 0);
}

void Model::updateAnimalsStatuses() {
	for (auto animalPtr : animalList_) {
		/*animalPtr->doMove();
		 animalPtr->updateStatus();*/
	}
}

//TODO wiekszosc przerzucic do update status
void Model::updateAnimalsPosition() {
	list<Animal*> animalToDieList;

	for (auto animal : animalList_) {
		animal->doMove();
		animal->updateStatus();
		if (animal->shouldDie() != nullptr)
			animalToDieList.push_back(animal);
	}

	for (auto animal : animalToDieList) {
		killAnimal(animal);
	}
}

std::vector<const LocationData*> Model::getAnimalsLocationData() {
	std::vector<const LocationData*> vectorToReturn;
	for (auto animal : animalList_)
		vectorToReturn.push_back(animal->returnLocationData());

	return vectorToReturn;
}

void Model::createCarnivore(unsigned x, unsigned y) {
	Animal* carnivorePtr = new Carnivore(x, y);
	animalList_.push_back(carnivorePtr);
	carnivorePtr->setAction(
			shared_ptr < Action > (new RandomWalking(carnivorePtr)));
}

void Model::createHerbivore(unsigned x, unsigned y) {
	Animal* herbivorePtr = new Herbivore(x, y);
	animalList_.push_back(herbivorePtr);
	herbivorePtr->setAction(
			shared_ptr < Action > (new TestAction(herbivorePtr)));
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

double Model::countDistance(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;

	return (sqrt(LenX * LenX + LenY * LenY));
}

unsigned Model::countAngle(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;
	double przeciwProstokatna = countDistance(first, second);
	unsigned angle = asin(abs(LenX) / przeciwProstokatna) * 180.0 / M_PI;

	if (LenX >= 0 && LenY < 0) {
		angle += 90;
	} else if (LenX < 0 && LenY < 0) {
		angle += 0;
	} else if (LenX < 0 && LenY >= 0) {
		angle += 270;
	} else {
		angle += 180;

	}

	return angle;
}

// TODO nazwy argumentow mi sie jebnely cos
// Ale dziala, to nie ruszam...
std::vector<Animal*> Model::getAnimalsInSight(Coordinates coordinates,
		unsigned sightLen, unsigned lookingAngle, unsigned lookingRad) {
	std::vector<Animal*> vectorToReturn;
	Coordinates tempCoords;
	unsigned angle;

	for (auto animal : animalList_) {
		tempCoords = animal->returnLocationData()->coordinates_;
		if (tempCoords == coordinates)
			continue;
		else if (countDistance(coordinates, tempCoords) <= sightLen) {
			angle = countAngle(coordinates, tempCoords);
			if ((lookingAngle + lookingRad / 2) >= angle
					&& (lookingAngle - lookingRad / 2) <= angle) {
				vectorToReturn.push_back(animal);
			}
		}
	}

	return vectorToReturn;
}

void Model::killAnimal(Animal* animalPtr) {
	Animal* tmpPtr;

	for (auto action : actionsList_) {
		action->deleteAnimal(animalPtr);
	}

	for (auto it = animalList_.begin(); it != animalList_.end(); ++it) {
		if (*it == animalPtr) {
			tmpPtr = *it;
			animalList_.erase(it);
			delete tmpPtr;
			break;
		}
	}
}

void Model::addAction(Action* actionPtr) {
	actionsList_.push_back(actionPtr);
}

void Model::deleteAction(Action* actionPtr) {
	for (auto it = actionsList_.begin(); it != actionsList_.end(); ++it) {
		if (*it == actionPtr) {
			actionsList_.erase(it);
			break;
		}
	}
}
