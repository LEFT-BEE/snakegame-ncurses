#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Player.h"
#include "Stage.h"
#include "menu.h"

extern Player *player;
extern Stage *stage;

Format::Format()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}
Format::~Format()
{
}



void Format::Render()
{
    //[TO-DO] 여기에서 mvaddch를 이용해서 출력해주기
    DrawScore();
    DrawMission();
}

void Format::DrawScore()
{

    move(7, maxwidth / 5 * 4 + 4);
    printw("| S C O R E |");

    for (int i = 0; i < 26; i++)
    {
        move(8, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }

    int totalScore = player->totalScore;

 
    move(10, maxwidth / 5 * 4 +2);
    printw("B : ");
    mvprintw(10 ,5*4+7  , player->lengthScore);
    mvprintw(10 ,5*4+8  , 10);

    mvprintw(11 ,5*4+2  , "+ : ");
    mvprintw(10 ,5*4+7  , player->growScore);

    mvprintw(11 ,5*4+2  , "- : ");
    mvprintw(10 ,5*4+7  , player->poisonScore);

    mvprintw(11 ,5*4+2  , "G : ");
    mvprintw(10 ,5*4+7  , player->gateScore);  

    for (int i = 0; i < 26; i++)
    {
        move(18, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }
}



char Format::Complete(int present, int goal)
{
    if (present >= goal)
        return 'V';
    else
        return ' ';
}

void Format::DrawMission()
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
    printw("Length : %d/%d (%c)", player->lengthScore, nowMission[0], Complete(player->lengthScore, nowMission[0]));

    move(24, maxwidth / 5 * 4 + 4);
    printw("Gift : %d/%d (%c)", player->growScore, nowMission[1], Complete(player->growScore, nowMission[1]));

    move(26, maxwidth / 5 * 4 + 4);
    printw("Poison : %d/%d (%c)", player->poisonScore, nowMission[2], Complete(player->poisonScore, nowMission[2]));

    move(28, maxwidth / 5 * 4 + 4);
    printw("Gate : %d/%d (%c)", player->gateScore, nowMission[3], Complete(player->gateScore, nowMission[3]));

    for (int i = 0; i < 26; i++)
    {
        move(30, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }
}