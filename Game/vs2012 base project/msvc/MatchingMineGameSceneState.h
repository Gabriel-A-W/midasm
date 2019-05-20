#pragma once
#include "MineGameSceneState.h"


namespace minegame
{
	class MatchingMineGameSceneState: public MineGameSceneState
	{

	private:
		GemSocketMatchList* _matches;
		void DoMatching(GemSocketMatchList& matches);
	public:
		MatchingMineGameSceneState(MineGameScene& s) : MineGameSceneState(s), _matches(nullptr) {};
		MatchingMineGameSceneState(MineGameScene& s, GemSocketMatchList* m) : MatchingMineGameSceneState(s) { _matches = m; };

		~MatchingMineGameSceneState() {};

		// Inherited via MineGameSceneState
		virtual void EnterState( ) override;
		virtual void LeaveState( ) override;
		virtual void Enter( ) override;
		virtual void Leave( ) override;
		virtual IScene * Update(float elapsed) override;
	};


}


