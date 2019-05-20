#pragma once
#include "IGemBuilder.h"
#include "Gem.h"

namespace minegame {
	class SimpleGemBuilder : public IGemBuilder
	{
	private:
		GemType _type;
		ISprite* _sprite;
	public:
		SimpleGemBuilder(ISprite* sprite, GemType t): _sprite(sprite), _type(t) {};
		~SimpleGemBuilder() {};

		// Inherited via IGemBuilder
		virtual bool Builds(Gem * g) override;
		virtual Gem * Build() override;
	};

}