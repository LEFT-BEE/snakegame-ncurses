#include <iostream>
using namespace std;

struct Position{
  int y;
  int x;
};


void Snake::MakeGate()
{
  struct Position Gate1,Gate2;
  int GateNow=0;
  int Gatecnt=0;

  Gate1.y=rand()%WIDTH;
  if(Gate1.y>(WIDTH/2)) Gate1.y=WIDTH-1;
  else Gate1.y=2;
  Gate1.x=rand()%HEIGHT; //가로 방향 게이트 랜덤 생성

  Gate2.y=rand()%WIDTH; //세로 방향 게이트 랜덤 생성
  Gate2.x=rand()%HEIGHT;
  if(Gate2.x>(HEIGHT/2)) Gate2.x=HEIGHT-1;
  else Gate2.x=2;

  mapManager->data[Gate1.x][Gate1.y]='5';//게이트 케이스 5라고 줌
  mapManager->data[Gate2.x][Gate2.y]='5';

}

void Snake::RemoveGate{
  mapManager->data[Gate1.x][Gate1.y]='1';
  mapManager->data[Gate2.x][Gate2.y]='1';

}
