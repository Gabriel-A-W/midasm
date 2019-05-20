#define GLM_FORCE_RADIANS 
#include <iostream>
#include <king/Engine.h>
#include <king/Updater.h>

#include "../msvc/MineGame.h"

//**********************************************************************
/*
class ExampleGame : public King::Updater {
public:

	ExampleGame()
		: mEngine("./assets")
		,_sfactory(new minegame::MMSpriteFactory(&mEngine))
		,gema(_sfactory->GetSprite(minegame::SpriteType::YELLOW), minegame::GemType::YELLOW)
		, mRotation(0.0f)
		, mYellowDiamondX(100.0f)
		, mYellowDiamondY(100.0f)
		, mYellowDiamondXDest(650.0f)
		, mYellowDiamondYDest(450.0f)

	{
	}

	void Start() {
	
		gema.SetX(100.0f);
		gema.SetY(100.0f);
		gema.SetDestX(650.0f);
		gema.SetDestY(450.0f);
		gema.SetSpeed(50.0f);
		mEngine.Start(*this);
		 

	}

	void Update() {
		mEngine.Render(King::Engine::TEXTURE_GREEN, 650.0f, 100.0f);
		mEngine.Render(King::Engine::TEXTURE_RED, 100.0f, 450.0f);
		mEngine.Render(King::Engine::TEXTURE_BLUE, 650.0f, 450.0f);

		mEngine.Write("Green", 650.0f, 140.0f);
		mEngine.Write("Red", 100.0f, 490.0f);
		mEngine.Write("Blue", 650.0f, 490.0f);

		const char text[] = "This rotates at 5/PI Hz";
		mRotation += mEngine.GetLastFrameSeconds();
		mEngine.Write(text, mEngine.GetWidth() / 2.0f, mEngine.GetHeight() / 2.0f, mRotation * 2.5f);

		if (mYellowDiamondXDest > mYellowDiamondX)
		{
			mYellowDiamondX += 20 * mEngine.GetLastFrameSeconds();
		}

		if (mYellowDiamondYDest > mYellowDiamondY)
		{
			mYellowDiamondY += 20 * mEngine.GetLastFrameSeconds();
		}

		if (mEngine.GetMouseButtonDown()) {
		//	mYellowDiamondX = mEngine.GetMouseX();
			//mYellowDiamondY = mEngine.GetMouseY();
		}
		gema.Update(mEngine.GetLastFrameSeconds());
		gema.Draw();
		//mEngine.Write("Click to", mYellowDiamondX, mYellowDiamondY + 40.0f);
	//	mEngine.Write("move me!", mYellowDiamondX, mYellowDiamondY + 70.0f);
	}

private:
	std::unique_ptr<minegame::ISpriteFactory> _sfactory;
 
	King::Engine mEngine;
	minegame::Gem gema;
	float mRotation;
	float mYellowDiamondX;
	float mYellowDiamondY;
	float mYellowDiamondXDest;
	float mYellowDiamondYDest;
};
*/
//**********************************************************************

int main(int argc, char *argv[]) {

	//King::Engine mEngine("./assets");
	//std::unique_ptr<minegame::ISpriteFactory> sfactory(new minegame::MMSpriteFactory(&mEngine));
	//minegame::GemFactory::GetInstance().Initialize(sfactory.get());
	//ExampleGame game;
	//minegame::Board b(8, 8);
	
	//b.RandomFill();
	//game.Start();

	minegame::MineGame game;
	game.Start();
	return 0;
}


