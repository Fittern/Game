#pragma once
#include "../Floor/Floor.h"
#include "../VecOfElem/VecOfPerson/VecOfPerson.h"
#include "../VecOfElem/VecOfItem/VecOfItem.h"
#include <fstream>

class Save {
private:
    //const Floor* floor;
    //const int rule1;
    //int rule2;
    //const std::string& filename;
public:
    static void SaveG(Floor* floor, int rule1, int rule2, VecOfItem* vecI, VecOfPerson* vecP, const std::string& filename="/home/denis/CLionProjects/Game/Serialization/save.txt");
    static int WriteG(Floor *floor_en, int rule1, int rule2, VecOfItem* vecI, VecOfPerson* vecP, const std::string& filename="/home/denis/CLionProjects/Game/Serialization/save.txt");
};
