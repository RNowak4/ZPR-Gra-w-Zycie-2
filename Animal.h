/* 
 * File:   Animal.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <vector>

/* Uwaga
 * Klasa C powinna dostarczyc interfejs do "zabicia"
 * Jednostki. CheckStatus moze np. zabic jednostke this,
 * albo zabic inna jednostke. Wtedy wysyla do Controllera wiadomosc
 * o tym, a Controller usuwa podane jednostki. 
 */

struct Coordinates{
    double x,y;
    Coordinates(double X, double Y) : x(X), y(Y) { }
};

class Animal {
private:
    double strength_;
    double speed_;
    double fertility_; // Plodnosc
    double hunger_; // Glod?
    double sightLen_; // Jak daleko jednostka widzi = wys trojkata
    unsigned lifeLen_; // Dlugosc zycia wyrazona w ustalonych kwantach czasu
    // Tak jak w ukladzie wspolrzednych kartezjanskich 2D.
    unsigned sightRad_; 
    Coordinates coordinates_;
    
protected:
    // Pobiera Wspolrzedne widzianego zwierzeta
    Coordinates getCoordinates(const Animal*) const;
    // Zwraca vector z widzianymi zwierzetami
    std::vector<const Animal*> getAnimalsInSight() const;
    
public:
    Animal();
    Animal(const Animal& orig);
    virtual ~Animal() = 0;
    // Aktualizuje status jednostki
    virtual void updatetatus() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return coordinates_; }
};

#endif	/* ANIMAL_H */