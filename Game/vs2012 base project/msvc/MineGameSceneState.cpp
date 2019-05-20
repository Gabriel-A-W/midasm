#include "MineGameSceneState.h"

namespace minegame
{



	void MineGameSceneState::Draw() const
	{

		_scene.GetBackgroundSprite()->Render(_scene.GetX(), _scene.GetY());
		_scene.GetScoreSprite()->Render(_scene.GetX() + 20, _scene.GetY() + 10);
		_scene.GetTimerSprite()->Render(_scene.GetX() + 75, _scene.GetY() + 450);
		_scene.GetBoard().Draw();
	}

}