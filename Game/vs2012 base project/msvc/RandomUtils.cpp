#include "RandomUtils.h"

namespace minegame
{
	 

	int RandomUtils::Get(int from, int to) 
	{
		std::uniform_int_distribution<int> int_dist(from, to);
		return int_dist(_rng);
	}
}