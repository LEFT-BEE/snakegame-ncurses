//@author Leeminji(20173416)

#pragma once
#include <ncurses.h>
#include <vector>
#include <string.h>
#include <cstdlib>





class MENU
{

public:
    int maxheight, maxwidth, digitTime;
    MENU();
    ~MENU();
    bool clear;
    void Update(float eTime);
    void Render();

    char Complete(int present, int goal);
    void DrawScore();
    void DrawMission();
};
