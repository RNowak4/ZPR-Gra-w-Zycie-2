/* 
 * File:   Attributes.h
 * Author: Radek
 *
 * Created on 12 marca 2015, 00:37
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

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
};

#endif	/* ATTRIBUTES_H */