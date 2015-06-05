/**
 * @file Model.cpp
 * @brief Implementation of the Model
 *
 * @author Radoslaw Nowak
 */

#include "Model.h"

#include <cmath>
#include <cstdlib>

#include "Actions/CarnivoreRandomWalking.h"
#include "Actions/FollowMother.h"
#include "Actions/HerbivoreRandomWalking.h"
#include "Attributes.h"
#include "Carnivore.h"
#include "Herbivore.h"

// Testowy commit z nowego kompa

Model::Model() {
	Action::setDefaultModel(this);
	srand(time(0));
}

Model::~Model() {
	for (auto animalPtr : animalList)
		delete animalPtr;
}

//Model(const Model& orig) {
//}

Coordinates Model::getCoordinates(const Animal* animalToGet) const {
	for (auto animalPtr : animalList) {
		if (animalPtr == animalToGet)
			return animalPtr->returnCoodtinates();
	}

	return Coordinates(0, 0);
}

void Model::updateAnimalsStatuses() {
	for (auto animalPtr : animalList) {
		/*animalPtr->doMove();
		 animalPtr->updateStatus();*/
	}
}

//TODO wiekszosc przerzucic do update status
void Model::updateAnimalsPosition() {
	list<Animal*> animalToDieList;

	for (auto animal : animalList) {
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
	for (auto animal : animalList)
		vectorToReturn.push_back(animal->returnLocationData());

	return vectorToReturn;
}

void Model::createCarnivore(unsigned x, unsigned y) {
	Animal* carnivore_ptr = new Carnivore(x, y);
	animalList.push_back(carnivore_ptr);
	carnivore_ptr->setAction(
			shared_ptr < Action > (new CarnivoreRandomWalking(carnivore_ptr)));
}

void Model::createHerbivore(unsigned x, unsigned y) {
	Animal* herbivore_ptr = new Herbivore(x, y);
	animalList.push_back(herbivore_ptr);
	herbivore_ptr->setAction(
			shared_ptr < Action > (new HerbivoreRandomWalking(herbivore_ptr)));
}

Animal* Model::createCarnivoreChild(unsigned x, unsigned y,
		const Attributes& attributes, Animal* motherPtr) {
	Animal* carnivore_ptr = new Carnivore(x, y, attributes);
	carnivore_ptr ->setAction(
			shared_ptr < Action > (new FollowMother(carnivore_ptr , motherPtr)));
	animalList.push_back(carnivore_ptr);
	return carnivore_ptr;
}

Animal* Model::createHerbivoreChild(unsigned x, unsigned y,
		const Attributes& attributes, Animal* motherPtr) {
	Animal* herbivore_ptr = new Herbivore(x, y, attributes);
	herbivore_ptr->setAction(
			shared_ptr < Action > (new FollowMother(herbivore_ptr, motherPtr)));
	animalList.push_back(herbivore_ptr);

	return herbivore_ptr;
}

bool Model::registerAnimal(unsigned x, unsigned y) {
	Animal* animalPtr = findAnimal(x, y);
	if (animalPtr == nullptr)
		return false;

	registeredanimalList.push_back(animalPtr);
	return true;
}

bool Model::registerAnimal(Animal* animalPtr) {
	registeredanimalList.push_back(animalPtr);

	return false;
}

bool Model::deregisterAnimal(unsigned x, unsigned y) {
	Animal* animalPtr = findAnimal(x, y);
	if (animalPtr == nullptr)
		return false;

	return deregisterAnimal(animalPtr);
}

bool Model::deregisterAnimal(Animal* animalToErase) {
	for (auto it = registeredanimalList.begin();
			it != registeredanimalList.end(); ++it) {
		if (*it == animalToErase) {
			registeredanimalList.erase(it);
			return true;
		}
	}

	return false;
}

Animal* Model::findAnimal(unsigned x, unsigned y) {
	for (auto animal : animalList) {
		if (animal->isThatMe(x, y)) {
			return animal;
		}
	}
	return nullptr;
}

bool Model::isRegistered(Animal* animalPtr) const {
	for (auto it = registeredanimalList.begin();
			it != registeredanimalList.end(); ++it) {
		if (*it == animalPtr) {
			return true;
		}
	}

	return false;
}

pairVectorPtr Model::getAnimalsData() const {
	shared_ptr<std::vector<pair<const LocationData*, const AnimalData*> > > vectorToReturn(
			new std::vector<pair<const LocationData*, const AnimalData*> >());

	for (auto animal : animalList) {
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

void Model::setModelParameters(unsigned simulationSpeed, unsigned adultWidth,
		unsigned adultHeigth, unsigned youngWidth, unsigned youngHeigth,
		unsigned mapWidth, unsigned mapHeight) {
	Parameters::setParameters(simulationSpeed, adultWidth, adultHeigth,
			youngWidth, youngHeigth, mapWidth, mapHeight);
}

double Model::countDistance(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;

	return (sqrt(LenX * LenX + LenY * LenY));
}

unsigned Model::countAngle(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;
	double distance = Model::countDistance(first, second);
	unsigned angle;

	if (LenX >= 0 && LenY < 0)
		angle = asin(abs(LenX) / distance) * 180.0 / M_PI + 90;
	else if (LenX < 0 && LenY < 0)
		angle = acos(abs(LenX) / distance) * 180.0 / M_PI;
	else if (LenX < 0 && LenY >= 0)
		angle = asin(abs(LenX) / distance) * 180.0 / M_PI + 270;
	else
		angle = acos(abs(LenX) / distance) * 180.0 / M_PI + 180;

	return angle;
}

std::vector<Animal*> Model::getAnimalsInSight(Coordinates coordinates,
		unsigned sightLen, unsigned lookingAngle, unsigned lookingRad) {
	std::vector<Animal*> vectorToReturn;
	Coordinates tempCoords;
	unsigned angle;

	for (auto animal : animalList) {
		tempCoords = animal->returnLocationData()->coordinates_;
		if (tempCoords == coordinates)
			continue;
		else if (countDistance(coordinates, tempCoords) <= sightLen) {
			angle = countAngle(coordinates, tempCoords);
			if ((lookingAngle + lookingRad / 2) >= angle
					&& (lookingAngle - lookingRad / 2 + 360) <= angle + 360) {
				vectorToReturn.push_back(animal);
			}
		}
	}

	return vectorToReturn;
}

std::vector<Animal*> Model::getNearlyAnimals(Coordinates coordinates,
		const unsigned range) {
	std::vector<Animal*> vectorToReturn;
	Coordinates tempCoords;

	for (auto animal : animalList) {
		tempCoords = animal->returnLocationData()->coordinates_;
		if (tempCoords == coordinates)
			continue;
		else if (countDistance(coordinates, tempCoords) <= range) {
			vectorToReturn.push_back(animal);
		}
	}

	return vectorToReturn;
}

void Model::killAnimal(Animal* animalPtr) {
	Animal* temp_ptr;

	for (auto action : actionsList) {
		action->deleteAnimal(animalPtr);
	}

	for (auto it = animalList.begin(); it != animalList.end(); ++it) {
		for(auto it2 = (*it)->childrenList.begin(); it2 != (*it)->childrenList.end(); ++it2) {
			(*it2)->deleteChild(animalPtr);
		}

		if (*it == animalPtr) {
			temp_ptr = *it;
			animalList.erase(it);
			delete temp_ptr;
			break;
		}
	}
}

void Model::addAction(Action* action_ptr) {
	actionsList.push_back(action_ptr);
}

void Model::deleteAction(Action* action_ptr) {
	for (auto it = actionsList.begin(); it != actionsList.end(); ++it) {
		if (*it == action_ptr) {
			actionsList.erase(it);
			break;
		}
	}
}
