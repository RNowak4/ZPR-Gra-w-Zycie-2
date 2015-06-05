/**
 * @file Animal.h
 * @brief Class that represents an Animal
 *
 * @author Radoslaw Nowak
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <ctime>
#include <list>
#include <memory>
#include <string>

#include "Actions/Action.h"
#include "AnimalData.h"
#include "AnimalViewParameters.h"
#include "Attributes.h"
#include "States/State.h"
#include "ViewStructs.h"

class Action;
class TestAction;

typedef shared_ptr<Action> ActionPtr;
typedef shared_ptr<AnimalData> AnimalDataPtr;
typedef shared_ptr<State> StatePtr;

class Animal {
private:
	Coordinates coordinates_;
	Sex sex_;
	double velocity;
	double acceleration;
	double angleVelocity;
	int childrenNumber;
	bool dead;

protected:
	list<StatePtr> statesList;
	ActionPtr currentAction;
	LocationData locationData_;
	Attributes actualAttributes_;
	time_t bornDate;
	time_t timeSinceCopulation;
	time_t lastRandomize;
	double eatNeed_;
	double sleepNeed_;

public:
	list<Animal*> childrenList;

	/**
	 *@function Animal
	 *@brief 	Copy Constructor.
	 */
	Animal(const Animal& orig);

	/**
	 *@function Animal
	 *@brief 	Creates an new Animal with random Modifiers.
	 */
	Animal(unsigned, unsigned, AnimalType = HERBIVORE);

	/**
	 *@function Animal
	 *@brief 	Creates an new Animal.
	 */
	Animal(unsigned, unsigned, Attributes, AnimalType = HERBIVORE);

	/**
	 *@function ~Animal
	 *@brief 	destructor.
	 */
	virtual ~Animal() {
	}

	/**
	 *@function updateStatus
	 *@brief 	Updates status of an animal.
	 */
	virtual void updateStatus() = 0;

	/**
	 *@function returnCoodtinates
	 *@brief 	gets coordinates of an animal.
	 *@return 	animal's coordinates
	 */
	Coordinates returnCoodtinates() const {
		return locationData_.coordinates_;
	}

	/**
	 *@function returnLocationData
	 *@brief	gets current location data of an animal.
	 *@return	current location data of an animal
	 */
	LocationData* returnLocationData() {
		return &locationData_;
	}

	/**
	 *@function isDangerous
	 *@brief	checks if animal is Dangerous for another
	 *@param another 		- another animal
	 *@return	bool falue
	 */
	virtual bool isDangerous(Animal* another) = 0;

	/**
	 *@function isThatMe
	 *@brief	checks if an animal is at position.
	 *@param x 		- position in x axis
	 *@param y		- position in y axis
	 *@return	bool falue
	 */
	bool isThatMe(unsigned x, unsigned y);

	/**
	 *@function isThatMe
	 *@brief	checks if an animal is at state.
	 *@param stateName	- name of an state
	 *@return	bool falue
	 */
	bool hasState(const string& stateName);

	/**
	 *@function setPosition
	 *@brief 	moves an animal to indicated position.
	 *@param x 		- position in x axis
	 *@param y		- position in y axis
	 */
	void setPosition(unsigned x, unsigned y);

	/**
	 *@function setPosition
	 *@brief 	moves an animal to indicated position.
	 *@param coodrinates	- coordinates of new position
	 */
	void setPosition(Coordinates coodrinates);

	/**
	 *@function getSex
	 *@brief 	gets animal sex.
	 *@return	Sex falue
	 */
	Sex getSex() {
		return sex_;
	}

	/**
	 *@function getAnimalData
	 *@brief 	Gets Data of an animal.
	 *@return	Pointer to AnimalData class
	 */
	AnimalData* getAnimalData();

	void setAction(ActionPtr actionPtr) {
		currentAction = actionPtr;
	}

	/**
	 *@function doMove
	 *@brief 	Moves an animal
	 */
	void doMove();

	/**
	 *@function turnRight
	 *@brief 	Turns an animal right
	 */
	void turnRight() {
		angleVelocity = 1.0;
	}

	/**
	 *@function turnLeft
	 *@brief 	Turns an animal left
	 */
	void turnLeft() {
		angleVelocity = -1.0;
	}

	/**
	 *@function stopTurning
	 *@brief 	Stops animal's turning
	 */
	void stopTurning() {
		angleVelocity = 0.0;
	}

	/**
	 *@function isHerbivore
	 *@brief 	Function returns true, if an animal is herbivore
	 *@return	bool value
	 */
	bool isHerbivore() {
		return locationData_.animalType_ == HERBIVORE
				|| locationData_.animalType_ == HERBIVORE_CHILD;
	}

	/**
	 *@function setLookingAngle
	 *@brief 	Sets looking angle of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setLookingAngle(unsigned value_to_set) {
		locationData_.lookingAngle = value_to_set;
	}

	/**
	 *@function setVelocity
	 *@brief 	Sets velocity of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setVelocity(double value_to_set) {
		velocity = value_to_set;
	}

	/**
	 *@function setAcceleration
	 *@brief 	Sets acceleration of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setAcceleration(double value_to_set) {
		acceleration = value_to_set;
	}

	/**
	 *@function shouldDie
	 *@brief 	Returns this if animal should die or nullptr.
	 *@return	Pointer to animal class
	 */
	Animal* shouldDie();

	/**
	 *@function isMother
	 *@brief 	Returns true if an animal is mother
	 *@return	boolean value
	 */
	bool isMother() {
		return this->hasState("Mother");
	}

	/**
	 *@function getAttributes
	 *@brief 	returns actual attributes of an animal
	 *@return	reference to the structure
	 */
	Attributes& getAttributes() {
		return actualAttributes_;
	}

	/**
	 *@function returnEatNeed
	 *@brief 	returns actual animal's eat need
	 *@return	reference to double value
	 */
	double& returnEatNeed() {
		return eatNeed_;
	}

	/**
	 *@function returnSleepNeed
	 *@brief 	returns actual animal's sleep need
	 *@return	reference to double value
	 */
	double& returnSleepNeed() {
		return sleepNeed_;
	}

	void addState(StatePtr new_state);

	void looseState(const string& state_name);

	time_t& returnTimeSiceCopulatio() {
		return timeSinceCopulation;
	}

	bool canHaveChild() {
		if (childrenNumber < actualAttributes_.fertility_
				&& (time(0) - timeSinceCopulation) > 30
				&& !hasState("Childhood"))
			return true;
		return false;
	}

	void markToKill() {
		dead = true;
	}

	int& getChildrenNumber() {
		return childrenNumber;
	}

	void deleteChild(Animal* animal_ptr);
};

#endif	/* ANIMAL_H */
