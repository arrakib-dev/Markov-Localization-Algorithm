#ifndef CALC_H_
#define CALC_H_

#include <cmath>
#include <string>
#include "map.h"
#include "measurement.h"

class Calc
{
public:
	Calc();

	const float ONE_OVER_SQRT_2PI;

	float squared(float x);

	float Normpdf(float x, float mu, float std);

	std::vector<float> NormalizedVector(std::vector<float> inputVector);

	bool ReadMapData(std::string filename, Map map);

	bool ReadMeasurementData(std::string filename_control, std::string filename_obs, std::vector<Measurement> measurement_list);

	bool CompareData(std::string filename_gt, std::vector<float> resultVector);


};


#endif // !CALC_H_
