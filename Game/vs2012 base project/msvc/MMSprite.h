#pragma once
#include"ISprite.h"
#include <king/Engine.h>

namespace minegame
{
	class MMSprite : public ISprite
	{
	public:
		MMSprite(King::Engine* engine, King::Engine::Texture texture)
		{
			this->_engine = engine;
			this->_texture = texture;
		
		}


		~MMSprite();

	private:
		King::Engine* _engine;
		King::Engine::Texture _texture;


		
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Render(float x, float y, float rotation = 0)const override;

	};


}


