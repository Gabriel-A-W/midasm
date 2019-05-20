#include "IdleMineGameSceneState.h"
#include "MatchingMineGameSceneState.h"
#include "Mouse.h"
namespace minegame
{
	 

	IdleMineGameSceneState::~IdleMineGameSceneState()
	{
	}

	void IdleMineGameSceneState::EnterState()
	{
	}

	void IdleMineGameSceneState::LeaveState()
	{
	}

	void IdleMineGameSceneState::Enter()
	{
	}

	void IdleMineGameSceneState::Leave()
	{
	}

	IScene * IdleMineGameSceneState::Update(float elapsed)
	{
		Mouse& m = Mouse::GetInstance();
		Board& board = _scene.GetBoard();

		if (!board.IsMoving())
		{
			if (m.IsLeftButtonDown())
			{
				if (!_mouseButtonWasDown)
				{
					_prevSock = board.GetAtPos(m.GetX(), m.GetY());
					_mouseButtonWasDown = _prevSock != nullptr;
				}
				else
				{
					
					GemSocket* csock = board.GetAtPos(m.GetX(), m.GetY());

					if (csock && csock != _prevSock)
					{
						int dc = csock->GetColumn();
						int dr = csock->GetRow();
						int pc = _prevSock->GetColumn();
						int pr = _prevSock->GetRow();

						int hv = std::abs(dc - pc);
						int vv = std::abs(dr - pr);
						_mouseButtonWasDown = false;

						if ( (hv == 1 && vv == 0) || (vv == 1 && hv == 0))
						{
							board.Swap(_prevSock, csock);

							std::unique_ptr<GemSocketMatchList> ml( new GemSocketMatchList());

							board.FindMatches(*ml);
							if (ml->size() > 0)
							{
								_scene.SetState(new MatchingMineGameSceneState(_scene, ml.release()));
							}
							else
							{
								board.Swap(_prevSock, csock);
								
							}

						}

					}
				}

			}
		}
		
		

		_scene.SetTimer(_scene.GetTimer() - elapsed);
		if (_scene.GetTimer() <= 0)
			return nullptr;
		_scene.GetBoard().Update(elapsed);
	
		return &_scene;
	}



}

