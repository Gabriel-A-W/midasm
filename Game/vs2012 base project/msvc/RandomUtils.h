#pragma once
#include <random>
#include <ctime>
namespace minegame
{


	class RandomUtils
	{
	private:
		std::mt19937 _rng;

		RandomUtils() : _rng(static_cast<long unsigned int>(time(NULL))) {};
		RandomUtils(RandomUtils& o) {};



	public:

		~RandomUtils() {};

		static RandomUtils& GetInstance()
		{
			static RandomUtils _instance;
			return _instance;
		}
		
		int Get(int from, int to);

	};

}