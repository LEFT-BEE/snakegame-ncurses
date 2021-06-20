//@author Hanseungjin(20181512)
//@author Leeminji(20173416)
class Stage
{
int mission[4][4] = {
		{1, 6, 6, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1}
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
