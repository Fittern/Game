#pragma once

#include "Floor.h"

class FloorBuilder {
public:
    virtual void GeneratNormalCells() = 0;
    virtual void GeneratWallCells() = 0;
    virtual void GeneratEntryCell() = 0;
    virtual void GeneratExitCell() = 0;

    virtual void GeneratItems() = 0;

    virtual void GeneratPlayer() = 0;

    virtual void GeneratEnemy() = 0;
};