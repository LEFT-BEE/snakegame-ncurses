//@author Hanseungjin(20181512)

#include<iostream>
#include<ncurses.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include "function.h"
#include "IScene.h"


#define WIDTH 62
#define HEIGHT 32

class MapManager
{
public:
	char data[HEIGHT][WIDTH];

	float lastDropTime = 0;

	MapManager();
	~MapManager();
	void* GetData();
	void PatchData(int y, int x, char patchData);
	void Load();
};
