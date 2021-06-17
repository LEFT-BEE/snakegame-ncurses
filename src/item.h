/*
@author Hanseungjin(20181512)
@author Chaejiyun(20191313)
*/

#include <vector>
#include <cstdlib>
#include "make_map.h"
#include "IObject.h"
#include "CharPosition.h"
#include <ncurses.h>
#include <string>
#include <vector>
#include<ctime>

struct Position{
  int y;
  int x;
};
class item:public IObject
{
public:
  string type = "none";
  CharPosition position;
  CharPosition getrnadpos();
  item(string type_):type(type_)
    {
      CharPosition temp = getrnadpos();
      position.x = temp.x;
      position.y = temp.y;
    }
  ~item(){};
  void Update(float eTime){};
  void Render(){};
};


class itemManager:public IObject
{

public:
    int maxheight, maxwidth;
    vector<item> data;
    float lastDropTime;
    float lastGateTime;
    itemManager();
    ~itemManager(){};
    void Update(float eTime);
    void Render(){};
    bool istimeover(float eTIme);
    bool gatetimeover(float eTime);
    void pushdata();
    void itemtype(std::string check, float eTime);
    void deleteitem(int y, int x);
    void MakeGate();
    void DeleteGate();


    float start_time , end_time;
};
