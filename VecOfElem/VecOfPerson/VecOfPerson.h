#pragma once
#include "../../Floor/Floor.h"

class VecOfPerson {
private:
    int _quantity = 0;
    const Floor &_floor;
public:
    int start_quantity;
    std::vector <IPerson*> persons;


    VecOfPerson(const Floor &floor);
    int getQuantity() const;
    void del(int ind);
};


