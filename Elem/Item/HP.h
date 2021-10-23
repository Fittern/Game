//
// Created by denis on 23.10.2021.
//

#ifndef GAME_HP_H
#define GAME_HP_H

#include "../IElem.h"


class HP {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Vector2i position;

    HP(sf::Texture* Texture, sf::Vector2i Position);
    sf::Sprite* getSprite() ;
    Type_of_elem getType();
    Type_of_item getItem();
};


#endif //GAME_HP_H
