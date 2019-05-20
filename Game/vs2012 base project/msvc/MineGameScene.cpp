#include <sstream>
#include <iomanip>
#include "MineGameScene.h"
#include "GemFactory.h"
#include "FillingMineGameSceneState.h"

namespace minegame
{
	
	MineGameScene::MineGameScene(ISpriteFactory* f) :_spriteFactory(f), _board(new GemFactory(f), 8, 8), _scoreSprite(nullptr), _score(0), _scoreText("0"), _timer(0.0f)
	{
		_bgSprite = _spriteFactory->GetSprite(SpriteType::BACKGROUND);
		_scoreSprite.reset(_spriteFactory->GetTextSprite(_scoreText));
		_timerSprite.reset(_spriteFactory->GetTextSprite(_timerText));
		SetX(0);
		SetY(0);
		SetTimer(60.0f);
		_nextState = (new FillingMineGameSceneState(*this));
	}

	void MineGameScene::SwapStates()
	{
		if (_nextState)
		{
			if(_currentState)
				_currentState->LeaveState();
			_currentState.reset(_nextState);
			_nextState = nullptr;
			_currentState->EnterState();
		}

	}


	int MineGameScene::GetScore()
	{
		return _score;
	}

	void MineGameScene::AddScore(int pts)
	{
		_score += pts;
		_scoreText.assign(std::to_string(_score));
	}

	float MineGameScene::GetTimer()
	{
		return _timer;
	}

	void MineGameScene::SetTimer(float v)
	{
		std::stringstream ss;

		_timer = v;
		ss <<std::fixed << std::setprecision(2) << _timer;
		_timerText.assign(ss.str());
	}
	

	//338, 90
	void  MineGameScene::SetX(float x)
	{
		_posX = x;
		_board.SetX(_posX + 316);
	}

	void  MineGameScene::SetY(float y)
	{
		_posY = y;
		_board.SetY(_posY + 90);
	}

	void  MineGameScene::SetRotation(float r)
	{
	}

	void  MineGameScene::Draw()
	{
		if (_currentState)
		_currentState->Draw();
	}

	void  MineGameScene::Enter()
	{
		if(_currentState)
			_currentState->Enter();
	}

	void MineGameScene::Leave()
	{
		if (_currentState)
		_currentState->Leave();
	}

	IScene* minegame::MineGameScene::Update(float elapsed)
	{
		SwapStates();

		if (_currentState)
			return _currentState->Update( elapsed);
		return nullptr;
	}



	const ISprite * MineGameScene::GetBackgroundSprite() const
	{
		return _bgSprite;
	}

	const ISprite * MineGameScene::GetScoreSprite() const
	{
		return _scoreSprite.get();
	}

	const ISprite * MineGameScene::GetTimerSprite() const
	{
		return _timerSprite.get();
	}

	Board & MineGameScene::GetBoard()
	{
		return _board;
	}

	void MineGameScene::SetState(MineGameSceneState * ns)
	{
		_nextState = ns;

	}

	int MineGameScene::GetWidth() const
	{
		return _bgSprite->GetWidth();
	}

	int MineGameScene::GetHeight() const
	{
		return _bgSprite->GetHeight();
	}

	float MineGameScene::GetX() const
	{
		return _posX;
	}

	float MineGameScene::GetY() const
	{
		return _posY;
	}

	float MineGameScene::GetRotation() const
	{
		return 0.0f;
	}

}
