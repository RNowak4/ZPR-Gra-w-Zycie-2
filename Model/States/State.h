/**
* @file State.h
* @brief Virtual class that represents States which can have an animal.
*
* @author Radoslaw Nowak
*/

#ifndef STATE_H_
#define STATE_H_

#include <string>

class Animal;

using namespace std;

/**
@class State
Virtual class that represents State of an animals.
*/
class State {
protected:
	Animal* animalPtr;

public:
	/**
	*@function State
	*@brief 	Default State class constructor
	*/
	State();

	/**
	*@function State
	*@brief 	Default State class constructor
	*@argument animal_ptr -		pointer to animals, which has that state.
	*/
	State(Animal* animal_ptr);

	/**
	*@function ~State
	*@brief 	Destructor is used to undone changes in animal's attributes.
	*/
	virtual ~State() { }

	/**
	*@function toString
	*@brief 	Function returns name of current state as string variable.
	*@return	string name of state.
	*/
	virtual string toString() = 0;

	/**
	*@function isThatMe
	*@brief 	Function boolean value due to being state which we ask for.
	*@argument state_name -	name of state.
	*@return	boolean value
	*/
	virtual bool isThatMe(string state_name) = 0;

	virtual void deleteAnimal(Animal* animal_ptr) = 0;
};

#endif /* STATE_H_ */
