/*
 * HerbivoreAction.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef HERBIVOREACTION_H_
#define HERBIVOREACTION_H_

#include "Action.h"

class HerbivoreAction: public Action {
public:
	HerbivoreAction();
	virtual ~HerbivoreAction();
	virtual void performAction() = 0;
	virtual shared_ptr<Action> chooseNextAction() = 0;
};

#endif /* HERBIVOREACTION_H_ */
