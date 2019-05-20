#include <cmath>
#include "Gem.h"
#include <iostream>
#include <limits>

namespace minegame
{

	GemType Gem::GetType() const
	{
		return _type;
	};

	bool Gem::operator== (const Gem& other) const
	{
		return _type == other.GetType();
	}

	bool Gem::IsMoving() const
	{
		return _posX != _desX || _posY != _desY;
	}

	void Gem::SetDestX(float x)
	{
		_desX = x;
	}

	void Gem::SetDestY(float y)
	{
		_desY = y;
	}

	void Gem::SetSpeed(float s)
	{
		_speed = s;
	}













	void  Gem::Update(float elapsed)
	{

		if (IsMoving())
		{

			float dx = _desX - _posX;
			float dy = _desY - _posY;
			float delta = std::sqrt(dx * dx + dy * dy);
			float f = std::numeric_limits<float>::max();
			
			if (delta > 1.0f)
			{
				const float disp = _speed * elapsed;
				f = disp / delta;
			}
			
			if (f > 1)
			{
				_posX = _desX;
				_posY = _desY;
			}
			else
			{
				_posX += dx * f;
				_posY += dy * f;
			}

			_rotation = 0;
		}

	}

	int  Gem::GetWidth() const
	{

		return _sprite? _sprite->GetWidth() : 0;
	}

	int  Gem::GetHeight() const
	{
		return _sprite? _sprite->GetHeight() : 0;
	}

	float Gem::GetX() const
	{
		return _posX;
	}

	float  Gem::GetY() const
	{
		return _posY;
	}

	float  Gem::GetRotation() const
	{
		return _rotation;
	}

	void  Gem::SetX(float x)
	{
		_posX = x;
	}

	void  Gem::SetY(float y)
	{
		_posY = y;
	}

	void  Gem::SetRotation(float r)
	{
		_rotation = r;
	}

	void Gem::Draw()
	{
		if (_sprite && _visible)
			_sprite->Render(GetX(), GetY(), GetRotation());
	}

}