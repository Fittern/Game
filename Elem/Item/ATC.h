//
// Created by denis on 23.10.2021.
//

#ifndef GAME_ATC_H
#define GAME_ATC_H

#include "../IElem.h"


class ATC {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Vector2i position;

    ATC(sf::Texture* Texture, sf::Vector2i Position);
    sf::Sprite* getSprite() ;
    Type_of_elem getType();
    Type_of_item getItem();
};


#endif //GAME_ATC_H
