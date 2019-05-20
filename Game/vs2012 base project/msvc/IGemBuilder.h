#pragma once
#include "Gem.h"

namespace minegame
{
	class IGemBuilder
	{
	public:
		virtual bool Builds(Gem* g) = 0;
		virtual Gem* Build() = 0;
		virtual ~IGemBuilder() {};
	};


}
