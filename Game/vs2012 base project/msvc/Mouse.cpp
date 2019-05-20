#include "Mouse.h"
#include <stdexcept>
namespace minegame
{
	Mouse::Mouse() : _engine(nullptr)
	{
	}

	King::Engine* Mouse::GetEngine() const
	{
		if (!_engine)
			throw std::runtime_error("Mouse not init");
		return _engine;
	}


	void Mouse::Initialize(King::Engine* engine)
	{
		_engine = engine;

	}

	float Mouse::GetX() const
	{

		return GetEngine()->GetMouseX();
	}

	float Mouse::GetY() const
	{
		return GetEngine()->GetMouseY();
	}

	float Mouse::IsLeftButtonDown() const
	{
		return GetEngine()->GetMouseButtonDown();
	}

	Mouse::~Mouse()
	{
	}



}

