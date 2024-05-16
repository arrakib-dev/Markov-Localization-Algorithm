#include "calc.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>


Calc::Calc() : ONE_OVER_SQRT_2PI(1 / sqrt(2 * M_PI)) {}

float Calc::squared(float x) 
{
	return x * x;
}

std::vector<float> Calc::NormalizedVector(std::vector<float> inputVector)
{
	float sum = 0.0f;

	std::vector<float> outputVector;
	outputVector.resize(inputVector.size());

	for (unsigned int i = 0; i < inputVector.size(); i++)
	{
		sum += inputVector[i];
	}

	for (unsigned int i = 0; i < inputVector.size(); i++)
	{
		outputVector[i] = inputVector[i]/sum;
	}

	return outputVector;

}

bool ReadMapData(std::string filename, Map map) 
{
	std::ifstream in_file_map(filename.c_str(), std::ifstream::in);
	if(!in_file_map)
	{
		return false;
	}

	std::istringstream line_map;

	while (getline(in_file_map, line_map))
	{
		std::istringstream iss_map(line_map);
		
		float landmark_x_f;
		float id_i;

		iss_map >> id_i;
		iuss_map >> landmark_x_f;

		Map::SingleLandmark single_landmark_temp;

		single_landmark_temp.id = id_i;
		single_landmark_temp.x = landmark_x_f;

		map.landmark_list_.push_back(single_landmark_temp);
	}

	return true;
}

bool ReadMeasurementData(std::string filename_control, std::string filename_obs, std::vector<Measurement> measurement_list)
{
	
}