#ifndef MAP_H_
#define MAP_H_

#include <vector>

class Map 
{
public: 
	//single point in the map
	struct SingleLandmark 
	{
		int id;
		float x;
	};

	std::vector<SingleLandmark> landmark_list_;
	
};

#endif // MAP_H_



