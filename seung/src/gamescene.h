#pragma once
#include <cstdlib>
#include <ctime>
#include"IScene.h"
#include"item.h"
#include"menu.h"
#include"score.h"


class GameScene : public IScene
{
public:
	int score;
	int maxwidth, maxheight;
	GameScene();
	~GameScene();
	bool isChangeScene;
	void InitGameWindow();
	void EndGameWinow();
	void Update(float eTime);
	void Render();

};
