/**
 * @file ViewStructs.cpp
 * @brief Some basic structures/enums
 *
 * @author Radoslaw Nowak
 */

#ifndef VIEWSTRUCTS_H
#define VIEWSTRUCTS_H

enum AnimalType {
	CARNIVORE, HERBIVORE, CARNIVORE_CHILD, HERBIVORE_CHILD
};

enum Sex {
	FEMALE, MALE
};

struct Coordinates {
	double x, y;
	Coordinates() {
		x = 0;
		y = 0;
	}
	Coordinates(unsigned X, unsigned Y) :
			x(X), y(Y) {
	}
	bool operator==(const Coordinates& toCompare) {
		if (toCompare.x == x && toCompare.y == y)
			return true;
		return false;
	}
};

struct LocationData {
	Coordinates coordinates_;
	int lookingAngle;
	unsigned lookingRad;
	double sightLen_;
	AnimalType animalType_;
	Sex animalSex_;
};

#endif
