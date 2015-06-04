/* 
 * File:   Attributes.cpp
 * Author: Radek
 * 
 * Created on 12 marca 2015, 00:37
 */

#include "Attributes.h"

void normalize(int& value) {
	if (value < 0)
		value = 0;
}

void normalize(double& value) {
	if (value < 0.0)
		value = 0.0;
}

Attributes::Attributes() {
	strength_ = distribution(generator);
	maximalSpeed_ = distribution(generator);
	fertility_ = static_cast<int>(distribution(generator));
	sickChance_ = sickChanceDistribution(generator);

	sightLength_ = static_cast<int>(distribution(generator) * 400.0 / 6.0);
	sightAngle_ = static_cast<int>(distribution(generator) * 360.0 / 20.0
			- (sightLength_ - 300) * 1 / 4.0);

	hearingRange_ = static_cast<int>(distribution(generator) * 400.0 / 6.0);

	// Not needed to be a random, but we want different
	// startup, so i did it random.
	sleepNeed_ = (distribution2(generator) / 200.0
			+ (maximalSpeed_ + strength_) / 400.0) / 30.0;
	eatNeed_ = (distribution2(generator) / 200.0
			+ (maximalSpeed_ + strength_) / 400.0) / 30.0;

	lifeLen_ = lifeDistribution(generator);

	normalizeAll();
}

default_random_engine Attributes::generator;
normal_distribution<double> Attributes::distribution(5.0, 1.0);
normal_distribution<double> Attributes::distribution2(6.0, 1.0);
normal_distribution<double> Attributes::lifeDistribution(750, 175);
normal_distribution<double> Attributes::sickChanceDistribution(1, 0.3);
normal_distribution<double> Attributes::mutationDistribution(0, 0.2);
normal_distribution<double> Attributes::mutationLifeDistribution(0, 10);

void Attributes::normalizeAll() {
	normalize(strength_);
	normalize(maximalSpeed_);
	normalize(fertility_);
	normalize(sickChance_);
	normalize(hearingRange_);
	normalize(sleepNeed_);
	normalize(eatNeed_);
	normalize(lifeLen_);
	sickChance_ /= 25.0;
}

Attributes Attributes::inheritAttributes(
		const Attributes& secondAttributes) const {
	Attributes newAttributes;

	newAttributes.strength_ = (this->strength_ + secondAttributes.strength_)
			/ 2.0 + mutationDistribution(generator);

	newAttributes.fertility_ = (this->fertility_ + secondAttributes.fertility_)
			/ 2.0 + mutationDistribution(generator) * 4.0;

	newAttributes.sickChance_ = (this->sickChance_
			+ secondAttributes.sickChance_) / 2.0
			+ mutationDistribution(generator);

	newAttributes.sightAngle_ = (this->sightAngle_
			+ secondAttributes.sightAngle_) / 2.0
			+ (mutationDistribution(generator) * 360.0 / 20.0);

	newAttributes.sightLength_ = (this->sightLength_
			+ secondAttributes.sightLength_) / 2.0
			+ (mutationDistribution(generator) * 400.0 / 6.0);

	newAttributes.hearingRange_ = (this->hearingRange_
			+ secondAttributes.hearingRange_) / 2.0
			+ (mutationDistribution(generator) * 400.0 / 6.0);

	newAttributes.eatNeed_ = (this->eatNeed_ + secondAttributes.eatNeed_) / 2.0
			+ mutationDistribution(generator);

	newAttributes.sleepNeed_ = (this->sleepNeed_ + secondAttributes.sleepNeed_)
			/ 2.0 + mutationDistribution(generator);

	newAttributes.lifeLen_ = (this->lifeLen_ + secondAttributes.lifeLen_) / 2.0
			+ mutationLifeDistribution(generator);

	newAttributes.normalizeAll();

	return newAttributes;
}
