//
// Created by denis on 23.10.2021.
//

#include "HP.h"

HP::HP(sf::Texture *Texture, sf::Vector2i Position): position(Position) {
    texture = new sf::Texture;
    texture = Texture;
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(WIDTH * position.x, WIDTH * position.y);
}

sf::Sprite *HP::getSprite() {
    return sprite;
}

Type_of_elem HP::getType() {
    return Type_of_elem::ITEM;
}

Type_of_item HP::getItem() {
    return Type_of_item::HP;
}