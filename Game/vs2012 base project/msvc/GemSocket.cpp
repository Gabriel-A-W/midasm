#include "GemSocket.h"
#include "MineConstants.h"

namespace minegame
{


	GemSocket::GemSocket() : _gem(), _posX(0), _posY(0), _row(0), _column(0)
	{
	}


	GemSocket::~GemSocket()
	{
	}

	void  GemSocket::Draw()
	{
		Gem* g = GetGem();
		if (g)
			g->Draw();

	}

	void  GemSocket::Update(float elapsed)
	{
		Gem* g = GetGem();
		if (g)
			g->Update(elapsed);
	}


	void GemSocket::SetGem(Gem * gem)
	{

		_gem.release();
		if (gem)
		{
			_gem.reset( gem);
			_gem->SetDestX(GetX() + GEMSOCK_WO);
			_gem->SetDestY(GetY() + GEMSOCK_HO);

		}

	}

	int GemSocket::GetWidth() const
	{
		return GEMSOCK_W;
	}
	int GemSocket::GetHeight() const
	{
		return GEMSOCK_H;
	}
	float GemSocket::GetX() const
	{
		return _posX;
	}
	float GemSocket::GetY() const
	{
		return _posY;
	}
	float GemSocket::GetRotation() const
	{
		return 0;
	}
	void GemSocket::SetX(float x)
	{
		_posX = x;
	}
	void GemSocket::SetY(float y)
	{
		_posY = y;
	}
	void GemSocket::SetRotation(float r)
	{
	}
}