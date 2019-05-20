#pragma once
#include "IUpdateable.h"
#include "IDrawable.h"
#include "IGemBuilder.h"
#include "GemSocket.h"
#include "GemFactory.h"
#include <vector>
#include <list>
#include <memory>


namespace minegame
{
	 

	using GemSocketRow = std::vector<GemSocket*>;
	using GemSocketMatrix = std::vector<GemSocketRow>;
	using GemSocketMatchList = std::list<std::list<GemSocket*>>;

	class Board : public IUpdateable, public IDrawable
	{
	private:
		int _columns;
		int _rows;
		
		float _posX;
		float _posY;

		GemSocketMatrix _socketMatrix;
		std::unique_ptr<GemFactory> _gemFactory;


		const GemFactory* GetGemFactory() const;
		void CreateRandomGemFor(GemSocket* sock);
		bool FindVerticalMatches(GemSocketMatchList& matches);
		bool FindHorizontalMatches(GemSocketMatchList& matches);

	public:
		Board(GemFactory* gf, int width, int height, float x = 0, float y = 0);
	//	Board() : Board(8, 8) {}
		~Board();

		int GetColumnCount() const;
		int GetRowCount() const;

		GemSocket* GetAt(int row, int col)const;
		GemSocket* GetAbove(GemSocket& context)const;
		GemSocket* GetLeft(GemSocket& context)const;
		GemSocket* GetAtPos(float x, float y) const;


		bool RandomFill();
		
		bool IsMoving() const;
		
		bool FindMatches(GemSocketMatchList& matches);
		void Swap(GemSocket* sockFrom, GemSocket* sockTo);


		
		// Inherited via IUpdateable
		virtual void Update(float elapsed) override;

		// Inherited via IDrawable
		virtual void Draw() override;
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