//
// Created by denis on 27.11.2021.
//

#include "Actions.h"

Actions::Actions(VecOfPerson &vec, VecOfItem& vecItem, Floor &floor) : _vec(vec), _vecItem(vecItem) , _floor(floor) {}

PAction Actions::move(PAction side) {
    ((Player*)(_vec.persons[0]))->setSide(side);
    for (int i = 0; i < _vec.getQuantity(); ++i) {
        for (int j = 0; j < _vec.persons[i]->getSpeed(); ++j) {
            Coords pos = _vec.persons[i]->getPosition();
            Coords new_pos = newPos(pos, _vec.persons[i]->getMove());
            if (_floor.cells[new_pos.x][new_pos.y]->getType() == Type::NORMAL){
                movePerson(new_pos, i);
            }
            if (_floor.cells[new_pos.x][new_pos.y]->getType() == Type::FULL){
                auto type_elem = _floor.cells[new_pos.x][new_pos.y]->getElem()->getType();
                if (_floor.cells[new_pos.x][new_pos.y]->getElem()->getType() == Type_of_elem::ITEM){
                    IItem* item = (IItem*)(_floor.cells[new_pos.x][new_pos.y]->getElem());
                    _vec.persons[i]->setItem(item->getItem());
                    _vecItem.del(item->getId());
                    movePerson(new_pos, i);
                }
                if(i == 0) {
                    if (type_elem == Type_of_elem::SOLDER || type_elem == Type_of_elem::TANK ||
                        type_elem == Type_of_elem::WIZARD) {
                        IPerson *person = (IPerson *) (_floor.cells[new_pos.x][new_pos.y]->getElem());
                        person->setDamage(_vec.persons[i]->getDamage());
//                        if (person->getIp() == 0) {
//                            printf("\n\n\n%d\n\n\n", person->getIp());
//                        }
//                        printf("%d\n", person->getHp());
                        if(person->getHp() <= 0){
                            ((Player*)_vec.persons[i])->setStep(person->getStep(), person->getType());
                            movePerson(new_pos, i);
                            _vec.del(person->getIp());
                        }
                    }
                }else{
                    if (type_elem == Type_of_elem::PLAYER) {
                        IPerson *person = (IPerson *) (_floor.cells[new_pos.x][new_pos.y]->getElem());
                        if (person->getIp() == 0) {
                            person->setDamage(_vec.persons[i]->getDamage());
//                            if (person->getIp() == 0) {
//                                printf("\n\n\n%d\n\n\n", person->getIp());
//                            }
//                            printf("%d\n", person->getHp());
                            if (person->getHp() <= 0) {
                                movePerson(new_pos, i);
                                return DEAD;
                            }
                        }
                    }
                }
            }
            if (_floor.cells[new_pos.x][new_pos.y]->getType() == Type::EXIT){
                if (i == 0) {
                    if (((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp() > 50){
                        _vec.persons[i]->setDamage(-50);
                    } else if (((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp() > 0){
                        _vec.persons[i]->setDamage(-(((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp()));
                    }
                    return WIN;
                }
            }
            if (_floor.cells[new_pos.x][new_pos.y]->getType() == Type::ENTRY){
                if (i == 0) {
                    if (((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp() > 50){
                        _vec.persons[i]->setDamage(-50);
                    } else if (((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp() > 0){
                        _vec.persons[i]->setDamage(-(((Player*)_vec.persons[i])->getMaxHp() - ((Player*)_vec.persons[i])->getHp()));
                    }
                }
            }
        }
    }
    _floor.cells[1][1]->setType(Type::ENTRY);
    return NOTHING;
}

void Actions::movePerson(Coords new_pos, int num_of_per) {
    Coords now_pos = _vec.persons[num_of_per]->getPosition();
    if(new_pos.x != -1) {
        _floor.cells[new_pos.x][new_pos.y]->setElem(_vec.persons[num_of_per]);
        _floor.cells[new_pos.x][new_pos.y]->setType(Type::FULL);
    }
    _floor.cells[now_pos.x][now_pos.y]->setElem(nullptr);
    _floor.cells[now_pos.x][now_pos.y]->setType(Type::NORMAL);
    _vec.persons[num_of_per]->setPosition(new_pos);
}

Coords Actions::newPos(Coords now_pos, int side_of_per) {
    Coords new_pos = now_pos;
    if(side_of_per == PAction::LEFT - 1){
        new_pos.x--;
    }else if(side_of_per == PAction::RIGHT - 1){
        new_pos.x++;
    }else if(side_of_per == PAction::DOWN - 1){
        new_pos.y++;
    }else if(side_of_per == PAction::UP - 1){
        new_pos.y--;
    }
    return new_pos;
}
