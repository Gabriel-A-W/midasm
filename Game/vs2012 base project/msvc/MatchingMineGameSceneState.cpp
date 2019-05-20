#include "MatchingMineGameSceneState.h"
#include "IdleMineGameSceneState.h"
#include "FillingMineGameSceneState.h"
#include "IScene.h"
namespace minegame
{


	void MatchingMineGameSceneState::DoMatching(GemSocketMatchList& matches)
	{
		

		if (matches.size() > 0)
		{
			for (auto mit = matches.begin(); mit != matches.end(); ++mit)
			{

				_scene.AddScore((*mit).size() * POINTS_PER_GEM);
				for (auto sit = (*mit).begin(); sit != (*mit).end(); ++sit)
				{
					(*sit)->SetGem(nullptr);
				}
			}

			_scene.SetState(new FillingMineGameSceneState(_scene));
		}
		else
		{

			_scene.SetState(new IdleMineGameSceneState(_scene));
		}
	}

	void  MatchingMineGameSceneState::EnterState( )
	{
		 
		


	}

	void  MatchingMineGameSceneState::LeaveState( )
	{
	}

	void  MatchingMineGameSceneState::Enter( )
	{
	}

	void  MatchingMineGameSceneState::Leave( )
	{
	}

	IScene * MatchingMineGameSceneState::Update( float elapsed)
	{
		//TODO: Animar...
		if (!_scene.GetBoard().IsMoving())
		{

			if (_matches)
			{
				DoMatching(*_matches);
			}
			else
			{
				GemSocketMatchList matches;
				_scene.GetBoard().FindMatches(matches);
				DoMatching(matches);
			}

		}

		_scene.SetTimer(_scene.GetTimer() - elapsed);
		if (_scene.GetTimer() <= 0)
			return nullptr;
		_scene.GetBoard().Update(elapsed);
		return &_scene;
	}


}
