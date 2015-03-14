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
    void createHerbivore(const Animal*, const Animal*);
    // Funkcja, ktora tworzy zwierze powstale w wyniku kopulacji
    void createCarnivore(const Animal*, const Animal*);
    // Update'uje statusy wszystkich jednostek
    void updateAnimalsStatuses();
    // Pobiera vector zwierzat w obrebie trojkata
    // Parametry to wysokosc i kat
    std::vector<const Animal*> getAnimalsInTriangle(double, double) const;
    // Pobiera Wspolrzedne widzianego zwierzeta
    Coordinates getCoordinates(const Animal*) const;    
    
private:
    // Tworzy herrbivore na podstawie dziecka
    void createHerbivore(const Animal*);
    // Tworzy carnivore na podstawie dziecka
    void createCarnivore(const Animal*);
    std::list<Animal*> animalList_;
    Attributes mixAttributes(const Animal*, const Animal*);
};

#endif	/* MODEL_H */