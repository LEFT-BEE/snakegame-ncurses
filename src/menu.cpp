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

MENU::MENU()
{
    getmaxyx(stdscr, maxheight, maxwidth);
    isclear = false;
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

    
    int growScore = me->growScore;
    string growScore_str =  to_string(growScore);
    move(12, maxwidth / 5 * 4 +1);
    printw("+ : ");
    move(12 , maxwidth / 5 * 4 +6);
    printw(growScore_str.c_str());

    
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
    printw("Gift : %d/%d (%c)", me->growScore, nowMission[1], Complete(me->growScore, nowMission[1]));

    move(26, maxwidth / 5 * 4 -4);
    printw("Poison : %d/%d (%c)", me->poisonScore, nowMission[2], Complete(me->poisonScore, nowMission[2]));

    move(28, maxwidth / 5 * 4 -2);
    printw("Gate : %d/%d (%c)", me->gateScore, nowMission[3], Complete(me->gateScore, nowMission[3]));

    if (Complete(me->lengthScore, nowMission[0]) == 'V' && Complete(me->lengthScore, nowMission[1]) == 'V' &&
        Complete(me->lengthScore, nowMission[2]) == 'V' && Complete(me->lengthScore, nowMission[3]) == 'V')
        isclear = true;
}
