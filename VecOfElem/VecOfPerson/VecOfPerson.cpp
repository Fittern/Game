//
// Created by denis on 27.11.2021.
//

#include "VecOfPerson.h"

VecOfPerson::VecOfPerson(const Floor &floor) : _floor(floor) {
    for (int i = 1; i < _floor.height - 1; ++i) {
        for (int j = 1; j < _floor.width - 1; ++j) {
            if (_floor.cells[i][j]->getElem()) {
                if (_floor.cells[i][j]->getElem()->getType() != Type_of_elem::ITEM) {
                    if (_quantity > 0){
                        ((Enemy*)(_floor.cells[i][j]->getElem()))->ip = _quantity;
                    }
                    _quantity++;
                    persons.push_back((IPerson*)(_floor.cells[i][j]->getElem()));
                }
            }
        }
    }
    std::cout << _quantity << std::endl;
}

int VecOfPerson::getQuantity() const {
    return _quantity;
}

void VecOfPerson::del(int ind) {
    ((Enemy*)persons[ind])->setDead();
    for (int i = ind + 1; i < _quantity; ++i) {
        ((Enemy*)persons[i])->ip--;
        persons[i-1] = persons[i];
    }
    _quantity--;
}
