#pragma once
namespace minegame
{
	class ISprite
	{
	public:

		virtual  int GetWidth() const = 0;
		virtual  int GetHeight() const = 0;
		virtual void Render(float x, float y, float rotation = 0) const = 0;
 
		virtual ~ISprite() { };
	};


}

