//
// Created by denis on 23.10.2021.
//

#include "HP.h"

HP::HP(sf::Texture *Texture, Coords Position): position(Position) {
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

std::string HP::GetLog() {
    return "type: HP\nLive: " + getIsLive() + "\ncoord: (" + std::to_string(position.x) + ", " +
           std::to_string(position.y) + ")" + " \n" + "//-----------\n";
}

std::string HP::getIsLive() {
    if (isLive == 1){
        return "Live";
    } else{
        return "Dead";
    }
}

void HP::setDead() {
    isLive = 0;
}

int HP::getId() const {
    return id;
}

void HP::setId(int id) {
    HP::id = id;
}
