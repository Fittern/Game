#pragma once

#include "iostream"
#include "stdlib.h"
#include <SFML/Graphics.hpp>
#include "../GameEng/Const.h"
#include "Coords.h"

enum class Type_of_elem{
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

class Elem {
/*private:
    Type_of_elem _type;
    int step, _hp, _chi, _damage;*/

public:
    //virtual Elem& operator=(const Elem& other) = 0;
    //virtual Elem& operator=(Elem&& other) = 0;
    virtual sf::Sprite* getSprite() = 0;
    virtual Type_of_elem getType() = 0;
};