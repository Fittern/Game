//
// Created by denis on 23.10.2021.
//

#include "Tank.h"

Tank::Tank(sf::Texture *texture, Coords position) : Enemy(texture, position) {
    speed = 2;
    atc_step = 1.5;
    hp_step = 3;
    mp_step = 0.5;
    atc = step * atc_step;
    mp = step * mp_step;
    hp = step * hp_step;
}

int Tank::getMove() {
    hp += 2*mp_step;
    return Enemy::getMove();
}

Type_of_elem Tank::getType() {
    return Type_of_elem::TANK;
}

std::string Tank::GetLog() {
    return "type: Tank\nId:" + std::to_string(ip) + "\nLive: " + getIsLive() +"\nnow health: " + std::to_string(hp) + " \n" + "damage: " + std::to_string(atc) + " \n" + "coord: ("   + std::to_string(position.x) + ", " +
           std::to_string(position.y) + ")" + " \n" + "//-----------\n";
}
