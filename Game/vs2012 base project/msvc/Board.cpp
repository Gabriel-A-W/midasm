#include <list>
#include <iostream>
#include <functional>
#include <utility>
#include "Board.h"
#include "RandomUtils.h"
#include "GemFactory.h"

namespace minegame
{
	Board::Board(GemFactory* gf, int width, int height, float x, float y) : _gemFactory(gf), _columns(width), _rows(height), _posX(x), _posY(y), _socketMatrix(height, GemSocketRow(width))
	{
		int w = 0;
		int h = 0;
		for (h = 0; h < _rows; h++)
		{
			for (w = 0; w < _columns; w++)
			{
				GemSocket* sock = new GemSocket();
				_socketMatrix[h][w] = sock;
				
				sock->SetRow(h);
				sock->SetColumn(w);
				sock->SetX(GetX() + (w * sock->GetWidth())  + 1 );
				sock->SetY(GetY() + (h * sock->GetHeight()) + 1 );
			}
		}
	
	}
	 

	Board::~Board()
	{
		int w = 0;
		int h = 0;
		for (h = 0; h < _rows; h++)
		{
			for (w = 0; w < _columns; w++)
			{
				 
				delete _socketMatrix[h][w];
				 
			}
		}
	}


	int Board::GetColumnCount() const
	{
		return _columns;
	}

	int Board::GetRowCount() const
	{
		return _rows;
	}

	GemSocket* Board::GetAt(int row, int col) const
	{
		return _socketMatrix[row][col];
	}


	GemSocket* Board::GetAbove(GemSocket& context) const
	{
		GemSocket* rv = nullptr;
		if (context.GetRow() < (GetColumnCount() - 1))
		{
			rv = GetAt(context.GetRow() + 1, context.GetColumn());
		}

		return rv;
	}

	GemSocket* Board::GetLeft(GemSocket& context) const
	{
		GemSocket* rv = nullptr;
		if (context.GetColumn() > 0)
		{
			rv = GetAt(context.GetRow(), context.GetColumn() - 1);
		}

		return rv;
	}


	const GemFactory* Board::GetGemFactory() const
	{
		return _gemFactory.get();
	}

	void Board::CreateRandomGemFor(GemSocket* sock)
	{
		 

		std::vector<IGemBuilder*> vals;
		GetGemFactory()->GetBuilders(&vals);
	
		
		if (sock->GetColumn() > 0)
		{
			Gem* g = GetLeft(*sock)->GetGem();
			if (g)
			{
				auto eltr = std::find_if(vals.begin(), vals.end(), [g](IGemBuilder*& builder) {

					return builder->Builds(g);
				});


				if (eltr != vals.end())
					vals.erase(eltr);

			}
				
		}

		GemSocket* uppr = GetAbove(*sock);
		if (uppr && uppr->GetGem())
		{
			Gem* g = uppr->GetGem();
			auto eltr = std::find_if(vals.begin(), vals.end(), [g](IGemBuilder*& builder) { return builder->Builds(g); });
			if(eltr != vals.end())
				vals.erase(eltr);
		}

		Gem* result = vals[RandomUtils::GetInstance().Get(0, vals.size() - 1)]->Build();
		result->SetX(sock->GetX());
		result->SetY(sock->GetY() - (result->GetHeight()) );

		sock->SetGem(result);
		
	}


	void Board::Update(float elapsed)
	{
		

		for (GemSocketMatrix::iterator mit = _socketMatrix.begin(); mit != _socketMatrix.end(); ++mit)
		{
			for (GemSocketRow::iterator rit = (*mit).begin(); rit != (*mit).end(); ++rit)
			{
				(*rit)->Update(elapsed);
			}

		}


	}

	void Board::Draw()
	{
		for (GemSocketMatrix::iterator mit = _socketMatrix.begin(); mit != _socketMatrix.end(); ++mit)
		{
			for (GemSocketRow::iterator rit = (*mit).begin(); rit != (*mit).end(); ++rit)
			{
				(*rit)->Draw();
			}

		}
	}




	

	GemSocket* Board::GetAtPos(float x, float y) const
	{
		 
		
		for (GemSocketMatrix::const_iterator mit = _socketMatrix.begin(); mit != _socketMatrix.end(); ++mit)
		{
			for (GemSocketRow::const_iterator rit = (*mit).begin(); rit != (*mit).end(); ++rit)
			{
				if ((*rit)->IsPointInside(x, y))
					return (*rit);
			}

		}
		return nullptr;
	}

