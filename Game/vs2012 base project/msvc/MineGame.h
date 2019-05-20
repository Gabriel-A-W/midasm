#pragma once
#include <memory>
#include <king/Updater.h>
#include <king/Engine.h>
#include "IScene.h"
#include "MMSpriteFactory.h"


namespace minegame
{
	class MineGame : public King::Updater
	{
	public:
		MineGame();
		~MineGame();

		void Start();

	private:
		std::unique_ptr<IScene> _currentScene;
		King::Engine _engine;
		MMSpriteFactory _spriteFactory;

		// Inherited via Updater
		virtual void Update() override;
	};




}
