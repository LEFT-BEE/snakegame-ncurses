//@author Hanseungjin(20181512)

#include"make_map.h"
#include"stage.h"
#include<string.h>
extern Stage* stage;


MapManager::MapManager()
{
}

void MapManager::Load()
{

    std::ifstream readFile;
    std::string src = "map/map" + std::to_string(stage->getNowStage() + 1) + ".txt";

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int i = 0; i < WIDTH; i++)
        {
            data[height][i] = temp[i];
        }

        height++;
    }


    if(stage->getNowStage() == 3){
      for (int i = 6; i < WIDTH-6; i++)
      {
          data[9][i] = '1';
      }
      for (int i = 6; i < WIDTH-6; i++)
      {
          data[18][i] = '1';
      }
      for (int i = 6; i < WIDTH-6; i++)
      {
          data[27][i] = '1';
      }
    }

}



void* MapManager::GetData()
{
    return data;
}

void MapManager::PatchData(int y, int x, char patchData)
{
    data[y][x] = patchData;
}

MapManager::~MapManager()
{
}
