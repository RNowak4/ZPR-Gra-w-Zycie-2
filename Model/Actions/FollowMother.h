/*
 * FollowMother.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_FOLLOWMOTHER_H_
#define MODEL_ACTIONS_FOLLOWMOTHER_H_

#include "ChildAction.h"

class FollowMother: public ChildAction {
public:
	FollowMother(Animal*, Animal*);
	virtual ~FollowMother();
	virtual void performAction();
	virtual Action* chooseNextAction();
	virtual void deleteAnimal(const Animal*);
};

#endif /* MODEL_ACTIONS_FOLLOWMOTHER_H_ */
