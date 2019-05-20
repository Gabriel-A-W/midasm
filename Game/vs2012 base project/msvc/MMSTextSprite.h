#pragma once
#include <string>
#include "ISprite.h"
#include <king/Engine.h>


namespace minegame
{
	class MMSTextSprite : public ISprite
	{
	private:
		King::Engine* _engine;
		std::string& _text;
		float _width;
	public:
		MMSTextSprite(King::Engine* engine, std::string& txt);
		~MMSTextSprite();

		// Inherited via ISprite
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Render(float x, float y, float rotation = 0) const override;
	};



}
