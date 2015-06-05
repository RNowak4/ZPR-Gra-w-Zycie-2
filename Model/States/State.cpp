/**
* @file State.cpp
* @brief Implementation of the State class
*
* @author Radoslaw Nowak
*/

#include "State.h"

State::State(): animalPtr(nullptr) {
}

State::State(Animal* animal_ptr): animalPtr(animal_ptr) {
}

