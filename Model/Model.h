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

#include "Actions/Action.h"
#include "Animal.h"
#include "AnimalData.h"
#include "Parameters.h"
#include "ViewStructs.h"

typedef shared_ptr<Animal> AnimalPtr;
typedef shared_ptr<std::vector<pair<const LocationData*, const AnimalData*> > > pairVectorPtr;

/**
@class Model
Class that is responsible for providing interface for the controller.
*/
class Model {
public:
	/**
	 *@function Model
	 *@brief 	Default constructor of Model class.
	 */
	Model();
	//Model(const Model& orig);

	/**
	 *@function ~Model
	 *@brief 	Destructor of Model class. Protects agains memory loss.
	 */
	~Model();

	/**
	 *@function createCarnivore
	 *@brief 	creates a single carnivore
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 */
	void createCarnivore(unsigned x, unsigned y);

	/**
	 *@function createHerbivore
	 *@brief 	creates a single herbivore
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 */
	void createHerbivore(unsigned x, unsigned y);

	/**
	*@function createCarnivoreChild
	*@brief 	creates a single carnivore child
	*@argument x -	position on x axis
	*@argument y -	position on y axis
	*@argument attributes - child's attributes
	*@argument mother_ptr - pointer to the mother
	*@return pointer to recently created animal child
	*/
	Animal* createCarnivoreChild(unsigned x, unsigned y,
			const Attributes& attributes, Animal* mother_ptr);

	/**
	*@function createHerbivoreChild
	*@brief 	creates a single herbivore child
	*@argument x -	position on x axis
	*@argument y -	position on y axis
	*@argument attributes - child's attributes
	*@argument mother_ptr - pointer to the mother
	*@return pointer to recently created animal child
	*/
	Animal* createHerbivoreChild(unsigned x, unsigned y,
			const Attributes& attributes, Animal* mother_ptr);

	/**
	 *@function updateAnimalsStatuses
	 *@brief 	updates status of every animal in model
	 */
	void updateAnimalsStatuses();

	/**
	 *@function getAnimalsInSight
	 *@brief 	Returns collection of animals in specified sight range.
	 *@argument coordinates -  position of the animal.
	 *@argument sightLen -	   sight length of the animal.
	 *@argument lookingAngle - animal's looking angle
	 *@argument lookingRad -   animal's looking radius
	 *@return	vector of pointer to animals being in sight of animal specified by coordinates
	 */
	std::vector<Animal*> getAnimalsInSight(Coordinates coordinates,
			unsigned sightLen, unsigned lookingAngle, unsigned lookingRad);

	/**
	 *@function getNearlyAnimals
	 *@brief 	Returns collection of animals in specified range.
	 *@argument coordinates -  position of the animal.
	 *@argument range -	   sight length of the animal.
	 *@return	vector of pointer to animals being in range of animal specified by coordinates
	 */
	std::vector<Animal*> getNearlyAnimals(Coordinates coordinates,
			const unsigned range);

	/**
	 *@function getCoordinates
	 *@brief 	Function simply returns coordinates of specified animal
	 *@argument animalPtr -	Pointer to Animal which coordinates we want to get
	 *@return	Coordinates structure
	 */
	Coordinates getCoordinates(const Animal* animalPtr) const;

	/**
	 *@function getAnimalsLocationData
	 *@brief 	Function returns all animals location data.
	 *@return	Vector of LocationData pointers
	 */
	std::vector<const LocationData*> getAnimalsLocationData();

	/**
	 *@function getAnimalsData
	 *@brief 	Function returns animals data.
	 *@return	Pointer to the Vector of specified pairs.
	 */
	pairVectorPtr getAnimalsData() const;

	/**
	 *@function switchAnimalRegister
	 *@brief 	Function swtiches current Animal being in registered animals collection
	 *@argument x -	position on x axis
	 *@argument y - position on y axis
	 *@return	bool value
	 */
	bool switchAnimalRegister(unsigned x, unsigned y);

	/**
	 *@function setModelParameters
	 *@brief 	Function is used to set model's parameters
	 *@argument adultWidth - 	width of adult animal
	 *@argument adultHeigth - 	height of adult animal
	 *@argument youngWidth -	width of young animal
	 *@argument youngHeigth -	height of young animal
	 *@argument mapWidth -		model's map width
	 *@argument mapHeight -		model's map height
	 */
	void setModelParameters(unsigned simulationSpeed, unsigned adultWidth,
			unsigned adultHeigth, unsigned youngWidth, unsigned youngHeigth,
			unsigned mapWidth, unsigned mapHeight);

	/**
	 *@function countAngle
	 *@brief 	Function is used to count an angle between first and second coordinates
	 *@argument first -		coordinates of selected position
	 *@argument second -	coordinates of relative position
	 *@return	unsigned integer value
	 */
	static unsigned countAngle(Coordinates first, Coordinates second);

	/**
	 *@function countDistance
	 *@brief 	Funtion is used to count a distance between first and second coordinates
	 *@argument first -		coordinates of selected position
	 *@argument second -	coordinates of relative position
	 *@return	unsigned integer value
	 */
	static double countDistance(Coordinates first, Coordinates second);

	/**
	 *@function killAnimal
	 *@brief 	Deletes an animal from model
	 *@argument animalPtr -	Pointer to animal which we want to kill
	 */
	void killAnimal(Animal* animalPtr);

	/**
	 *@function addAction
	 *@brief 	Function is used to add an action to a model.
	 *@argument actionPtr - pointer to an action which we want to add.
	 */
	void addAction(Action* actionPtr);

	/**
	 *@function deleteAction
	 *@brief 	Function is used to delete an action from a model.
	 *@argument actionPtr - pointer to an action which we want to delete.
	 */
	void deleteAction(Action* actionPtr);

	/**
	 *@function slowerSimulation
	 *@brief 	function is used to slow the simulation
	 */
	void slowerSimulation() {
		Parameters::simulationSpeed -= 0.1;
		if (Parameters::simulationSpeed < 0)
			Parameters::simulationSpeed = 0.0;
	}

	/**
	 *@function fasterSimulation
	 *@brief 	function is used to faster the simulation
	 */
	void fasterSimulation() {
		Parameters::simulationSpeed += 0.1;
	}

private:
	std::list<Animal*> animalList;
	std::list<Animal*> registeredanimalList;
	std::list<Action*> actionsList;

	/**
	 *@function findAnimal
	 *@brief 	Function finds an animal using specified coordinates. If there's no such animal, function returns nullptr.
	 *@argument x -	position on x axis
	 *@argument y - position on y axis
	 *@return	Pointer to the animal class.
	 */
	Animal* findAnimal(unsigned x, unsigned y);

	bool deregisterAnimal(Animal*);
	bool isRegistered(Animal*) const;
	bool registerAnimal(unsigned, unsigned);
	bool registerAnimal(Animal*);
	bool deregisterAnimal(unsigned, unsigned);
};

#endif	/* MODEL_H */
