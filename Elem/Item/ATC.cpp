//
// Created by denis on 23.10.2021.
//

#include "ATC.h"

ATC::ATC(sf::Texture *Texture, sf::Vector2i Position): position(Position) {
    texture = new sf::Texture;
    texture = Texture;
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(WIDTH * position.x, WIDTH * position.y);
}

sf::Sprite *ATC::getSprite() {
    return sprite;
}

Type_of_elem ATC::getType() {
    return Type_of_elem::ITEM;
}

Type_of_item ATC::getItem() {
    return Type_of_item::ATC;
}
