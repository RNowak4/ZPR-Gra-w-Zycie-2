/**
 * @file Carnivore.h
 * @brief Class that represents a Carnivore
 *
 * @author Radoslaw Nowak
 */

#ifndef CARNIVORE_H
#define	CARNIVORE_H

#include "Animal.h"

class Carnivore: public Animal {
public:
	/**
	 *@function Carnivore
	 *@brief 	Constructs single carnivore at specified coordinates
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 */
	Carnivore(unsigned x, unsigned y);

	/**
	 *@function Carnivore
	 *@brief 	Constructs single carnivore at specified coordinates and modifiers
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 *@argument modifiers - modifiers that will be copied
	 */
	Carnivore(unsigned x, unsigned y, const Modifiers& modifiers);

	/**
	 *@function isDangerous
	 *@brief 	Checks if an animal is dangerous for another one
	 *@argument another -	another animal
	 */
	bool isDangerous(Animal* another) {
		return true;
	}

	void updateStatus();
};

#endif	/* CARNIVORE_H */
