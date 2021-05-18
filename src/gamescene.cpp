#include"gamescene.h"
#include"function.h"
#include "IObject.h"
#include "stage.h"
#include <ncurses.h>
#include <unistd.h>



using namespace std;
extern Stage* stage;
using int32 = int;
MapManager* mapManager;


GameScene::GameScene()
{
    srand(time(NULL));

    //mapManager�� ���� ��������������
    mapManager = new MapManager();
    mapManager->Load();

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
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);                  // initialise the keyboard: we can use arrows for directions
    noecho();                              // user input is not displayed on the screen
    curs_set(0);                           // cursor symbol is not not displayed on the screen (Linux)
    getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
    return;
}

bool isclear() {
    printw("nextmap key is f1  ");
    int ch;
    ch = getch();
    if (ch == KEY_F(1))
        return true;
  
    return false;
}

void GameScene::Update(float eTime)
{
    //���⿡�� chagneScene�� �ɾ��ش�.
    if (isclear())
    {
        stage->nowStage++;
        ChangeScene(new GameScene());
    }

    usleep(150000);
}

void GameScene::Render()
{


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
                mvaddch(i, j, '-');
                break;
            case '2':
                mvaddch(i, j, 'X');
                break;
            case '3':
                mvaddch(i, j, 'H');
                break;
            case '4':
                mvaddch(i, j, 'B');
                break;
            case '5':
                mvaddch(i, j, 'G');
                break;
            case '6':
                mvaddch(i, j, 'P');
                break;
            case '7':
                mvaddch(i, j, '?');
                break;
            case '8':
                mvaddch(i, j, ' ');
            }
        }
    }

    refresh();
}

// draw the game window

// // print score at bottom of window
// void GameScene::PrintScore()
// {
// 	move(maxheight-1, 0);
// 	printw("Score: %d", score);
// 	return;
// }

// void GameScene::PlayGame()
// {
//     while(1)
//     {
//         if (FatalCollision())
//         {
//             move((maxheight-2)/2,(maxwidth-5)/2);
//             printw("GAME OVER");
//             break;
//         }

//         Update();
//         Render();

//         if (direction=='q') //exit
//         {
//         	break;
//         }

//         usleep(500); // delay
//     }
// }
