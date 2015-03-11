/* 
 * File:   Animal.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <list>

/* Uwaga
 * Klasa C powinna dostarczyc interfejs do "zabicia"
 * Jednostki. CheckStatus moze np. zabic jednostke this,
 * albo zabic inna jednostke. Wtedy wysyla do Modelu wiadomosc
 * o tym, a Model usuwa podane jednostki. Nastepnie wywoluje metode
 * Controllera, ktora ma go powiadomic o koniecznosci usuniecia jednostki
 * z ekranu.
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
    std::list<const Animal*> getAnimalsInSight() const;
    
public:
    // Animal bedzie przyjmowalo okreslone wartosci srednie i odchylenia std
    // Przy powolaniu do zycia. Nastepnie z nich wygeneruje
    // Wartosci losowe zgodnie z rozkladem gaussa.
//    Animal(...);
    // Zadnego klonowania. To wbrew naturze, barbarzynco.
    // W sumie klonowanie moze sie przydac przy kopiowaniu calego modelu
    Animal(const Animal& orig) = delete; 
    // Za bardzo nie ma czego usuwac, wiec pusty destruktor
    // Usuwaniem z ekranu zajmuje sie Cotroller.
    virtual ~Animal() { }
    // Aktualizuje status jednostki
    virtual void updatetatus() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return coordinates_; }
};

#endif	/* ANIMAL_H */