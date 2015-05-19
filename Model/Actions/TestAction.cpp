/*
 * TestAction.cpp
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#include "TestAction.h"

TestAction::TestAction() {
}

TestAction::~TestAction() {
}

void TestAction::performAction() {
	// Do nothing
}

shared_ptr<Action> TestAction::chooseNextAction() {
	return shared_ptr<Action>(this);
}
