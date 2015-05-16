/*
 * Action.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ACTION_H_
#define ACTION_H_

class Action {
public:
	Action();
	virtual ~Action();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
};

#endif /* ACTION_H_ */
