#pragma once
#include <memory>
#include <string>
#include"ISpriteFactory.h"
#include "MMSprite.h"


namespace minegame
{
	class MMSpriteFactory : public ISpriteFactory
	{
	private:
		King::Engine* _engine;
		std::unique_ptr<MMSprite> _sprites[static_cast<int>(SpriteType::MAX)];
		
	
	public:
		MMSpriteFactory(King::Engine* engine);

		~MMSpriteFactory();

		// Inherited via ISpriteFactory
		virtual ISprite* GetSprite(SpriteType t) const override;
		virtual ISprite* GetTextSprite(std::string& txt) const override;

	

		

	};


}

