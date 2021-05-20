#pragma once
#include <cstdlib>
#include <ctime>
#include "make_map.h"
#include"IScene.h"

class GameScene : public IScene
{
public:
	int score;
	int maxwidth, maxheight;

	char edgechar;
	GameScene();
	~GameScene();
	bool isChangeScene;

	void InitGameWindow();
	void EndGameWinow();
	void Update(float eTime);
	void Render();

};
