#include"gamescene.h"
#include"function.h"
#include "IObject.h"
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
    //delete mapManager;
    nodelay(stdscr, false);
    endwin();
}

// initialise the game window
void GameScene::InitGameWindow()
{
    initscr(); // initialise the screen
    start_color();
    init_pair(1,COLOR_BLACK , COLOR_WHITE);
    attron(COLOR_PAIR(1));
    wbkgd(stdscr , COLOR_PAIR(1));
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);                  // initialise the keyboard: we can use arrows for directions
    noecho();                              // user input is not displayed on the screen
    curs_set(0);                           // cursor symbol is not not displayed on the screen (Linux)
    getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
    return;
}

void GameScene::EndGameWinow()
{
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
}

bool isclear() {
    if(menu->isclear == true)
        menu->isclear = false;
        return true;
    
    return false;
}

void GameScene::Update(float eTime)
{

    if (isclear())
    {
        stage->delaytime -= 25000;
        stage->nowStage++;
        if(stage->nowStage == 3){
          EndGameWinow();
        }
        ChangeScene(new GameScene());
    }

    mysnake->movesnake(eTime);

    if(mysnake->isDied == true){
      ChangeScene(new GameOver());
    }
    mysnake->PushData();

    me->SetTotalScore(stage->nowStage);
    menu->Update(eTime);
    itemmanager->Update(eTime);
    usleep(stage->delaytime);
}

void GameScene::Render()

{   menu->Render();
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
