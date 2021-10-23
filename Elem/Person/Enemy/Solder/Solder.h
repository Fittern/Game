//
// Created by denis on 23.10.2021.
//

#ifndef GAME_SOLDER_H
#define GAME_SOLDER_H

#include "../Enemy.h"


class Solder: public Enemy{
public:
    int speed = 1;
    int atc_step = 5;
    int hp_step = 3;
    int mp_step = 2;
    int atc = Enemy::step * atc_step;
    int hp = Enemy::step * hp_step;
    int mp = Enemy::step * mp_step;

    Solder(sf::Texture* texture, sf::Vector2i position);
    Type_of_elem getType() final;
    int getMove() final;
};


#endif //GAME_SOLDER_H
