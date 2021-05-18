#include"make_map.h"
#include"stage.h"
#include<string.h>
extern Stage* stage;
//----------------------------------------------------------------------

MapManager::MapManager() // load txt file. named stageName. ex) 1.txt 2.txt 3.txt 4.txt
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

void MapManager::Render()
{
}

void MapManager::Update(float eTime)
{
}
