#include "MineGame.h"
#include "Mouse.h"
#include "GemFactory.h"
#include "MineGameScene.h"

namespace minegame
{
	MineGame::MineGame() : _engine("./assets"), _spriteFactory(&_engine)
	{
	}


	MineGame::~MineGame()
	{
	}

	void MineGame::Start()
	{
		Mouse::GetInstance().Initialize(&_engine);
		
		_currentScene.reset(new MineGameScene(&_spriteFactory));
		_currentScene->SetX(static_cast<float>((_engine.GetWidth() - _currentScene->GetWidth()) / 2));
		_currentScene->Enter();
		_engine.Start(*this);

	}

	void MineGame::Update()
	{
	
		
		if (_currentScene)
		{
			IScene* ns = _currentScene->Update(_engine.GetLastFrameSeconds());


			if (ns)
			{
				if (ns != _currentScene.get())
				{
					_currentScene->Leave();
					_currentScene.reset(ns);
					_currentScene->Enter();
				}
				else
				{
					_currentScene->Draw();
				}
				
				
			}
			else
			{
				_engine.Quit();
			}

		}

	}

}


