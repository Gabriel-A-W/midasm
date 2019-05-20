#include <memory>
#include <utility>
#include <stdexcept> 
#include <vector>
#include "GemFactory.h"
#include "SimpleGemBuilder.h"



namespace minegame
{


	GemFactory::GemFactory(ISpriteFactory * sf) : _spriteFactory(sf)
	{
		_spriteFactory = sf;
		
		_builders.insert(std::pair<GemType, std::unique_ptr<IGemBuilder>>(GemType::BLUE,
			std::move(std::unique_ptr<IGemBuilder>(new SimpleGemBuilder(sf->GetSprite(SpriteType::BLUE), GemType::BLUE)))));
		_builders.insert(std::pair<GemType, std::unique_ptr<IGemBuilder>>(GemType::GREEN,
			std::move(std::unique_ptr<IGemBuilder>(new SimpleGemBuilder(sf->GetSprite(SpriteType::GREEN), GemType::GREEN)))));
		_builders.insert(std::pair<GemType, std::unique_ptr<IGemBuilder>>(GemType::RED,
			std::move(std::unique_ptr<IGemBuilder>(new SimpleGemBuilder(sf->GetSprite(SpriteType::RED), GemType::RED)))));
		_builders.insert(std::pair<GemType, std::unique_ptr<IGemBuilder>>(GemType::YELLOW,
			std::move(std::unique_ptr<IGemBuilder>(new SimpleGemBuilder(sf->GetSprite(SpriteType::YELLOW), GemType::YELLOW)))));
		_builders.insert(std::pair<GemType, std::unique_ptr<IGemBuilder>>(GemType::PURPLE,
			std::move(std::unique_ptr<IGemBuilder>(new SimpleGemBuilder(sf->GetSprite(SpriteType::PURPLE), GemType::PURPLE)))));
	} 



	

	Gem* GemFactory::Create(GemType t) const
	{
		IGemBuilder* builder = nullptr;

		if (_builders.count(t) > 0)
		{
			builder = _builders.at(t).get();
		}



		return builder->Build();
	}


	

	void GemFactory::GetBuilders(std::vector<IGemBuilder*>* rv) const
	{

		int i = 0;

		for (std::map<GemType, std::unique_ptr<IGemBuilder>>::const_iterator it = _builders.begin(); it != _builders.end(); ++it)
		{
			rv->push_back(it->second.get());
		}

	}


}