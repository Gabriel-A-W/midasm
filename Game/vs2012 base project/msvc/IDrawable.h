#pragma once

namespace minegame
{


	class IDrawable
	{
	public:
		virtual  int GetWidth() const = 0;
		virtual  int GetHeight() const = 0;
		virtual  float GetX() const = 0;
		virtual  float GetY() const = 0;
		virtual  float GetRotation() const = 0;

		virtual  void SetX(float x)  = 0;
		virtual  void SetY(float y)  = 0;
		virtual  void SetRotation(float r)  = 0;


		virtual bool IsPointInside(float x, float y) const
		{
			float bx = GetX();
			float by = GetY();
			float dx = GetX() + GetWidth();
			float dy = GetY() + GetHeight();

			return (x > bx && y > by && x < dx && y < dy);
		}

		virtual void Draw() = 0;
		virtual ~IDrawable() {};


	};
}
