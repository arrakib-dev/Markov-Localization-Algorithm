#ifndef BAYES_FILTER_H_
#define BAYES_FILTER_H_

#include <vector>
#include <string>
#include <fstream>

#include "measurement.h"
#include "calc.h"
#include "map.h"


class BayesFilter
{
public:
	BayesFilter();
	virtual ~BayesFilter();

	void ProcessMesurement(const Measurement& measurements, const Map& map, Calc& calc);

	std::vector<float> belief_x;

private:

	void Init(const Map& map, Calc& calc);

	float Predict(int i, const Measurement &mesurement, const Map& map, Calc& calc);

	float Update(int i, const Measurement& mesurement, const Map& map, Calc& calc);

	bool is_ninitialized_; 
	std::vector<float> belief_x_init_;
	float control_std_;
	float observation_std_;

};



#endif // !BAYES_FILTER_H_
