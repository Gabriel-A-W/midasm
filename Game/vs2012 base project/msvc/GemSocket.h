#pragma once
#include <memory>
#include "IUpdateable.h"
#include "IDrawable.h"
#include "Gem.h"

namespace minegame
{

	
	class GemSocket : public IDrawable, public IUpdateable
	{
	private:
		int _row;
		int _column;
		std::unique_ptr<Gem> _gem;

		float _posX;
		float _posY;

	public:
		GemSocket( );
		~GemSocket();

		// Inherited via IDrawable
		virtual void Draw() override;

		// Inherited via IUpdateable
		virtual void Update(float elapsed) override;

		  int GetRow()
		{
			return _row;
		}
		  int GetColumn()
		{
			return _column;
		}

		 void SetRow( int row)
		{
			_row = row;
		}
		
		 void SetColumn( int col)
		{
			_column = col;
		}

		 Gem* GetGem() const
		{
			return _gem.get();
		}

		void SetGem(Gem* gem);




		// Inherited via IDrawable
		virtual int GetWidth() const override;

		virtual int GetHeight() const override;

		virtual float GetX() const override;

		virtual float GetY() const override;

		virtual float GetRotation() const override;

		virtual void SetX(float x)  override;

		virtual void SetY(float y)  override;

		virtual void SetRotation(float r)  override;

	};

}