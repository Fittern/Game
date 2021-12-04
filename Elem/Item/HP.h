#pragma once

#include "IItem.h"


class HP: public IItem {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    Coords position;
    int isLive = 1;
    int id;

    HP(sf::Texture* Texture, Coords Position);
    sf::Sprite* getSprite() final;
    Type_of_elem getType() final;
    Type_of_item getItem() final;
    std::string GetLog() final;
    std::string getIsLive();
    void setDead() final;
    int getId() const;
    void setId(int id);
};