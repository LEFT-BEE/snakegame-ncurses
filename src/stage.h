//@author Hanseungjin(20181512)
#include "IObject.h"
class Stage
{
int mission[4][4] = {
		{1, 1, 1, 1},
		{1, 2, 2, 2},
		{1, 2, 3, 3},
		{1, 3, 1, 3}
	};


public:
	int nowStage;
	int delaytime;
	bool clear;

	Stage();
	~Stage();

	int getNowStage() { return nowStage; }
	int* getNowMission(){return mission[nowStage]; }

};
