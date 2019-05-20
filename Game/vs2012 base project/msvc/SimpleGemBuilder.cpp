#include "SimpleGemBuilder.h"

namespace minegame
{
	 
	 

	bool minegame::SimpleGemBuilder::Builds(Gem * g)
	{
		return g->GetType() == _type;
	}

	Gem * minegame::SimpleGemBuilder::Build()
	{
		return new Gem(_sprite, _type);
	}



}
