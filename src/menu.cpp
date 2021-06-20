//@author Leeminji(20173416)

#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "score.h"
#include "stage.h"
#include "menu.h"
#include "gamescene.h"

using namespace std;
extern Player *me;
extern Stage *stage;



char MENU::Complete(int present, int goal)
{
    if (present >= goal)
        return 'V';
    else
        return ' ';
}


MENU::MENU()
{
    clear = false;
    getmaxyx(stdscr, maxheight, maxwidth);
}
MENU::~MENU()
{
}
void MENU::Update(float eTime)
{
      int *nowMission = stage->getNowMission();

      if (Complete(me->lengthScore, nowMission[0]) == 'V')
        clear = true;
      else
        clear = false;
}

void MENU::Render()
{
    DrawScore();
    DrawMission();
}

void MENU::DrawScore()
{

    move(7, maxwidth / 5*4 -3 );
    printw("| S C O R E |");

    for (int i = 0; i < 26; i++)
    {
        move(8, maxwidth / 5 * 4 -9 + i);
        addch('-');
    }

    int totalScore = me->totalScore;
    string totalScore_str =  to_string(totalScore);
    move(10, maxwidth / 5 * 4 -3);
    printw("Score : ");
    move(10 , maxwidth / 5 * 4 +6);
    printw(totalScore_str.c_str());


    int giftScore = me->giftScore;
    string giftScore_str =  to_string(giftScore);
    move(12, maxwidth / 5 * 4 +1);
    printw("+ : ");
    move(12 , maxwidth / 5 * 4 +6);
    printw(giftScore_str.c_str());


    int poisonScore = me->poisonScore;
    string poisonScore_str =  to_string(poisonScore);
    move(14, maxwidth / 5 * 4 +1);
    printw("- : ");
    move(14 , maxwidth / 5 * 4 +6);
    printw(poisonScore_str.c_str());


    int gateScore = me->gateScore;
    string gateScore_str =  to_string(gateScore);
    move(16, maxwidth / 5 * 4 +1);
    printw("G : ");
    move(16 , maxwidth / 5 * 4 +6);
    printw(gateScore_str.c_str());

}
void MENU::DrawMission()
{
    int *nowMission = stage->getNowMission();

    move(19, maxwidth / 5 * 4 -5);
    printw("| M I S S I O N |");

    for (int i = 0; i < 26; i++)
    {
        move(20, maxwidth / 5 * 4 - 9 + i);
        addch('-');
    }

    move(22, maxwidth / 5 * 4 -4);
    printw("Length : %d/%d (%c)", me->lengthScore, nowMission[0], Complete(me->lengthScore, nowMission[0]));

    move(24, maxwidth / 5 * 4 -2);
    printw("Gift : %d/%d (%c)", me->giftScore, nowMission[1], Complete(me->giftScore, nowMission[1]));

    move(26, maxwidth / 5 * 4 -4);
    printw("Poison : %d/%d (%c)", me->poisonScore, nowMission[2], Complete(me->poisonScore, nowMission[2]));

    move(28, maxwidth / 5 * 4 -2);
    printw("Gate : %d/%d (%c)", me->gateScore, nowMission[3], Complete(me->gateScore, nowMission[3]));

}
