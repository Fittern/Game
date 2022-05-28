#pragma once

#include "../VecOfElem/VecOfPerson/VecOfPerson.h"
#include "../VecOfElem/VecOfItem/VecOfItem.h"

class Actions {
private:
    VecOfPerson& _vec;
    VecOfItem& _vecItem;
    Floor& _floor;
public:
    Actions(VecOfPerson &vec, VecOfItem& vecItem, Floor &floor);

    PAction move(PAction side);
    void movePerson(Coords new_pos, int num_of_per);
    Coords newPos(Coords now_pos, int side_of_per);
};


