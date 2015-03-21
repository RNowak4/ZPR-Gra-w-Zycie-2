/* 
 * File:   Animal.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:29
 */

#include "Animal.h"

//TODO: Uzupelnic ten konstrktor
Animal::Animal(const Animal* mother, const Animal* father) : sex_(MALE) {
	baseAttributes_.inheritAttributes(mother->getBaseAttributes(),
		father->getBaseAttributes(),
		mother->getAncestorTraits(),
		father->getAncestorTraits()
		);


}

Animal::Animal(double x, double y) {
    locationData_.coordinates_.x = x;
    locationData_.coordinates_.y = y;
}