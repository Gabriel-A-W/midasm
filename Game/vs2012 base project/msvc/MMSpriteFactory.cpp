#include "MMSpriteFactory.h"
#include "MMSTextSprite.h"

namespace minegame
{

	MMSpriteFactory::MMSpriteFactory(King::Engine* engine):_engine(engine)
	{
		_sprites[static_cast<int>(SpriteType::BACKGROUND)].reset(new MMSprite(engine, King::Engine::TEXTURE_BACKGROUND));
		_sprites[static_cast<int>(SpriteType::BLUE)].reset(new MMSprite(engine, King::Engine::TEXTURE_BLUE));
		_sprites[static_cast<int>(SpriteType::GREEN)].reset(new MMSprite(engine, King::Engine::TEXTURE_GREEN));
		_sprites[static_cast<int>(SpriteType::PURPLE)].reset(new MMSprite(engine, King::Engine::TEXTURE_PURPLE));
		_sprites[static_cast<int>(SpriteType::RED)].reset(new MMSprite(engine, King::Engine::TEXTURE_RED));
		_sprites[static_cast<int>(SpriteType::YELLOW)].reset(new MMSprite(engine, King::Engine::TEXTURE_YELLOW));



	}


	MMSpriteFactory::~MMSpriteFactory()
	{
	}

	ISprite* minegame::MMSpriteFactory::GetSprite(SpriteType t) const
	{
		return (_sprites[static_cast<int>(t)]).get();
	}

	ISprite * MMSpriteFactory::GetTextSprite(std::string & txt) const
	{
		return new MMSTextSprite(_engine, txt);
	}

}