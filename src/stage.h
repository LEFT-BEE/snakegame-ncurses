//@author Hanseungjin(20181512)
//@author Leeminji(20173416)
class Stage
{
int mission[4][4] = {
		{6, 1, 1, 1},
		{6, 2, 2, 2},
		{6, 2, 3, 3},
		{6, 3, 1, 3}
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
