#pragma once
#include "../../Floor/Floor.h"

class VecOfItem {
private:
    int _quantity = 0;
    const Floor &_floor;
public:
    std::vector <IItem*> items;


    VecOfItem(const Floor &floor);
    int getQuantity() const;
    void del(int ind);
};



