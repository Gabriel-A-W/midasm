#pragma once
#include "ISprite.h"

namespace minegame
{
	enum struct SpriteType
	{
		BACKGROUND,
		BLUE,
		GREEN,
		PURPLE,
		RED,
		YELLOW,
		MAX
	};

	class ISpriteFactory
	{
	public:

		virtual ISprite* GetSprite(SpriteType t) const = 0;
		virtual ISprite* GetTextSprite(std::string& txt) const = 0 ;
		virtual ~ISpriteFactory() {};


	};


}
 