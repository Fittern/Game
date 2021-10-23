#ifndef GAME_IELEM_H
#define GAME_IELEM_H

#include "../Floor/Cell/Cell.h"

enum class Type_of_elem : unsigned short {
    EMPTY,
    FULL,
    PLAYER,
    WIZARD,
    TANK,
    SOLDER,
    ITEM
};

enum class Type_of_item{
    ATC,
    MP,
    HP
};

class IElem {
/*private:
    Type_of_elem _type;
    int step, _hp, _chi, _damage;*/

public:
    //virtual IElem& operator=(const IElem& other) = 0;
    //virtual IElem& operator=(IElem&& other) = 0;
    virtual sf::Sprite* getSprite() = 0;
    virtual Type_of_elem getType() = 0;
};


#endif GAME_IELEM_H
