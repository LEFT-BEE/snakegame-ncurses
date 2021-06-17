//@author Hanseungjin


#pragma once
#include"IScene.h"
#include <ncurses.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

class GameOver:public IScene{

public:
  int maxwidth , maxheight;

  GameOver();
  ~GameOver();

  void ClearScreen(float x , float y);
  int UserInput();
  int is_restart();
  void load();
  void Render(){};
	void Update(float eTime);

};
