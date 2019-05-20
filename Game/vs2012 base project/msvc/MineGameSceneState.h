#pragma once 
#include "IScene.h"
#include "MineGameScene.h"
namespace minegame
{

	class MineGameScene;
	class MineGameSceneState
	{
	protected:
		MineGameScene& _scene;

	public:
		MineGameSceneState(MineGameScene& scene) : _scene(scene) {}

		virtual void EnterState() = 0;
		virtual void LeaveState() = 0;

		virtual void Enter() = 0;
		virtual void Leave() = 0;
		virtual IScene* Update(float elapsed) = 0;
		virtual void Draw() const;

	
		virtual ~MineGameSceneState() {};



	};


}
