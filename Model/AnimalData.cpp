/**
 * @file Model.h
 * @brief Implementation of the AnimalData class.
 *
 * @author Radoslaw Nowak
 */

#include "AnimalData.h"

#include <utility>

AnimalData::AnimalData() {
}

void AnimalData::setActionName(const string& action_name) {
	this->action_name = action_name;
}

void AnimalData::pushString(const string& stringToPush) {
	stringVector.push_back(stringToPush);
}

void AnimalData::pushPair(const pair<string, double>& pairToPush) {
	pairVector.push_back(pairToPush);
}

void AnimalData::pushPair(string stringToPush, double numberToPush) {
	pairVector.push_back(pair<string, double>(stringToPush, numberToPush));
}
