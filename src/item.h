/*
@author Hanseungjin(20181512)
@author Chaejiyun(20191313)
@author Leeminji(20173416)
*/

#include <vector>
#include <cstdlib>
#include "make_map.h"
#include "myposition.h"
#include <ncurses.h>
#include <string>
#include <vector>
#include<ctime>

struct Position{
  int y;
  int x;
};
class item
{
public:
  string type = "none";
  myposition position;
  myposition getrnadpos();
  item(string type_):type(type_)
    {
      myposition temp = getrnadpos();
      position.x = temp.x;
      position.y = temp.y;
    }
  ~item(){};
};


class itemManager
{

public:
    int maxheight, maxwidth;
    vector<item> data;
    float lastDropTime;
    float lastGateTime;
    itemManager();
    ~itemManager(){};
    void Update(float eTime);
    bool istimeover(float eTIme);
    bool gatetimeover(float eTime);
    void pushdata();
    void itemtype(std::string check, float eTime);
    void deleteitem(int y, int x);
    void MakeGate();
    void DeleteGate();


    float start_time , end_time;
};
