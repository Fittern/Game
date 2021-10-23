//
// Created by denis on 23.10.2021.
//

#ifndef GAME_IPERSON_H
#define GAME_IPERSON_H

#include "../IElem.h"



class IPerson: public IElem {
public:


    virtual int getDamage() = 0;
    virtual void setDamage(int damage) = 0;
    virtual void setItem(Type_of_item item) = 0;
    virtual int getSpeed() = 0;
    virtual int getMove() = 0;
    virtual int getStep() = 0;
    virtual void setStep(int step, Type_of_elem typeOfEnemy) = 0;
};


#endif //GAME_IPERSON_H
