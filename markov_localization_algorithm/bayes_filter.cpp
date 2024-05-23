#include "bayes_filter.h"
#include <iostream>

BayesFilter::BayesFilter() 
{
	is_ninitialized_ = false;
	control_std_ = 1.0f;
	observation_std_ = 1.0f;

	belief_x_init_.resize(100, 0);
	belief_x.resize(100, 0);
}

BayesFilter::~BayesFilter() 
{

}

