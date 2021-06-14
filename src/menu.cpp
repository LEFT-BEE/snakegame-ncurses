#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "score.h"
#include "stage.h"
#include "menu.h"
using namespace std;
extern Player *me;
extern Stage *stage;

MENU::MENU()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}
MENU::~MENU()
{
}
void MENU::Update(float eTime)
{
}


void MENU::Render()
{
    //[TO-DO] 여기에서 mvaddch를 이용해서 출력해주기
    DrawScore();
    //DrawMission();
}

void MENU::DrawScore()
{

    move(7, maxwidth / 5*4 -3 );
    printw("| S C O R E |");

    for (int i = 0; i < 26; i++)
    {
        move(8, maxwidth / 5 * 4 -8 + i);
        addch('-');
    }

    int totalScore = me->totalScore;
    string totalScore_str =  to_string(totalScore);
    move(10, maxwidth / 5 * 4 +1);
    printw("B : ");
    move(10 , maxwidth / 5 * 4 +6);
    //printw("%s" , totalScore_str);

    // move(12 , 5*4+2);
    // printw("+ : ");
    // move(12 , 5*4+7);
    // printw("%s" , score[me->growScore][0]);
    //
    // move(14 , 5*4+2);
    // printw("- : ");
    // move(14 , 5*4+7);
    // printw("%s" , score[me->poisonScore][0]);
    //
    // move(16 , 5*4+2);
    // printw("G : ");
    // move(16 , 5*4+7);
    // printw("%s" ,score[me->gateScore][0]);

    for (int i = 0; i < 26; i++)
    {
        move(18, maxwidth / 5 * 4 -8 + i);
        addch('-');
    }
}



char MENU::Complete(int present, int goal)
{
    if (present >= goal)
        return 'V';
    else
        return ' ';
}

void MENU::DrawMission()
{
    int *nowMission = stage->getNowMission();

    move(maxheight / 2, maxwidth / 5 * 4 + 1);
    printw("| M I S S I O N |");

    for (int i = 0; i < 26; i++)
    {
        move(maxheight / 2 + 1, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }

    move(22, maxwidth / 5 * 4 + 4);
    printw("Length : %d/%d (%c)", me->lengthScore, nowMission[0], Complete(me->lengthScore, nowMission[0]));

    move(24, maxwidth / 5 * 4 + 4);
    printw("Gift : %d/%d (%c)", me->growScore, nowMission[1], Complete(me->growScore, nowMission[1]));

    move(26, maxwidth / 5 * 4 + 4);
    printw("Poison : %d/%d (%c)", me->poisonScore, nowMission[2], Complete(me->poisonScore, nowMission[2]));

    move(28, maxwidth / 5 * 4 + 4);
    printw("Gate : %d/%d (%c)", me->gateScore, nowMission[3], Complete(me->gateScore, nowMission[3]));

    for (int i = 0; i < 26; i++)
    {
        move(30, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }
}
