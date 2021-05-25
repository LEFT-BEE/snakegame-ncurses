#include<iostream>
#include<ncurses.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

#define WIDTH 62
#define HEIGHT 32

struct CharPosition
{
	int x, y;
	CharPosition(int col, int row) : x(col), y(row) {}
	CharPosition() : x(0), y(0) {}
};

class cell(){
public:
    CharPosition tmp;
    char val;
    cell(CharPosition newtmp , char value):tmp(newtmp) , val(value){}
}


class MapManager : public IObject
{
public:
	char data[HEIGHT][WIDTH];

	float lastDropTime = 0;

	MapManager();
	~MapManager();

	void Render();
	void Update(float eTime);

	void* GetData();

	void PatchData(int y, int x, char patchData);
	void Load();
};
