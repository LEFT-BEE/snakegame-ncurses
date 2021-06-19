/*
@author Hanseungjin(20181512)
@author Leeminji(20173416)
@author Chaejiyun(20191313)

*/

#include"gamescene.h"
#include"function.h"
#include "stage.h"
#include"snake.h"
#include <ncurses.h>
#include <unistd.h>
#include<ctime>
#include<cstdlib>
#include"gameoverscene.h"



using namespace std;
extern Stage* stage;
MapManager* mapManager;
itemManager *itemmanager;
Player * me;
MENU *menu;
snakeclass * mysnake;

GameScene::GameScene()
{

    srand(time(NULL));
    me = new Player();
    mapManager = new MapManager();
    mapManager->Load();

    mysnake = new snakeclass();
    itemmanager = new itemManager();
    menu  = new MENU();

    InitGameWindow();
    refresh();
}

GameScene::~GameScene()
{
    nodelay(stdscr, false);
    endwin();
}


void GameScene::InitGameWindow()
{
    initscr();
    start_color();
    init_pair(1,COLOR_BLACK , COLOR_WHITE);
    attron(COLOR_PAIR(1));
    wbkgd(stdscr , COLOR_PAIR(1));
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, maxheight, maxwidth);
    return;
}

void GameScene::EndGameWinow()
{
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
}


void GameScene::Update(float eTime)
{
    mysnake->movesnake(eTime);

    if(mysnake->isDied == true){
      ChangeScene(new GameOver());
    }
    mysnake->PushData();

    me->SetTotalScore(stage->nowStage);
    menu->Update(eTime);
    itemmanager->Update(eTime);


    if (menu->clear)
    {
        stage->nowStage++;
        if(stage->nowStage == 4){
          EndGameWinow();
        }
        stage->delaytime -= 20000;
        mapManager = new MapManager();
        mapManager->Load();
        mysnake = new snakeclass();
        me = new Player();
        menu  = new MENU();

        InitGameWindow();
        refresh();
    }

    usleep(stage->delaytime);
}

void GameScene::Render()

{

    menu->Render();
    start_color();
    WINDOW*wall;
    init_pair(2 , COLOR_BLACK , COLOR_BLACK);
    init_pair(3 , COLOR_RED , COLOR_RED);
    init_pair(4 , COLOR_BLUE , COLOR_BLUE);
    init_pair(5 , COLOR_GREEN , COLOR_GREEN);
    init_pair(6,COLOR_YELLOW , COLOR_YELLOW);
    init_pair(7 , COLOR_MAGENTA , COLOR_MAGENTA);
    init_pair(8 , COLOR_CYAN , COLOR_CYAN);


    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            switch (mapManager->data[i][j])
            {
            case '0':
                mvaddch(i, j, ' ');
                break;
            case '1':
                  attron(COLOR_PAIR(2));
            			mvprintw(i, j," ");
            			attroff(COLOR_PAIR(2));
                break;
            case '2':
                  attron(COLOR_PAIR(3));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(3));
                break;
            case 'x':
                  attron(COLOR_PAIR(4));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(4));
                break;
            case '4':
                mvaddch(i, j, 'x');
                break;
            case '5':
                  attron(COLOR_PAIR(5));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(5));
                break;
            case '6':
                  attron(COLOR_PAIR(6));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(6));
                break;
            case '7':
                  attron(COLOR_PAIR(7));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(7));
                break;
            case '8':
                  attron(COLOR_PAIR(8));
                  mvprintw(i, j," ");
                  attroff(COLOR_PAIR(8));
            }
        }
    }

    refresh();
}
