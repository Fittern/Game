//
// Created by denis on 23.10.2021.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "../IPerson.h"

class Enemy: public IPerson{
public:
    sf::Texture* texture;
    sf::Sprite* sprite;
    Coords position;
    int speed;
    int step = 20;
    int atc_step;
    int hp_step;
    int mp_step;
    int atc;
    int hp;
    int mp;
    int ip;

    Enemy(sf::Texture* Texture, Coords Position);
    ~Enemy();
    sf::Sprite* getSprite() final;
    Type_of_elem getType() override;

    int getIp() final;
    int getHp() final;
    Coords getPosition() final;
    void setPosition(Coords position) final;
    void setItem(Type_of_item item) final;
    int getDamage() override;
    void setDamage(int damage) final;
    int getSpeed() final;
    int getMove() override;
    int getStep() final;
    void setStep(int step, Type_of_elem type) final;
};


#endif //GAME_ENEMY_H
