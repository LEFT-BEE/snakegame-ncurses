//@author Leeminji(20173416)

#pragma once
#include <ncurses.h>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "IObject.h"




class MENU: public IObject
{

public:
    int maxheight, maxwidth, digitTime;
    const char *score[11] = {"0" ,"1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9"};
    MENU();
    ~MENU();
    bool clear;
    void Update(float eTime);
    void Render();

    char Complete(int present, int goal);
    void DrawScore();
    void DrawMission();
};
