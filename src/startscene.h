//@author Hanseungjin(20181512)
#include "IScene.h"
#include "stage.h"
#include "function.h"
#include "gamescene.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class startscene : public IScene
{
public:
	int maxwidth, maxheight;

	startscene();
	~startscene();

	void Update(float eTime);
	void Render(){};

	void Load();
	void ClearCentre(float x, float y);
	int UserInput();
	int IsUserReady();

};
