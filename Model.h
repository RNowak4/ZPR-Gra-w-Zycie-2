/* 
 * File:   Model.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef MODEL_H
#define	MODEL_H

#include "Animal.h"
#include <list>

/* Model bedzie wysylal cale paczki danych
 * do Controllera. Pewnie w postaci listy.
 */

class Model {
public:
    Model();
    Model(const Model& orig);
    ~Model();
    // Funkcja, ktora tworzy zwierze o konkretnych parametrach.
    Animal* createAnimal();
    // Update'uje statusy wszystkich jednostek
    void updateAnimalsStatuses();
    
private:
    std::list<Animal*> animalList_;
};

#endif	/* MODEL_H */