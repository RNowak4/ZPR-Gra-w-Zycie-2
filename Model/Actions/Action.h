/*
 * Action.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <random>
#include <string>

class Model;

class Animal;

using namespace std;

class Action {
protected:
	Animal* animalPtr;
	Model* modelPtr;
	static Model* defaultModelPtr;
	static default_random_engine generator;

public:
	/**
	 *@function Action
	 *@brief Constructor of Action class - sets animalPtr and modelPtr values
	 *@argument animalPtr_ -	pointer to the Animal
	 */
	Action(Animal* animalPtr_);

	/**
	 *@function Action
	 *@brief Constructor of Action class - sets animalPtr and modelPtr values
	 *@argument animalPtr_ -	pointer to the Animal
	 *@argument modelPtr_ -	pointer to the model
	 */
	Action(Animal* animalPtr_, Model* modelPtr_) :
			animalPtr(animalPtr_), modelPtr(modelPtr_) {

	}

	/**
	 *@function ~Action
	 *@brief 	Destructor of Action class - cleans up it's existence in the model
	 */
	virtual ~Action();

	/**
	 *@function performAction
	 *@brief 	performs action of an animal - changes it's values that depends of current action
	 */
	virtual void performAction() = 0;

	/**
	 *@function szablon
	 *@brief 	szablon
	 *@argument szablon
	 *@return	szablon
	 */
	virtual Action* chooseNextAction() = 0;

	/**
	 *@function deleteAnimal
	 *@brief 	Function is used to avoid segmentation fault - if animal
	 *@brief 	which we for example are hunting - dies - this functions sets
	 *@brief 	animalPtr to the null value, avoiding error
	 *@argument animalPtr_ -	pointer to deleted animal
	 */
	virtual void deleteAnimal(const Animal* animalPtr_) = 0;

	/**
	 *@function setDefaultModel
	 *@brief 	Function sets the default model for Action class hierarchy
	 *@argument modelPtr -	pointer to a default model
	 */
	static void setDefaultModel(Model* modelPtr) {
		defaultModelPtr = modelPtr;
	}

	/**
	 *@function toString
	 *@brief 	Function returns name of the action
	 *@return string
	 */
	virtual string toString() = 0;
};

#endif /* ACTION_H_ */
