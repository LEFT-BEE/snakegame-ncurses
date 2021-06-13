#include"snake.h"
#include"item.h"
extern itemManager *itemmanager;
extern MapManager * mapManager;
extern Position Gate1;
extern Position Gate2;


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
     snake.push_back(snakepart((maxwidth/2)+i, (maxheight/2)));
   }
   grow = false;
   dok = false;
   fast = false;

   //초기방향 : left
   direction = 'l';
   srand(time(0));
   //makeitem();
   //snake data clear
   for(int i = 0; i<snake.size(); i++){
    mapManager->PatchData(snake[i].y , snake[i].x , 'x');
  }
}
snakeclass::~snakeclass(){}

bool snakeclass::collision() // get item? or get die?
{
    if(snake[0].x == 0 || snake[0].x == maxwidth-1 || snake[0].y ==0 || snake[0].y == maxheight-2) return true;
    if(mapManager->data[snake[0].y][snake[0].x] == '1'){ return true;}
    if(mapManager->data[snake[0].y][snake[0].x] == '2'){ return true;}
    //gate에 충돌시
    if(mapManager->data[snake[0].y][snake[0].x] == '8'){ return false;}
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
      dok = true;
    }
    else{
      dok = false;
    }
    if(mapManager->data[snake[0].y][snake[0].x] == '6'){
      itemmanager->deleteitem(snake[0].y , snake[0].x);
      grow = true;
    }
    else{
      grow = false;
    }
    if(mapManager->data[snake[0].y][snake[0].x] == '7'){
      itemmanager->deleteitem(snake[0].y , snake[0].x);
      fast = true;
    }
    else{
      fast = false;
    }
// // 게이트에 들어갔을 때 -gate1 진입시
if(mapManager->data[snake[0].y][snake[0].x] == '8'){
    mapManager->data[Gate2.y][Gate2.x]='3';
    if (snake[0].y == Gate1.y && snake[0].x == Gate1.x){

      if (Gate2.x == 1){
        direction = 'r';
        mapManager->PatchData(Gate2.y, Gate2.x + 1, 'x');
        // snake[0].x = Gate2.x + 1;
        // snake[0].y = Gate2.y;
      }
      else{
        direction = 'l';
        mapManager->PatchData(Gate2.y, Gate2.x - 1, 'x');
        // snake[0].x = Gate2.x - 1;
        // snake[0].y = Gate2.y;
          }
      }
//gate2 진입시
    else if (snake[0].y == Gate2.y && snake[0].x == Gate2.x){
      if (Gate1.y == 1){
        direction = 'd';
        mapManager->PatchData(Gate1.y + 1, Gate1.x, 'x');
        // snake[0].x = Gate1.x;
        // snake[0].y = Gate1.y + 1;
      }
      else{
        direction = 'u';
        mapManager->PatchData(Gate1.y - 1, Gate1.x, 'x');
        // snake[0].x = Gate1.x;
        // snake[0].y = Gate1.y - 1;
        }
    }
}
}

void snakeclass::PushData(){
  if(!grow)//add len
  {
      mapManager->PatchData(snake[snake.size()-1].y , snake[snake.size()-1].x , '0');
      snake.pop_back();
  }

  if(dok)
  {
    mapManager->PatchData(snake[snake.size()-1].y , snake[snake.size()-1].x , '0');
    snake.pop_back();
  }
  if(fast)
  {
    while(1){
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if(mapManager->data[y][x] == '0'){
            mapManager->PatchData(y ,x , '2');
            mapManager->PatchData(y-1 ,x , '2');
            mapManager->PatchData(y ,x+1 , '2');
            mapManager->PatchData(y-1 ,x+1 , '2');
            break;
        }
    }
  }

  if(snake.size()<3) isDied = true;
  if(!isDied)
      mapManager->PatchData(snake[0].y , snake[0].x , 'x');
}
