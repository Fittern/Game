//
// Created by denis on 23.10.2021.
//

#include "Tank.h"

Tank::Tank(sf::Texture *texture, sf::Vector2i position) : Enemy(texture, position) {}

int Tank::getMove() {
    hp += 2*mp_step;
    return Enemy::getMove();
}

Type_of_elem Tank::getType() {
    return Type_of_elem::TANK;
}
