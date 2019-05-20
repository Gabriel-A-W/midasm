#pragma once
#include "IUpdateable.h"
#include "IDrawable.h"
#include "ISprite.h"
#include "GemType.h"
#include "MineConstants.h"

namespace minegame
{

	class Gem : public IUpdateable, public IDrawable
	{


	private:
		ISprite* _sprite;
		GemType _type;

		float _posX;
		float _posY;
		float _rotation;


		float _desX;
		float _desY;
		float _speed;

		bool _visible;

	public:
		Gem(ISprite* sprite, GemType type) : _sprite(sprite), _visible(true), _type(type), _posX(0), _posY(0), _desX(0), _desY(0), _speed(GEM_SPEED), _rotation(0) {};
		~Gem() {};

		GemType GetType() const;

		bool operator== (const Gem& other) const;

		bool IsMoving() const;

		void SetDestX(float x);

		void SetDestY(float y);

		void SetSpeed(float s);

		// Inherited via IUpdateable
		virtual void Update(float elapsed) override;


		// Inherited via IDrawable
		virtual int GetWidth() const override;

		virtual int GetHeight() const override;

		virtual float GetX() const override;

		virtual float GetY() const override;

		virtual float GetRotation() const override;

		virtual void SetX(float x) override;

		virtual void SetY(float y) override;

		virtual void SetRotation(float r) override;

		virtual void Draw() override;





	};
}