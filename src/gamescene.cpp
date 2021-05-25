#include"gamescene.h"
#include"function.h"
#include "IObject.h"
#include "stage.h"
#include"item.h"
#include<score.h>
#include <ncurses.h>
#include <unistd.h>
#include<ctime>



using namespace std;
extern Stage* stage;
player * me;
MapManager* mapManager;
itemManager* itemmanager;
SnakeManager* Snake;

GameScene::GameScene()
{
    srand(time(NULL));

    mapManager = new MapManager();
    mapManager->Load();
    itemmanager = new itemManager();
    itemmanager.setitem();
    me = new player();
    me.lengthScore++;

    CharPosition start = new CharPosition(1,2);
    cell startpoint2(start , '5');
    snake = new SnakeManager(startpoint2);

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
    int y ,x;
    printw("\n");
    getyx(stdscr , y ,x);

    mvprintw(y+1 , 20, "nextmap key is f1  ");
    int ch;
    ch = getch();
    if (ch == KEY_F(1))
        return true;

    return false;
}

void GameScene::Update(float eTime)
{

    if (isclear())
    {
        stage->nowStage++;
        if(stage->nowStage == 3){
          EndGameWinow();
        }
        ChangeScene(new GameScene());
    }

    player->SetTotalScore(stage->nowStage);

    //1. snake 이동값 받기
    // 2. head의 상태에 따라 snake몸통 update
    int now_status = Snake.now_status();
    float itemmanager.end_time = clock();

    if(itemmanager.end_time - itemmanager.start_time > 5){
        itemmanager.setitem();
    }

    
    if(now_status== 3){ // 0은 하나 줄어드는 경우임)
        Snake.removetail();
        itemmanager.setitem();
        score.poisonScore++;
    }

    else if(now_status == 4){
        Snake.addtail();
        itemmanager.setitem();
        score.growScore++;
    }

    //3. snake renderring하기
    Snake.map_push_data();
    score.lengthScore++;

`
    usleep(150000);
}

void GameScene::Render()
{
    start_color();
    WINDOW*wall;
    init_pair(2 , COLOR_BLACK , COLOR_BLACK);
    init_pair(3 , COLOR_RED , COLOR_RED);

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
            case '3':
                mvaddch(i, j, 'A');
                break;
            case '4':
                mvaddch(i, j, 'B');
                break;
            case '5':
                mvaddch(i, j, 'C');
                break;
            case '6':
                mvaddch(i, j, 'D');
                break;
            case '7':
                mvaddch(i, j, 'E');
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
