#pragma once
#include <string>
#include "ISpriteFactory.h"
#include "IScene.h"
#include "Board.h"
#include "MineGameSceneState.h"

namespace minegame
{
	class MineGameSceneState;
	class MineGameScene : public IScene
	{
	private:
		Board _board;
		ISpriteFactory* _spriteFactory;
		ISprite* _bgSprite;
		
		std::unique_ptr<MineGameSceneState> _currentState;
		MineGameSceneState* _nextState;
		int _score;
		std::string _scoreText;
		std::unique_ptr<ISprite> _scoreSprite;

		float _timer;
		std::string _timerText;
		std::unique_ptr<ISprite> _timerSprite;

		void SwapStates();

	public:
		MineGameScene(ISpriteFactory* f);
		~MineGameScene() {};

		int GetScore();
		void AddScore(int pts);
		float GetTimer();
		void SetTimer(float v);
		

		const ISprite* GetBackgroundSprite() const;
		const ISprite* GetScoreSprite() const;
		const ISprite* GetTimerSprite() const;
		Board& GetBoard();

		void SetState(MineGameSceneState* ns);

		// Inherited via IScene
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual float GetX() const override;
		virtual float GetY() const override;
		virtual float GetRotation() const override;
		virtual void SetX(float x) override;
		virtual void SetY(float y) override;
		virtual void SetRotation(float r) override;
		virtual void Draw() override;
		virtual void Enter() override;
		virtual void Leave() override;
		virtual IScene * Update(float elapsed) override;

	};


}

