/* 
 * File:   Attributes.cpp
 * Author: Radek
 * 
 * Created on 12 marca 2015, 00:37
 */

#include "Attributes.h"

// TODO  Generowanie poczatkowych atrybutow na podsatwie modyf.
//		 Beda one potem modyfikowane przez Actions
Attributes::Attributes() {
	normal_distribution<double> distribution(5.0, 1.0);
	normal_distribution<double> distribution2(6.0, 1.0);
	normal_distribution<double> lifeDistribution(750, 175);

	strength_ = distribution(generator);
	maximalSpeed_ = distribution(generator);
	fertility_ = static_cast<int>(distribution(generator));
	sickChance_ = distribution(generator);
	// TODO sprawdzic, czy /20.0 jest odpowiednia liczba
	sightAngle_ = static_cast<int>(distribution(generator) * 360.0 / 20.0);
	// TODO sprawdzic, czy /10.0 jest odpowiednia liczba
	sightLength_ = static_cast<int>(distribution(generator) * 400.0 / 6.0);
	hearingRange_ = static_cast<int>(distribution(generator) * 400.0 / 6.0);

	// Not needed to be a random, but we want different
	// startup, so i did it random.
	sleepNeed_ = (distribution2(generator) / 200.0 + maximalSpeed_ / 400.0)
			/ 10.0;
	eatNeed_ = (distribution2(generator) / 200.0 + maximalSpeed_ / 400.0)
			/ 10.0;

	lifeLen_ = lifeDistribution(generator);
}

default_random_engine Attributes::generator;

Attributes Attributes::inheritAttributes(
		const Attributes& secondAttributes) const {
	Attributes newAttributes;
	normal_distribution<double> mutationDistribution(0, 0.2);
	normal_distribution<double> mutationLifeDistribution(0, 10);

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

	return newAttributes;
}
