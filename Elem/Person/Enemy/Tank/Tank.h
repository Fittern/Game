//
// Created by denis on 23.10.2021.
//

#ifndef GAME_TANK_H
#define GAME_TANK_H

#include "../Enemy.h"

class Tank: public Enemy{
public:
    int speed = 2;
    int atc_step = 3;
    int hp_step = 6;
    int mp_step = 1;
    int atc = Enemy::step * atc_step;
    int hp = Enemy::step * hp_step;
    int mp = Enemy::step * mp_step;

    Tank(sf::Texture* texture, sf::Vector2i position);
    Type_of_elem getType() final;
    int getMove() final;
};


#endif //GAME_TANK_H
