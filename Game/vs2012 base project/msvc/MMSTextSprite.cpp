#include "MMSTextSprite.h"

namespace minegame
{

	MMSTextSprite::MMSTextSprite(King::Engine* engine, std::string& txt):_engine(engine), _text(txt)
	{
		 

	}


	MMSTextSprite::~MMSTextSprite()
	{
	}

	int  MMSTextSprite::GetWidth() const
	{
		return static_cast<int>(_engine->CalculateStringWidth(_text.c_str()));
	}

	int  MMSTextSprite::GetHeight() const
	{
		return 35;
	}

	void  MMSTextSprite::Render(float x, float y, float rotation) const
	{
		_engine->Write(_text.c_str(), x, y, rotation);
	}


}
