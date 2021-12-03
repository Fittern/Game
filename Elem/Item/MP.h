#pragma once

#include "IItem.h"


class MP: public IItem {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    Coords position;

    MP(sf::Texture* Texture, Coords Position);
    sf::Sprite* getSprite() override;
    Type_of_elem getType() override;
    Type_of_item getItem() final;
};
