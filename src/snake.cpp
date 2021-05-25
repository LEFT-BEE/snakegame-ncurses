#include"gamescene.h"
#include"function"


class SnakeManager(){

    bool isgrow  =false;
    
    int direc;
    dequeue<cell> snake;

    SnakeManager(cell startpoint){
        snake.push_back(startpoint));
    }

    ~SnakeManager();

    int head_now(){
        return data[snake.front().tmp.y][snake.front().tmp.x]
    }

    void addtail(){ //꼬리에 데이터 추가
        //이후 움직일떄 마지막 데이터 삭제 안해줘도 됨
        isgrow = true;
    }

    void removetail(){

        snake.pop_back();
    }

    void map_push_data(){ // 최종ㅈ적으로 실행되어야 하는 함수 -특히 이동한후 map에 들어가야함!!!!
        for (cell elem : snake){
            MapManager.patchData(elem.y , elem.x , '5');
        }
    
    }
    

    bool is_dead(){
        if(snake.size() < 3)
            return true;
        
        int head_x = snake.front.x;
        int head_y = snake.front.y;

        for(int i=1; i < snake.size(); i ++) // 계속 완성안함

    }

    void 

};