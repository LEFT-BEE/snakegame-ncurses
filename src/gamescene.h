#pragma once
#include <cstdlib>
#include <ctime>
#include "make_map.h"
#include"IScene.h"


using int32 = int;

class GameScene : public IScene
{
public:
	int32 score;
	int32 maxwidth, maxheight;

	char edgechar;

	GameScene();
	~GameScene();
	bool isChangeScene;

	void InitGameWindow();
	void Update(float eTime);
	void Render();

};
