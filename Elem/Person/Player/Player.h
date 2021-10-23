//
// Created by denis on 23.10.2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../IPerson.h"

enum Side{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Player: public IPerson{
public:
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Vector2i position;
    //Type_of_elem type = Type_of_elem::ENEMY;
    int speed = 1;
    int atc = 300;
    int hp = 300;
    int mp = 300;
    int side;

    Player(sf::Texture* Texture, sf::Vector2i Position);
    ~Player();
    sf::Sprite* getSprite() final;
    Type_of_elem getType() final;

    int setSide(Side now_side);

    int getDamage() final;
    void setDamage(int damage) final;
    int getSpeed() final;
    int getMove() final;
    int getStep() final;
    void setStep(int step, Type_of_elem typeOfEnemy) final;
    void setItem(Type_of_item item) override;
};


#endif //GAME_PLAYER_H
