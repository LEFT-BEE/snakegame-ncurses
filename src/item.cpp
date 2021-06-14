#include"item.h"
#include <cstdlib>
#include <ctime>
#include <string>

extern MapManager *mapManager;

CharPosition item::getrnadpos(){

        CharPosition *pos = new CharPosition();

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





}
