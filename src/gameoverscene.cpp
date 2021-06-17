//@author Hanseungjin


#include "IScene.h"
#include "gamescene.h"
#include "startscene.h"
#include"gameoverscene.h"
#include <ncurses.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>


GameOver::GameOver(){}
GameOver::~GameOver(){}

void GameOver::Update(float eTime){
  refresh();
  load();
  char answer =is_restart();

  if(answer=='y'){
    ChangeScene(new startscene());
  }
  else if(answer == 'n'){
    exit(0);
  }
}


void GameOver::load(){
    std::ifstream readFile;
    string path = "scene/GameOverScene.txt";

    readFile.open(path);
    int height = 0;
    while(!readFile.eof()){
      char map[120];
      readFile.getline(map , 120);

      for(int width = 0; width < 58; width++){
        if(map[width] == ' ')
        {
          move(height+2 , width +2);
          addch(' ');
        }
        else
        {
          move(height+2 , width+2);
          addch(char(219));
        }
      }
      height++;
    }

}
int GameOver::UserInput(){
  int userinput;
  userinput = getch();
  endwin();
  clear();
  return userinput;
}

void GameOver::ClearScreen(float x, float y)
{
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);
    move((maxheight / 3 * 2 / y), (maxwidth / x));
}


int GameOver::is_restart(){
  ClearScreen(3.5 ,2);
  move(25 ,65);
  printw("if (YOU WANT TO TRY AGAIN){");
  move(26 , 66);
  printw("PRESS 'y'}");
  move(28,65);
  printw("else{");
  move(29,66);
  printw("PRESS 'n'}");
  return UserInput();

}
