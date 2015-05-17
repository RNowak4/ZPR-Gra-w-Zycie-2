/* 
 * File:   Model.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef MODEL_H
#define	MODEL_H

#include "Animal.h"
#include "Herbivore.h"
#include <list>
#include <vector>

class Model {
public:
	Model();
	Model(const Model& orig);
	~Model();
	// Funkcja, ktora tworzy zwierze powstale w wyniku kopulacji
	void createHerbivore(const Animal*, const Animal*);
	// Funkcja, ktora tworzy zwierze powstale w wyniku kopulacji
	void createCarnivore(const Animal*, const Animal*);

	// Funkcje do szybkiego wyswietlania! Tylko w ramach testow!
	void createCarnivore(unsigned, unsigned);
	void createHerbivore(unsigned, unsigned);
	//*********************************************************

	// Update'uje statusy wszystkich jednostek
	void updateAnimalsStatuses();
	//Updatuje pozycje zwierzat na mapie.
	void updateAnimalsPosition();
	// Pobiera vector zwierzat w obrebie trojkata
	// Parametry to wysokosc i kat
	std::vector<const Animal*> getAnimalsInTriangle(double, double) const;
	// Pobiera Wspolrzedne widzianego zwierzeta
	Coordinates getCoordinates(const Animal*) const;

	std::vector<const LocationData*> getAnimalsLocationData();
	std::vector<pair<const LocationData*, const AnimalData*> > getAnimalsData();
	bool registerAnimal(unsigned, unsigned);
	bool deregisterAnimal(unsigned, unsigned);

private:
	// Tworzy herrbivore na podstawie dziecka
	void createHerbivore(const Animal*);
	// Tworzy carnivore na podstawie dziecka
	void createCarnivore(const Animal*);
	std::list<Animal*> animalList_;
	std::list<Animal*> registeredAnimalList_;
	Attributes mixAttributes(const Animal*, const Animal*);
	Animal* findAnimal(unsigned, unsigned);
	bool deregisterAnimal(Animal*);
	bool isRegistered(Animal*) const;
};

#endif	/* MODEL_H */
