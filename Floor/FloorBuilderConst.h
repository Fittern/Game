#pragma once

#include "FloorBuilder.h"
#include <cstdlib>

class FloorBuilderConst : public FloorBuilder{
private:
    Floor* floor;
    MyTexture now_texture;

public:
    FloorBuilderConst(MyTexture texture);
    ~FloorBuilderConst();

    //void setNowTexture(MyTexture texture);
    void GeneratNormalCells() override;
    void GeneratWallCells() override;
    void GeneratEntryCell() override;
    void GeneratExitCell() override;

    void GeneratItems() override;

    void GeneratPlayer() override;

    void GeneratEnemy() override;

    void Reset();
    Floor* getFloor() override;
};
