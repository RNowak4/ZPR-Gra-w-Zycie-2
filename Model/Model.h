/**
 * @file Model.h
 * @brief Class that represents Model.
 *
 * @author Radoslaw Nowak
 */

#ifndef MODEL_H
#define	MODEL_H

#include <list>
#include <utility>
#include <vector>

#include "Animal.h"
#include "AnimalData.h"
#include "ViewStructs.h"

typedef shared_ptr<Animal> AnimalPtr;
typedef shared_ptr<std::vector<pair<const LocationData*, const AnimalData*> > > pairVectorPtr;

class Model {
public:
	Model();
	Model(const Model& orig);
	~Model();
	void createCarnivore(unsigned, unsigned);
	void createHerbivore(unsigned, unsigned);
	void createCarnivore(unsigned, unsigned, const Modifiers&);
	void createHerbivore(unsigned, unsigned, const Modifiers&);
	void updateAnimalsStatuses();
	void updateAnimalsPosition();
	std::vector<Animal*> getAnimalsInSight(Coordinates, unsigned, unsigned,
			unsigned);
	Coordinates getCoordinates(const Animal*) const;
	std::vector<const LocationData*> getAnimalsLocationData();
	pairVectorPtr getAnimalsData() const;
	bool switchAnimalRegister(unsigned, unsigned);
	void setModelParameters(unsigned, unsigned, unsigned, unsigned, unsigned,
			unsigned);
	static unsigned countAngle(Coordinates, Coordinates);
	static double countDistance(Coordinates, Coordinates);
	void killAnimal(Animal* animalPtr);
	void addAction(Action*);
	void deleteAction(Action*);

private:
	std::list<Animal*> animalList_;
	std::list<Animal*> registeredAnimalList_;
	std::list<Action*> actionsList_;
	Animal* findAnimal(unsigned, unsigned);
	bool deregisterAnimal(Animal*);
	bool isRegistered(Animal*) const;
	bool registerAnimal(unsigned, unsigned);
	bool registerAnimal(Animal*);
	bool deregisterAnimal(unsigned, unsigned);
};

#endif	/* MODEL_H */
