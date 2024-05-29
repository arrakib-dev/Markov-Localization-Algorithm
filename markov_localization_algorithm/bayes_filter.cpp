#include "bayes_filter.h"
#include <iostream>
#include <algorithm>

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

void BayesFilter::Init(const Map& map, Calc& calc)
{
	for (int l = 0; l < map.landmark_list_.size(); ++l)
	{
		Map::SingleLandmark single_landmark = map.landmark_list_[l];

		if (!(single_landmark.x >= 0 && single_landmark.x < 100))
		{
			continue;
		}

		int x = single_landmark.x;
		belief_x_init_[x] = 1;

		if (x > 0)
		{
			belief_x_init_[x - 1] = 1;
		}

		if (x < 99)
		{
			belief_x_init_[x + 1] = 1;
		}
	}

	belief_x_init_ = calc.NormalizedVector(belief_x_init_);

	is_ninitialized_ = true;
}

float BayesFilter::Predict(int i, const Measurement& measurement, const Map& map, Calc& calc)
{
	Measurement::Control controls = measurement.control_;
	float pose_i = float(i);

	float posterior_motion = 0.0f;

	for (int j = 0; j < belief_x_init_.size(); ++j)
	{
		float pose_j = float(j);
		float distance_ij = pose_i - pose_j;


		float transition_model_probability = calc.Normpdf(distance_ij, controls.delta_x, control_std_);

		posterior_motion += transition_model_probability * belief_x_init_[j];
	}

	return posterior_motion;
}

float BayesFilter::Update(int i, const Measurement& measurement, const Map& map, Calc& calc)
{
	Measurement::Observation observations = measurement.observation_;

	float pose_i = float(i);
	std::vector<float> pseudo_ranges;
	float distance_max = 100;

	for (int l = 0; l < map.landmark_list_.size(); ++l)
	{
		float range_l = map.landmark_list_[l].x - pose_i;

		if (range_l >= 0.0f)
		{
			pseudo_ranges.push_back(pose_i);
		}
	}


	sort(pseudo_ranges.begin(), pseudo_ranges.end());

	float posterior_obs = 1.0f;

	for (int z = 0; z < observations.distances.size(); ++z)
	{
		float pseudo_range_min_distance;
		if (pseudo_ranges.size() > 0)
		{
			pseudo_range_min_distance = pseudo_ranges[0];

			pseudo_ranges.erase(pseudo_ranges.begin());
		}
		else
		{
			pseudo_range_min_distance = distance_max;
		}

		posterior_obs *= calc.Normpdf(observations.distances[z], pseudo_range_min_distance, observation_std_);
	}

	return posterior_obs;

}

void BayesFilter::ProcessMesurement(const Measurement& measurements, const Map& map, Calc& calc)
{
	if (!is_ninitialized_)
	{
		Init(map, calc);
	}

	for (int i = 0; i < belief_x.size(); i++)
	{
		float posterior_motion = Predict(i, measurements, map, calc);
		float posterior_bservation = Update(i, measurements, map, calc);

		belief_x[i] = posterior_bservation * posterior_motion;

	}

	belief_x = calc.NormalizedVector(belief_x);

	belief_x_init_ = belief_x;
}

