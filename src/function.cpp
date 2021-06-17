//@author Hanseungjin(20181512)

#include"function.h"
#include"gamescene.h"
#include"startscene.h"


IScene* nowScene;


int currentWidth;
int currentHeight;

std::chrono::steady_clock::time_point startTime;

void Init()
{
	startTime = std::chrono::steady_clock::now();

	nowScene = new startscene();
}

void Update(float eTime)
{
	nowScene->Update(eTime);
}

void Render()
{
	nowScene->Render();
}

void Destroy()
{
	delete nowScene;
}
// �����ð� �ޱ�
float GetElapsedTime()
{
	auto endTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed_seconds = endTime - startTime;
	float eTime = (float)elapsed_seconds.count();
	return eTime;
}

void ChangeScene(IScene* p, bool nowSceneErase)
{
	if (nowSceneErase)
		delete nowScene;
	nowScene = p;
}
