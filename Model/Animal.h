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
#include "Attributes.h"
#include "States/State.h"
#include "ViewStructs.h"

class Action;
class TestAction;

typedef shared_ptr<Action> ActionPtr;
typedef shared_ptr<AnimalData> AnimalDataPtr;
typedef shared_ptr<State> StatePtr;

/**
@class Animal
Class that represents each animal in the model. 
It is virtual class.
*/
class Animal {
private:
	Sex sex; /** animal's sex */
	double velocity; /** animal's velocity */
	double acceleration; /** animal's acceleration */
	double angleVelocity; /** animal's angle velocity */
	int childrenNumber; /** animal's childrens number */
	bool dead;

protected:
	list<StatePtr> statesList; /** animal's states */
	ActionPtr currentAction; /** animal's current action */
	LocationData locationData; /** animal's current location data */
	Attributes actualAttributes; /** animal's actual attributes */
	time_t bornDate; /** animal's born date */
	time_t timeSinceCopulation; /** animal's time since copulation */
	time_t lastRandomize;
	double eatNeed; /** animal's eat need */
	double sleepNeed; /** animal's sleep need */

public:
	list<Animal*> childrenList; /** animal's children list */

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
	virtual ~Animal();

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
		return locationData.coordinates_;
	}

	/**
	 *@function returnLocationData
	 *@brief	gets current location data of an animal.
	 *@return	current location data of an animal
	 */
	LocationData* returnLocationData() {
		return &locationData;
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
		return sex;
	}

	/**
	 *@function getAnimalData
	 *@brief 	Gets Data of an animal.
	 *@return	Pointer to AnimalData class
	 */
	AnimalData* getAnimalData();

	/**
	*@function setAction
	*@brief 	Sets action to current animal.
	*@argument action_ptr - shared pointer to new action.
	*/
	void setAction(ActionPtr action_ptr) {
		currentAction = action_ptr;
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
		return locationData.animalType_ == HERBIVORE
				|| locationData.animalType_ == HERBIVORE_CHILD;
	}

	/**
	 *@function setLookingAngle
	 *@brief 	Sets looking angle of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setLookingAngle(unsigned value_to_set) {
		locationData.lookingAngle = value_to_set;
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
		return actualAttributes;
	}

	/**
	 *@function returnEatNeed
	 *@brief 	returns actual animal's eat need
	 *@return	reference to double value
	 */
	double& returnEatNeed() {
		return eatNeed;
	}

	/**
	 *@function returnSleepNeed
	 *@brief 	returns actual animal's sleep need
	 *@return	reference to double value
	 */
	double& returnSleepNeed() {
		return sleepNeed;
	}

	/**
	 *@function addState
	 *@brief 	adds a state to the animal
	 *@argument new_state - state to add
	 */
	void addState(StatePtr new_state);

	/**
	 *@function looseState
	 *@brief 	deletes state from the animal
	 *@argument state_name - state to be lost
	 */
	void looseState(const string& state_name);

	/**
	 *@function returnTimeSiceCopulation
	 *@brief 	returns a time since last copulation
	 *@return	time_t reference
	 */
	time_t& returnTimeSiceCopulation() {
		return timeSinceCopulation;
	}

	/**
	 *@function canHaveChild
	 *@brief 	returns a bool value due to ability of an animal to have a child
	 *@return	bool value
	 */
	bool canHaveChild() {
		if (childrenNumber < actualAttributes.fertility_
				&& (time(0) - timeSinceCopulation) > 30
				&& !hasState("Childhood"))
			return true;
		return false;
	}

	/**
	 *@function markToKill
	 *@brief 	marks an animal to be killed in a model
	 */
	void markToKill() {
		dead = true;
	}

	/**
	 *@function getChildrenNumber
	 *@brief 	gets a children number
	 *@return	int reference
	 */
	int& getChildrenNumber() {
		return childrenNumber;
	}

	/**
	 *@function deleteChild
	 *@brief 	deletes a child from child list
	 *@argument animal_ptr - pointer to an child
	 */
	void deleteChild(Animal* animal_ptr);

	/**
	*@function getState
	*@brief 	gets pointer to state.
	*@argument state_name - name of the state that we want to receive.
	*@return Pointer to the state or nullptr if not found.
	*/
	State* getState(string state_name);
};

#endif	/* ANIMAL_H */
