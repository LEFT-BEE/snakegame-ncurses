#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "function.h"

int maxheight, maxwidth;

int main()
{
	Init();
	do
	{
		Update(GetElapsedTime());
		Render();
	} while (true);
	Destroy();
	return 0;
}
