#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <vector>

class Measurement
{
public:
	struct Control
	{
		float delta_x; // move only x axis
	};

	struct Observation
	{
		std::vector<float> distance;
	};
	
	Control control_;
	Observation observation_;

};


#endif // !MEASUREMENT_H_
