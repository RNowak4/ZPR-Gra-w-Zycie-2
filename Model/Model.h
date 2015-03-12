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
/* Do implementacji w Modelu:
 *-Klasa Controllera powinna dostarczyc interfejs do "zabicia"
 * Jednostki. UpdateStatus moze np. zabic jednostke this,
 * albo zabic inna jednostke. Wtedy wysyla do Modelu wiadomosc
 * o tym, a Model usuwa podane jednostki. Nastepnie wywoluje metode
 * Controllera, ktora ma go powiadomic o koniecznosci usuniecia jednostki
 * z ekranu.
 * 
 *-W C powinna byc metoda, ktora wysyla pojemnik z wskaznikami
 * na jednostki, ktore znajduja sie w obrebie zadanego kwadratu lub okregu.
 */

class Model {
public:
    Model();
    Model(const Model& orig);
    ~Model();
    // Funkcja, ktora tworzy zwierze powstale w wyniku kopulacji
    Animal* createAnimal(const Animal*, const Animal*);
    // Update'uje statusy wszystkich jednostek
    void updateAnimalsStatuses();
    // Pobiera vector zwierzat w obrebie trojkata
    std::vector<const Animal*> getAnimalsInTriangle(double, double, double) const;
    
private:
    // Funkcja, ktora tworzy zwierze o losowych
    Animal* createAnimal();
    std::list<Animal*> animalList_;
};

#endif	/* MODEL_H */