/**
 * @file AnimalData.h
 * @brief Class that animals data which user can see in a animal window.
 *
 * @author Radoslaw Nowak
 */

#ifndef ANIMALDATA_H_
#define ANIMALDATA_H_

#include <string>
#include <utility>
#include <vector>

using namespace std;

class AnimalData {
private:
	string action_name;
	vector<string> stringVector;
	vector<pair<string, double> > pairVector;

public:
	/**
	 *@function AnimalData
	 *@brief Default constructor.
	 */
	AnimalData();

	/**
	 *@function setActionName
	 *@brief Sets action name to send it to the View
	 *@param action_name - name of the action
	 */
	void setActionName(const string& action_name);

	/**
	 *@function pushString
	 *@brief Pushes single string into vector.
	 *@param strintToPush	- string to push
	 */
	void pushString(const string& strintToPush);

	/**
	 *@function pushPair
	 *@brief Pushes single pair into vector.
	 *@param pairToPush	- pair to push
	 */
	void pushPair(const pair<string, double>& pairToPush);

	/**
	 *@function pushPair
	 *@brief Creates and pushes single pair into vector.
	 *@param stringToPush	- string to push
	 *@param numberToPush	- double value to push
	 */
	void pushPair(string stringToPush, double numberToPush);

	/**
	 *@function returnStringVector
	 *@brief Returns an vector of strings to view.
	 *@return	vector of strings
	 */
	const vector<string>& returnStringVector() const {
		return stringVector;
	}

	/**
	 *@function returnStringVector
	 *@brief Returns an vector of pairs to view.
	 *@return	vector of strings
	 */
	const vector<pair<string, double> >& returnPairVector() const {
		return pairVector;
	}
};

#endif /* ANIMALDATA_H_ */
