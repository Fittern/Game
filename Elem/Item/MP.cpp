//
// Created by denis on 23.10.2021.
//

#include "MP.h"

MP::MP(sf::Texture *Texture, sf::Vector2i Position): position(Position) {
    texture = new sf::Texture;
    texture = Texture;
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(WIDTH * position.x, WIDTH * position.y);
}

sf::Sprite *MP::getSprite() {
    return sprite;
}

Type_of_elem MP::getType() {
    return Type_of_elem::ITEM;
}

Type_of_item MP::getItem() {
    return Type_of_item::ATC;
}