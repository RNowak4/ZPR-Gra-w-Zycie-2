/*
 * Illness.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ILLNESS_H_
#define ILLNESS_H_

#include "State.h"

class Illness: public State {
public:
	Illness();
	string toString();
};

#endif /* ILLNESS_H_ */
