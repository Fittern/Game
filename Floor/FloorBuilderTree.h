#pragma once

#include "FloorBuilder.h"
#include <cstdlib>

class FloorBuilderTree : public FloorBuilder{
private:
    Floor* floor;
    MyTexture now_texture;

public:
    FloorBuilderTree(MyTexture texture);
    ~FloorBuilderTree();

    //void setNowTexture(MyTexture texture);
    void GeneratNormalCells() override;
    void GeneratWallCells() override;
    void GeneratWallDungeonCells(int x1, int y1, int x2, int y2, int** mass);
    void GeneratEntryCell() override;
    void GeneratExitCell() override;

    void GeneratItems() override;

    void GeneratPlayer() override;

    void GeneratEnemy() override;

    void Reset();
    Floor* getFloor();
};
