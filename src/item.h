#include"gamescene.h"
#include<"function.h"
#include<ctime>
#include<srand>

class itemManager():public IObject{
    itemManager();
    ~itemManager();
    getrnadpos();
    Update();
    
    float start_time , end_time;    
}

