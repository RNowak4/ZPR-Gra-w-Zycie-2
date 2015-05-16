enum AnimalType {
	CARNIVORE, HERBIVORE,
};

struct Coordinates {
	unsigned x, y;
	// Tymczasowo, zeby nie wywalalo errorow
	Coordinates() {
	}
	Coordinates(unsigned X, unsigned Y) :
			x(X), y(Y) {
	}
};

struct LocationData {
	Coordinates coordinates_;
	unsigned lookingRad;
	unsigned lookingAngle;
	// Zmienna, ktora okresla zasieg widzenia
	double sightLen_;
	// Potrzebne do wyswietlenia
	AnimalType animalType_;
};

