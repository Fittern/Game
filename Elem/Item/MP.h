//
// Created by denis on 23.10.2021.
//

#ifndef GAME_MP_H
#define GAME_MP_H

#include "../IElem.h"


class MP {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Vector2i position;

    MP(sf::Texture* Texture, sf::Vector2i Position);
    sf::Sprite* getSprite() ;
    Type_of_elem getType();
    Type_of_item getItem();
};


#endif //GAME_MP_H
