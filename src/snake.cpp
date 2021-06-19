/*
@author Hanseungjin(20181512)
@author Chaejiyun(20191313)
@author Leeminji(2017)
*/

#include"snake.h"
#include"item.h"
#include"score.h"
extern itemManager *itemmanager;
extern MapManager * mapManager;
extern Player *me;

extern Position Gate1;
extern Position Gate2;
extern bool gateflag;


snakepart::snakepart(int col, int row)
{
    x = col;
    y = row;
}

snakepart::snakepart()
{
    x=0;
    y=0;
}
snakeclass::snakeclass()
{

   getmaxyx(stdscr, maxheight, maxwidth);
   for(int i=0; i<3; i++){
     snake.push_back(snakepart(20+i, 20));
   }
   grow = false;
   poison = false;
   biggift = false;

   //초기방향 : left
   direction = 'l';
   srand(time(0));
   for(int i = 0; i<snake.size(); i++){
    mapManager->PatchData(snake[i].y , snake[i].x , 'x');
  }
}
snakeclass::~snakeclass(){}

bool snakeclass::collision() // get item? or get die?
{

    if(mapManager->data[snake[0].y][snake[0].x] == '1'){ return true;}
    if(mapManager->data[snake[0].y][snake[0].x] == '2'){ return true;}
    //snakebody에 snakehead 닿을 시 충돌
    for(int i =2; i<snake.size(); i++){
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y) return true;
    }
    return false;
}

void snakeclass::movesnake(float eTime)
{   int tmp;
    tmp = getch();
    switch(tmp)
    {
        case KEY_LEFT:
            if(direction!='r')
                direction = 'l';
            else isDied = true;
            break;
        case KEY_UP:
            if(direction!='d')
                direction = 'u';
            else isDied = true;
            break;
        case KEY_DOWN:
            if(direction!='u')
                direction = 'd';
            else isDied = true;
            break;
        case KEY_RIGHT:
            if(direction!='l')
                direction = 'r';
            else isDied = true;
            break;
    }
    if(!isDied)
    {
        if(direction=='l')
            snake.insert(snake.begin(),snakepart(snake[0].x-1,snake[0].y));
        else if(direction=='r')
            snake.insert(snake.begin(),snakepart(snake[0].x+1,snake[0].y));
        else if(direction=='u')
            snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y-1));
        else if(direction=='d')
            snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y+1));

    }
    if(collision() == true){isDied = true;}

    if(mapManager->data[snake[0].y][snake[0].x] == '5'){
      itemmanager->deleteitem(snake[0].y , snake[0].x);
      me->SetPoisonScore(me->poisonScore + 1);
      me->SetLengthScore(me->lengthScore - 1);
      poison = true;
    }
    else{
      poison = false;
    }
    if(mapManager->data[snake[0].y][snake[0].x] == '6'){
      itemmanager->deleteitem(snake[0].y , snake[0].x);
      me->SetGrowScore(me->growScore + 1);
      me->SetLengthScore(me->lengthScore + 1);
      grow = true;
    }
    else{
      grow = false;
    }
    if(mapManager->data[snake[0].y][snake[0].x] == '7'){
      itemmanager->deleteitem(snake[0].y , snake[0].x);
      me->SetGrowScore(me->growScore + 1);
      me->SetLengthScore(me->lengthScore + 1);
      biggift = true;
      grow = true;
    }
    else{
      biggift = false;
    }

    //gate
    if(mapManager->data[snake[0].y][snake[0].x] == '8'){
        gateflag=true; //gate통과중 표시 ->게이트 생성 정지
        me->SetGateScore(me->gateScore + 1);
        if (snake[0].y == Gate1.y && snake[0].x == Gate1.x){

          if (Gate2.x == 1){
            direction = 'r';
            snake[0].x = Gate2.x + 1;
            snake[0].y = Gate2.y;
            mapManager->PatchData(snake[0].y , snake[0].x , 'x');
          }
          else{
            direction = 'l';
            snake[0].x = Gate2.x - 1;
            snake[0].y = Gate2.y;
            mapManager->PatchData(snake[0].y , snake[0].x , 'x');
              }
          }
    //gate2 진입시
        else if (snake[0].y == Gate2.y && snake[0].x == Gate2.x){
          if (Gate1.y == 1){
            direction = 'd';
            snake[0].x = Gate1.x;
            snake[0].y = Gate1.y + 1;
            mapManager->PatchData(snake[0].y , snake[0].x , 'x');
          }
          else{
            direction = 'u';
            snake[0].x = Gate1.x;
            snake[0].y = Gate1.y - 1;
            mapManager->PatchData(snake[0].y , snake[0].x , 'x');
            }
        }
    }
    gateflag=false;
}

void snakeclass::PushData(){
  if(!grow)//add len
  {
      mapManager->PatchData(snake[snake.size()-1].y , snake[snake.size()-1].x , '0');
      snake.pop_back();
  }

  if(poison)
  {
    mapManager->PatchData(snake[snake.size()-1].y , snake[snake.size()-1].x , '0');
    snake.pop_back();
  }
  if(biggift)
  {
    while(1){
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if(mapManager->data[y][x] == '0'){
            mapManager->PatchData(y ,x , '1');
            mapManager->PatchData(y-1 ,x , '1');
            mapManager->PatchData(y ,x+1 , '1');
            mapManager->PatchData(y-1 ,x+1 , '1');
            break;
        }
    }
  }

  if(snake.size()<3) isDied = true;
  if(!isDied)
      mapManager->PatchData(snake[0].y , snake[0].x , 'x');
}
