/*
 * AnimalData.h
 *
 *  Created on: 16-05-2015
 *      Author: radek
 */

#ifndef ANIMALDATA_H_
#define ANIMALDATA_H_

#include <string>
#include <vector>

using namespace std;

class AnimalData {
private:
	vector<string> stringVector;
	vector<pair<string, double> > pairVector;

public:
	AnimalData();
	void pushString(const string&);
	void pushPair(const pair<string, double>&);
	void pushPair(string stringToPush, double numberToPush);
	const vector<string>& returnStringVector() const {
		return stringVector;
	}
	const vector<pair<string, double> >& returnPairVector() const {
		return pairVector;
	}
};

#endif /* ANIMALDATA_H_ */
