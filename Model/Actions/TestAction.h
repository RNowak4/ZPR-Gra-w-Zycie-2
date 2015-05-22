/*
 * TestAction.h
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_TESTACTION_H_
#define MODEL_ACTIONS_TESTACTION_H_

#include "Action.h"

class TestAction: public Action {
public:
	TestAction();
	TestAction(Animal*);
	TestAction(Animal*, Model*);
	virtual ~TestAction();
	void performAction();
	Action*chooseNextAction();
};

#endif /* MODEL_ACTIONS_TESTACTION_H_ */
