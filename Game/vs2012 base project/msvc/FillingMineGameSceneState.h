#pragma once
#include "MineGameSceneState.h"

namespace minegame
{
	class FillingMineGameSceneState : public MineGameSceneState
	{
	private:
		

	public:
		FillingMineGameSceneState(MineGameScene& s) : MineGameSceneState(s) {};

		~FillingMineGameSceneState() {};

		// Inherited via MineGameSceneState
		virtual void EnterState( ) override;
		virtual void LeaveState( ) override;
		virtual void Enter( ) override;
		virtual void Leave( ) override;
		virtual IScene * Update( float elapsed) override;
	};




}
