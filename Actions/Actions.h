#pragma once

#include "../VecOfElem/VecOfPerson/VecOfPerson.h"

class Actions {
private:
    VecOfPerson& _vec;
    Floor& _floor;
public:
    Actions(VecOfPerson &vec, Floor &floor);

    PAction move(PAction side);
    void movePerson(Coords new_pos, int num_of_per);
    Coords newPos(Coords now_pos, int side_of_per);
};


