//
// Created by denis on 23.10.2021.
//

#include "Solder.h"

Solder::Solder(sf::Texture *texture, Coords position) : Enemy(texture, position) {

    speed = 1;
    atc_step = 5;
    hp_step = 3;
    mp_step = 2;
    atc = Enemy::step * atc_step;
    hp = Enemy::step * hp_step;
    mp = Enemy::step * mp_step;
}

int Solder::getMove() {
    hp += mp_step;
    return Enemy::getMove();
}

Type_of_elem Solder::getType() {
    return Type_of_elem::SOLDER;
}

std::string Solder::GetLog() {
    return "type: Solder\nId:" + std::to_string(ip) + "\nLive: " + getIsLive() + "\nnow health: " + std::to_string(hp) + " \n" + "damage: " + std::to_string(atc) + " \n" + "coord: ("   + std::to_string(position.x) + ", " +
           std::to_string(position.y) + ")" + " \n" + "//-----------\n";
}
