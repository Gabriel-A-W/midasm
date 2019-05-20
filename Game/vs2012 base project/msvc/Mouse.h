#pragma once
#include <king/Engine.h>


namespace minegame
{
	class Mouse
	{
	private:
		Mouse();
		King::Engine* _engine;
		King::Engine* GetEngine() const;

	public:
		static Mouse& GetInstance()
		{
			static Mouse _instance;
			return _instance;
		}

		void Initialize(King::Engine* engine);

		float GetX() const;
		float GetY() const;
		float IsLeftButtonDown() const;

		~Mouse();
	};




}
