/**
* @file Action.h
* @brief Virtual class that is used to represent 
* @brief an action which permorm an animal.
*
* @author Radoslaw Nowak
*/

#ifndef ACTION_H_
#define ACTION_H_

#include <ctime>
#include <random>
#include <string>

class Model;

class Animal;

using namespace std;

/**
@class Action
Virtual class that represents action which can be performed by an animal.
*/
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
	 *@argument animal_ptr -	pointer to the Animal
	 */
	Action(Animal* animal_ptr);

	/**
	 *@function Action
	 *@brief Constructor of Action class - sets animalPtr and modelPtr values
	 *@argument animal_ptr -	pointer to the Animal
	 *@argument modelPtr_ -	pointer to the model
	 */
	Action(Animal* animal_ptr, Model* model_ptr) :
			animalPtr(animal_ptr), modelPtr(model_ptr) {

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
	 *@function chooseNextAction
	 *@brief 	Function is used to choose next action for an animal
	 *@brief	depending on current situation.
	 *@return	Action pointer to the next action.
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
