//
// Created by denis on 23.10.2021.
//

#include "MP.h"

MP::MP(sf::Texture *Texture, Coords Position): position(Position) {
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
    return Type_of_item::MP;
}

std::string MP::GetLog() {
    return "type: MP\nLive: " + getIsLive() + "\ncoord: (" + std::to_string(position.x) + ", " +
           std::to_string(position.y) + ")" + " \n" + "//-----------\n";
}

std::string MP::getIsLive() {
    if (isLive == 1){
        return "Live";
    } else{
        return "Dead";
    }
}

void MP::setDead() {
    isLive = 0;
}

int MP::getId() const {
    return id;
}

void MP::setId(int id) {
    MP::id = id;
}
