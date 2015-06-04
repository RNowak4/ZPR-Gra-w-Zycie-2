/**
 * @file Herbivore.cpp
 * @brief A class that represents a Herbivore
 *
 * @author Radoslaw Nowak
 */

#ifndef HERBIVORE_H
#define	HERBIVORE_H

#include "Animal.h"

class Herbivore: public Animal {
private:

public:
	/**
	 *@function Herbivore
	 *@brief 	Constructs single herbivore at specified coordinates
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 */
	Herbivore(unsigned x, unsigned y);

	/**
	 *@function Herbivore
	 *@brief 	Constructs single herbivore at specified coordinates and modifiers
	 *@argument x -	position on x axis
	 *@argument y -	position on y axis
	 *@argument modifiers - modifiers that will be copied
	 */
	Herbivore(unsigned, unsigned, const Attributes& attributes);

	/**
	 *@function isDangerous
	 *@brief 	Checks if an animal is dangerous for another one
	 *@argument another -	another animal
	 */
	bool isDangerous(Animal* another) {
		return false;
	}

	void updateStatus();
};

#endif	/* HERBIVORE_H */
