//
// Created by denis on 23.10.2021.
//

#include "Wizard.h"

Wizard::Wizard(sf::Texture *texture, Coords position) : Enemy(texture, position) {
    speed = 1;
    atc_step = 2;
    hp_step = 1;
    mp_step = 7;
    atc = Enemy::step * atc_step;
    hp = Enemy::step * hp_step;
    mp = Enemy::step * mp_step;
}

int Wizard::getMove() {
    if (speed_flag == 1){
        speed_flag = 0;
        return Enemy::getMove();
    }
    else {
        speed_flag = 1;
        Enemy::getMove();
        return -1;
    }
}

Type_of_elem Wizard::getType() {
    return Type_of_elem::WIZARD;
}
