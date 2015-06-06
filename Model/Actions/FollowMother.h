/**
* @file FollowMother.h
* @brief Class that is used to represent
* @brief following the mother performed by children.
*
* @author Radoslaw Nowak
*/
#ifndef MODEL_ACTIONS_FOLLOWMOTHER_H_
#define MODEL_ACTIONS_FOLLOWMOTHER_H_

#include "ChildAction.h"

/**
@class FollowMother
Class that represents following mother action being performed by child animal.
*/
class FollowMother: public ChildAction {
private:
	const static unsigned MIN_DIST = 60;
	const static unsigned MAX_DIST = 100;

public:
	FollowMother(Animal*, Animal*);
	virtual ~FollowMother();
	virtual void performAction();
	virtual Action* chooseNextAction();
	virtual void deleteAnimal(const Animal*);
	string toString() {
		return "Following mother";
	}
};

#endif /* MODEL_ACTIONS_FOLLOWMOTHER_H_ */
