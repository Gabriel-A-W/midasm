#pragma once
#include "MineGameSceneState.h"

namespace minegame
{
	class IdleMineGameSceneState : public MineGameSceneState
	{
	private:
		bool _mouseButtonWasDown;
		GemSocket* _prevSock;
		

	public:
		IdleMineGameSceneState(MineGameScene& s) : MineGameSceneState(s), _mouseButtonWasDown(false) {};
		~IdleMineGameSceneState();


		// Inherited via MineGameSceneState
		virtual void EnterState() override;
		virtual void LeaveState() override;
		virtual void Enter() override;
		virtual void Leave() override;
		virtual IScene * Update(float elapsed) override;
	};



}
