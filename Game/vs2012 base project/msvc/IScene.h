#pragma once
#include "IUpdateable.h"
#include "IDrawable.h"
namespace minegame
{


	class IScene :  public IDrawable
	{
	protected:
		float _posX;
		float _posY;
	
	public:

		virtual void Enter() = 0;
		virtual void Leave() = 0;

		
		virtual IScene* Update(float elapsed) = 0;
		virtual ~IScene() {};

	
	};

}