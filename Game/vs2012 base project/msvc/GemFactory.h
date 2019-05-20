#pragma once

#include <stdexcept> 
#include <map>
#include <vector>
#include <memory>
#include "ISpriteFactory.h"
#include "Gem.h"
#include "IGemBuilder.h"


namespace minegame
{

	
	class GemFactory
	{
	private:
		
		ISpriteFactory* _spriteFactory;
		std::map<GemType, std::unique_ptr<IGemBuilder>> _builders;

	public:

		 
		GemFactory(ISpriteFactory* sf) ;
		 
		void GetBuilders(std::vector<IGemBuilder*>* rv) const;

		Gem* Create(GemType t) const ;

		~GemFactory() {};
	};

}