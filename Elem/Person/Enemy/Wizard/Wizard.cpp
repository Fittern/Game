//
// Created by denis on 23.10.2021.
//

#include "Wizard.h"

Wizard::Wizard(sf::Texture *texture, sf::Vector2i position) : Enemy(texture, position) {}

int Wizard::getMove() {
    if (speed_flag == 0){
        speed_flag = 1;
        speed = 0;
        return Enemy::getMove();
    }
    else {
        speed_flag = 0;
        speed = 1;
        return Enemy::getMove();
    }
}

Type_of_elem Wizard::getType() {
    return Type_of_elem::WIZARD;
}
