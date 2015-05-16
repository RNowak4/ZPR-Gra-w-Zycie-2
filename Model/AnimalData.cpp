/*
 * AnimalData.cpp
 *
 *  Created on: 16-05-2015
 *      Author: radek
 */

#include "AnimalData.h"

AnimalData::AnimalData() { }

void AnimalData::pushString(const string& stringToPush) {
	stringVector.push_back(stringToPush);
}

void AnimalData::pushPair(const pair<string, double>& pairToPush) {
	pairVector.push_back(pairToPush);
}

void AnimalData::pushPair(string stringToPush, double numberToPush) {
	pairVector.push_back(pair<string,double>(stringToPush,numberToPush));
}
