enum AnimalType {
	CARNIVORE, HERBIVORE,
};

struct Coordinates {
	unsigned x, y;
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
	unsigned lookingAngle;
	unsigned lookingRad;
	double sightLen_;
	AnimalType animalType_;
};

