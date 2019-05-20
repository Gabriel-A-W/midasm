#pragma once
namespace minegame
{


	class IUpdateable
	{
	public:
		virtual void Update(float elapsed) = 0;

		virtual ~IUpdateable() {};
	};

}