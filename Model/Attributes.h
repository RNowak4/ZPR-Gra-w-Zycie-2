/* 
 * File:   Attributes.h
 * Author: Radek
 *
 * Created on 12 marca 2015, 00:37
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

/* TODO:
 *-Kazda bierna cecha bedzie reprezentowana 
 * przez staly singleton. Pobierane beda jej atrybuty
 * i dodawane do atrybutow tymczasowych.
 * 
 *-Dodac standardowe wartosci dla atrybutow w pliku *cpp.
 */

#include <chrono>
#include <random>
#include <vector>

class Attributes {
private:
    double strength_;
    double speed_;
    double fertility_; // Plodnosc
    double hunger_; // Glod?
    double sightLen_; // Jak daleko jednostka widzi = wys trojkata
    unsigned lifeLen_; // Dlugosc zycia wyrazona w ustalonych kwantach czasu
    // Kat widzenia
    unsigned sightRad_; 
    // Funkcja, ktora generuje atrybuty zupelnie losowo, bez przodkow
    // Wywolana, gdy vector atrybutow jest pusty
    void generateAttributes();
    
public:
    Attributes();
    Attributes(const Attributes& orig);
    virtual ~Attributes();
    // Funkcja, ktora generuje atrybuty na podstawie przodkow
    void inheritAttributes(std::vector<Attributes>);
    // Przekopiowanie atrybutow
    Attributes& operator=(const Attributes&);
    //Dodanie atrybutow do istniejacych
    Attributes& operator+(const Attributes&) const;
};

#endif	/* ATTRIBUTES_H */