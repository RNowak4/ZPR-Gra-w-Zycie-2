/**
 * @file Constants.h
 * @brief Implementation of the Constants class
 *
 * @author Radoslaw Nowak
 */

#include "Constants.h"

const double Constants::DEFAULT_MAXIMAL_VALUE = 10.0;

const time_t Constants::DEFAULT_INTERVAL = 5;

const unsigned Constants::DEFAULT_ACTION_TIME_CHANGE = 1;

const unsigned Constants::DEFAULT_HERBIVORE_SIGHT_LEN = 300;
const unsigned Constants::DEFAULT_HERBIVORE_SIGHT_RAD = 90;
const unsigned Constants::DEFAULT_HERBIVORE_LIFE_LEN = 7.0;
const unsigned Constants::DEFAULT_HERBIVORE_HEARING_DISTANCE = 80;
const double Constants::DEFAULT_HERBIVORE_MAX_SPEED = 2.5;
const double Constants::DEFAULT_HERBIVORE_ACCELERATION = 0.075;
const double Constants::DEFAULT_HERBIVORE_CONSUMPTION = 0.002;
const double Constants::DEFAULT_HERBIVORE_EXAUSTING = 0.002;

const unsigned Constants::DEFAULT_CARNIVORE_SIGHT_LEN = 300;
const unsigned Constants::DEFAULT_CARNIVORE_HUNGER = 6.0;
const unsigned Constants::DEFAULT_CARNIVORE_SIGHT_RAD = 90;
const unsigned Constants::DEFAULT_CARNIVORE_LIFE_LEN = 6.0;
const unsigned Constants::DEFAULT_CARNIVORE_HEARING_DISTANCE = 80;
const double Constants::DEFAULT_CARNIVORE_MAX_SPEED = 3.0;
const double Constants::DEFAULT_CARNIVORE_ACCELERATION = 0.08;
const double Constants::DEFAULT_CARNIVORE_CONSUMPTION = 0.0005;
const double Constants::DEFAULT_CARNIVORE_EXAUSTING = 0.001;

unsigned Constants::adultWidth = 50;
unsigned Constants::adultHeigth = 70;
unsigned Constants::youngWidth = 30;
unsigned Constants::youngHeigth = 50;
unsigned Constants::mapWidth = 20000;
unsigned Constants::mapHeight = 20000;
