#include "FillingMineGameSceneState.h"
#include "MatchingMineGameSceneState.h"

namespace minegame
{
 
	void FillingMineGameSceneState::EnterState( )
	{
		_scene.GetBoard().RandomFill();
	}

	void FillingMineGameSceneState::LeaveState( )
	{
	}

	void FillingMineGameSceneState::Enter( )
	{
	}

	void FillingMineGameSceneState::Leave( )
	{
	}

	IScene * FillingMineGameSceneState::Update( float elapsed)
	{
		Board& b = _scene.GetBoard();
		_scene.SetTimer(_scene.GetTimer() - elapsed);
		if (_scene.GetTimer() <= 0)
			return nullptr;
		b.Update(elapsed);
		if (!b.IsMoving())
		{
			_scene.SetState(new MatchingMineGameSceneState(_scene));
		}
			
		return &_scene;
	}



}
	