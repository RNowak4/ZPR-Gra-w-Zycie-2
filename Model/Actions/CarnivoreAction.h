/*
 * CarnivoreAction.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef CARNIVOREACTION_H_
#define CARNIVOREACTION_H_

#include "Action.h"

class CarnivoreAction: public Action {
public:
	CarnivoreAction();
	virtual ~CarnivoreAction();
	virtual void performAction() = 0;
	virtual shared_ptr<Action> chooseNextAction() = 0;
};

#endif /* CARNIVOREACTION_H_ */
