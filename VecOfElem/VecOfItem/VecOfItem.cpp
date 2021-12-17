//
// Created by denis on 27.11.2021.
//

#include "VecOfItem.h"

VecOfItem::VecOfItem(const Floor &floor) : _floor(floor) {
    for (int i = 1; i < _floor.height - 1; ++i) {
        for (int j = 1; j < _floor.width - 1; ++j) {
            if (_floor.cells[i][j]->getElem()) {
                if (_floor.cells[i][j]->getElem()->getType() == Type_of_elem::ITEM) {
                    ((IItem*)(_floor.cells[i][j]->getElem()))->setId(_quantity);
                    _quantity++;
                    items.push_back((IItem*)(_floor.cells[i][j]->getElem()));
                }
            }
        }
    }
    //std::cout << _quantity << std::endl;
}

int VecOfItem::getQuantity() const {
    return _quantity;
}


void VecOfItem::del(int ind) {
    items[ind]->setDead();
    for (int i = ind + 1; i < _quantity; ++i) {
        ((IItem*)items[i])->setId(((IItem*)items[i])->getId() - 1);
        items[i-1] = items[i];
    }
    _quantity--;
}
