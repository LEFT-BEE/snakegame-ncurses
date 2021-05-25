#include"item.h"
cell itemManager::getrnadpos(){

        srand(tile(NULL)); 
        cell iteminfo;
        CharPosition pos;

        while(1){
            int v = rand() % 2;
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;

            if(MapManager->data[y][x] == 0){
                pos.x = x;
                pos.y =y;

                iteminfo.tmp = pos;
                iteminfo.val = v;
                return iteminfo
            }
        }
}

void itemManager::update(){
}

void itemManager::setitem(){
    start_time = clock();
    cell pos = getrnadpos();
    int v = pos.val;
    CharPosition itempos = pos.tmp;
    if(v ==1)
        char item_val = '3';  //3 은 독을의미함
    else
        char item_val = '4'; //4는 기프트를 의미함


    MapManager.patchData(tmp.y , tmp.x , item_val);

}



