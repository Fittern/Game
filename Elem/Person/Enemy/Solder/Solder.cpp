//
// Created by denis on 23.10.2021.
//

#include "Solder.h"

Solder::Solder(sf::Texture *texture, sf::Vector2i position) : Enemy(texture, position) {}

int Solder::getMove() {
    hp += mp_step;
    return Enemy::getMove();
}

Type_of_elem Solder::getType() {
    return Type_of_elem::SOLDER;
}
