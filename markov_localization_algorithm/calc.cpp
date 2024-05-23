#include "calc.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "measurement.h"


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


float Calc::Normpdf(float x, float mu, float std)
{
	return (ONE_OVER_SQRT_2PI / std) * exp(-0.5 * squared((x - mu) / std));
}


bool Calc::ReadMapData(std::string filename, Map map) 
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


bool Calc::ReadMeasurementData(std::string filename_control, std::string filename_obs, std::vector<Measurement> measurement_list)
{
	std::ifstream in_file_control(filename_control.c_str(), std::ifstream::in);
	if(!in_file_control)
	{
		return false;
	}

	std::string line;
	int count = 1;

	while (getline(in_file_control, line))
	{
		Measurement measurement;

		std::istringstream iss(line);

		float delta_x_f;
		iss >> delta_x_f;

		measurement.control_.delta_x = delta_x_f;

		char str_obj[1024];

		sprintf(str_obj, "%sobservation_%06i.txt", filename_obs.c_str(), count);
		std::string in_file_observation = std::string(str_obj);

		std::ifstream in_file_observation(in_file_observation.c_str(), std::ifstream::in);

		if (!in_file_observation)
		{
			return false;
		}

		std::string line_obs;

		while (getline(in_file_observation, line_obs)) 
		{
			std::istringstream iss_obs(line_obs);

			float distance_f;

			iss_obs >> distance_f;

			measurement.observation_.distances.push_back(distance_f);

		}

		measurement_list.push_back(measurement);
		count++;
	}
	return true;
}

bool Calc::CompareData(std::string filename_gt, std::vector<float> resultVector)
{
	std::vector<float> gt_vec;

	std::ifstream in_file_gt(filename_gt.c_str(), std::ifstream::in);

	std::string line_gt;

	while (getline(in_file_gt, line_gt))
	{
		std::istringstream iss_gt(line_gt);

		float gt_value;

		iss_gt >> gt_value;

		gt_vec.push_back(gt_value);
	}

	float error_sum;
	float belief_sum;

	std::count << " Result : " << std::endl;

	for (unsigned int i = 0; i < resultVector.size(); ++i)
	{
		error_sum += (gt_vec[i] - resultVector[i]) * (gt_vec[i] - resultVector[i]);
		belief_sum += resultVector[i];

		std::cout << std::fixed << std::setprecision(5) << "bel(x)= " << i << " : \t"
			<< resultVector[i] << "\t"
			<< "ground truth: \t"
			<< gt_vect[i] << std::endl;

	}

	std::cout << "----------------------------------------" << std::endl;
	std:cout << std::fixed << std::setprecision(5) << "belief_sum:\t" << belief_sum << std::endl;
	std::count << std::fixed << std::setprecision(5) << "sqrt error sum:\t" << sqrt(error_sum) << std::endl;

	return true;
	
}
