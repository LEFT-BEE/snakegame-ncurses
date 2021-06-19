/*
@author Hanseungjin(20181512)
@author Chaejiyun(20191313)
@author Leeminji(20173416)
*/

#include"item.h"
#include <cstdlib>
#include <ctime>
#include <string>

extern MapManager *mapManager;
bool gateflag=false;

myposition item::getrnadpos(){

        myposition *pos = new myposition();

        while(1){
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;

            if(mapManager->data[y][x] == '0'){
                pos->x = x;
                pos->y = y;
                return *pos;
            }
        }
}

itemManager::itemManager()
{   lastDropTime =0;
    getmaxyx(stdscr, maxheight, maxwidth);
}




bool itemManager::istimeover(float eTime){
  if(eTime - lastDropTime > 5)
    return TRUE;
  return false;
}
bool itemManager::gatetimeover(float eTime){
  if(eTime - lastGateTime > 10)
    return TRUE;
  return false;
}

void itemManager::deleteitem(int y , int x){
  int target;
  for(int i=0 ; i < data.size(); i++ ){
    if(data[i].position.x == x && data[i].position.y == y){
      target = i;
      data.erase(data.begin() + target);
    }
  }
}

void itemManager::itemtype(string type , float eTime){
  if(type == "poison"){
    data.push_back(item("poison"));
  }
  else if(type == "gift"){
    data.push_back(item("gift"));
  }
  else{
    data.push_back(item("biggift"));
  }
}


void itemManager::pushdata(){
    for(int i=0; i < data.size();i++){
        if(data[i].type == "poison"){
          mapManager->PatchData(data[i].position.y , data[i].position.x , '5');
        }
        else if(data[i].type == "gift"){
          mapManager->PatchData(data[i].position.y , data[i].position.x , '6');
        }
        else if(data[i].type == "biggift"){
          mapManager->PatchData(data[i].position.y , data[i].position.x , '7');
        }
    }
}


void itemManager::Update(float eTime){

    if(istimeover(eTime)){
      for(int i=0 ; i < data.size(); i++ ){
        mapManager-> PatchData(data[i].position.y , data[i].position.x , '0');
      }
      data.clear();
      for(int i=0; i < 3; i++){
        int r = rand() % 3;
        if(r == 0)
          itemtype("poison" , eTime);
        else if(r == 1)
          itemtype("gift" , eTime);
        else{
          itemtype("biggift" , eTime);
        }

      }
      pushdata();
      lastDropTime = eTime;
    }

    if(gatetimeover(eTime)){
      if(!gateflag)
      {
        DeleteGate();
        MakeGate();
        lastGateTime = eTime;
      }
    }
}

struct Position Gate1={0,};
struct Position Gate2={0,};
int Gatecnt=0;

void itemManager::MakeGate()
{
  if(Gatecnt==0)
  {
    Gate1.y=rand()%HEIGHT;
    if(Gate1.y>(HEIGHT/2)) Gate1.y=HEIGHT-2;
    else Gate1.y=1;
    Gate1.x=rand()%(WIDTH-3);

    Gate2.y=rand()%(HEIGHT-3);
    Gate2.x=rand()%WIDTH;
    if(Gate2.x>(WIDTH/2)) Gate2.x=WIDTH-;
    else Gate2.x=1;

    mapManager->PatchData(Gate1.y ,Gate1.x , '8');
    Gatecnt++;
    mapManager->PatchData(Gate2.y ,Gate2.x , '8');
    Gatecnt++;
  }
}

void itemManager::DeleteGate()
{
  if(Gatecnt==2)
  {
    mapManager->PatchData(Gate1.y ,Gate1.x , '1');
    Gatecnt--;

    mapManager->PatchData(Gate2.y ,Gate2.x , '1');
    Gatecnt--;
  }
}
