#ifndef GAME_IELEM_H
#define GAME_IELEM_H

#include "../Floor/Cell/Cell.h"

enum class Type_of_elem : unsigned short {
    EMPTY,
    FULL,
    PLAYER,
    ENEMY,
    ITEM,
    PLACE_OF_POWER
};

class IElem {
/*private:
    Type_of_elem _type;
    int step, _hp, _chi, _damage;*/

public:
    //IElem(Ce* cell) = 0;
    IElem(IElem&&) = default;
    virtual IElem& operator=(const IElem& other) = 0;
    virtual IElem& operator=(IElem&& other) = 0;
    virtual void setTexture(sf::Texture* texture) = 0;
    virtual sf::Sprite* getSprite() = 0;
    virtual Type_of_elem getType() = 0;
    virtual float getDamage() = 0;
    virtual void setDamage(float damage) = 0;
    virtual int getSpeed() = 0;
    virtual int getStep() = 0;
    virtual void setStep(int step) = 0;


};


#endif GAME_IELEM_H
