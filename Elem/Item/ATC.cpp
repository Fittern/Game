//
// Created by denis on 23.10.2021.
//

#include "ATC.h"

ATC::ATC(sf::Texture *Texture, Coords Position): position(Position) {
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

std::string ATC::GetLog() {
    return "type: ATC\nLive: " + getIsLive() + "\ncoord: (" + std::to_string(position.x) + ", " +
           std::to_string(position.y) + ")" + " \n" + "//-----------\n";
}

std::string ATC::getIsLive() {
    if (isLive == 1){
        return "Live";
    } else{
        return "Dead";
    }
}

void ATC::setDead() {
    isLive = 0;
}

int ATC::getId() const {
    return id;
}

void ATC::setId(int id) {
    ATC::id = id;
}

int ATC::getIdSt() const {
    return id_st;
}

void ATC::setIdSt(int idSt) {
    id_st = idSt;
}

 Coords &ATC::getPosition() {
    return position;
}

void ATC::setPosition(const Coords &position) {
    ATC::position = position;
}