	bool Board::RandomFill()
	{
		int x = 0;
		int y = 0;
		bool swapDone = false;

		for (x = GetRowCount() - 1; x >= 0; x--)
		{
			for (y = 0; y <  GetColumnCount(); y++)
			{
				GemSocket* sock = GetAt(x, y);
				if (!sock->GetGem())
				{
					if (x == 0)
					{
						CreateRandomGemFor(sock);
					}
					else
					{
						Swap(sock, GetAt(x - 1, y));
						swapDone = true;
					}
				}
			}
		}

		if (swapDone)
			return RandomFill();
	
		return swapDone;
	}

	bool Board::IsMoving() const
	{
		int w = 0;
		int h = 0;
		for (h = 0; h < _rows; h++)
		{
			for (w = 0; w < _columns; w++)
			{
				Gem* g = _socketMatrix[h][w]->GetGem();
				if (g && g->IsMoving())
				{
					return true;
				}
				
				 
			}
		}
		return false;
	}



	


	bool Board::FindVerticalMatches(GemSocketMatchList& matches)
	{

		 int col = 0;
		 int n = 0;
		 int row = 0;
		bool rv = false;
		std::function<bool(Gem*, Gem*)> gemEquals = [](Gem* a, Gem* b) { return (a && b) && *a == *b; };

		for (col = 0; col < GetColumnCount(); col++)
		{
			row = 0;
			while (row < GetRowCount() - 2)
			{
				for (n = row + 1; n < GetRowCount() && gemEquals(GetAt(row, col)->GetGem(), GetAt(n, col)->GetGem()); n++);
				if ((n - row) >= 3)
				{
					std::list<GemSocket*> chain;
					for ( int i = row; i < n; i++)
					{
						chain.push_back(GetAt(i, col));
					}
					matches.push_back(std::move(chain));
					rv = true; 
				}
				row += n - row;
			}

		}


		return rv;
	}

	bool Board::FindHorizontalMatches(GemSocketMatchList&  matches)
	{
		 int col = 0;
		 int n = 0;
		bool rv = false;
		std::function<bool(Gem*, Gem*)> gemEquals = [](Gem* a, Gem* b) { return (a && b) && *a == *b; };

		for ( int row = 0; row < GetRowCount(); row++)
		{
			col = 0;
			n = 0;


			while (col < GetColumnCount() - 2)
			{
				for (n = col + 1; n < GetColumnCount() && gemEquals(GetAt(row, col)->GetGem(), GetAt(row, n)->GetGem()); n++);

				if ((n - col) >= 3)
				{
					std::list<GemSocket*> chain;
					for ( int i = col; i < n; i++)
					{
						chain.push_back(GetAt(row, i));
					}
					matches.push_back(std::move(chain));
					rv = true;
				}
				col += n - col;
			}
		}


		return rv;
	}


	bool Board::FindMatches(GemSocketMatchList& matches)
	{
		bool ver = FindVerticalMatches(matches);
		bool hor = FindHorizontalMatches(matches);
		return ver || hor;
	}

	void Board::Swap(GemSocket* sockFrom, GemSocket* sockTo)
	{
		Gem* fgem = sockFrom->GetGem();
		if (!fgem && !sockTo->GetGem())
			return;
		sockFrom->SetGem(sockTo->GetGem());
		sockTo->SetGem(fgem);

	}

	int Board::GetWidth() const
	{
		return 0;
	}

	int Board::GetHeight() const
	{
		return 0;
	}

	float Board::GetX() const
	{
		return _posX;
	}

	float Board::GetY() const
	{
		return _posY;
	}

	float Board::GetRotation() const
	{
		return 0;
	}

	void Board::SetX(float x)
	{
		_posX = x;
		int w = 0;
		int h = 0;
		for (h = 0; h < _rows; h++)
		{
			for (w = 0; w < _columns; w++)
			{
				GemSocket* sock = _socketMatrix[h][w];

				sock->SetX(GetX() + (w * sock->GetWidth()) + 1);
			}
		}
	}

	void Board::SetY(float y)
	{
		_posY = y;
		int w = 0;
		int h = 0;
		for (h = 0; h < _rows; h++)
		{
			for (w = 0; w < _columns; w++)
			{
				GemSocket* sock = _socketMatrix[h][w];
				 
				sock->SetY(GetY() + (h * sock->GetHeight()) + 1);
			}
		}

	}

	void Board::SetRotation(float r)
	{
	}


	


}