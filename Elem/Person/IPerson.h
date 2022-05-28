#pragma once

#include "../Elem.h"

enum PAction{
    END,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NOTHING,
    WIN,
    DEAD,
    SAVE,
    WR
};

class IPerson: public Elem {
public:


    virtual int getDamage() = 0;
    virtual void setDamage(int damage) = 0;
    virtual void setPosition(Coords position) = 0;
    virtual Coords getPosition() = 0;
    virtual void setItem(Type_of_item item) = 0;
    virtual int getSpeed() = 0;
    virtual int getMove() = 0;
    virtual int getIp() = 0;
    virtual int getHp() = 0;
    virtual int getStep() = 0;
    virtual void setStep(int step, Type_of_elem typeOfEnemy) = 0;
};