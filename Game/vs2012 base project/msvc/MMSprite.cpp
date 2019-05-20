#include "MMSprite.h"

namespace minegame
{



	MMSprite::~MMSprite()
	{
	}

	int MMSprite::GetWidth() const
	{
		return _engine->GetTextureWidth(_texture);
	}

	int MMSprite::GetHeight() const
	{
		return _engine->GetTextureHeight(_texture);
	}

	void MMSprite::Render(float x, float y, float rotation) const
	{
		_engine->Render(_texture, x, y, rotation);

	}


}

