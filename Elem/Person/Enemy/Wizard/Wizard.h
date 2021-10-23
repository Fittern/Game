//
// Created by denis on 23.10.2021.
//

#ifndef GAME_WIZARD_H
#define GAME_WIZARD_H

#include "../Enemy.h"

class Wizard: public Enemy{
public:
    int speed = 0;
    int speed_flag = 0;
    int atc_step = 2;
    int hp_step = 1;
    int mp_step = 7;
    int atc = Enemy::step * atc_step;
    int hp = Enemy::step * hp_step;
    int mp = Enemy::step * mp_step;

    Wizard(sf::Texture* texture, sf::Vector2i position);
    Type_of_elem getType() final;
    int getMove() final;
};


#endif //GAME_WIZARD_H
