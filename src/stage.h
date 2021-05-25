#include "IObject.h"
class Stage : public IObject
{
int mission[3][4] = {
		{6, 1, 1, 1},
		{6, 2, 2, 2},
		{6, 2, 3, 3},
	};


public:
	int nowStage;
	bool clear;

	Stage();
	~Stage();

	int getNowStage() { return nowStage; }
	int* getNowMission(){return mission[nowStage]; }
	void setNowStage(int nowStage) { this->nowStage = nowStage;}
	void Update(float eTime);

	void Render();
};
