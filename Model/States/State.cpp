/*
 * State.cpp
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#include "State.h"

State::State(): animalPtr(nullptr) {
}

State::State(Animal* animal_ptr): animalPtr(animal_ptr) {
}

