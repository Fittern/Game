#pragma once

#include "../IPerson.h"

class Player: public IPerson{
public:
    sf::Texture* texture;
    sf::Sprite* sprite;
    Coords position;
    //Type_of_elem type = Type_of_elem::ENEMY;
    int speed = 1;
    int atc = 300;
    int hp = 300;
    int max_hp = 300;
    int mp = 300;
    int side;
    int ip = 0;
    int step = 0;

    Player(sf::Texture* Texture, Coords Position);
    ~Player();
    sf::Sprite* getSprite() final;
    Type_of_elem getType() final;

    void setSide(PAction now_side);

    Coords getPosition() final;
    void setPosition(Coords position) final;
    int getDamage() final;
    void setDamage(int damage) final;
    int getSpeed() final;
    int getMove() final;
    int getIp() final;
    int getHp() final;
    int getStep() final;
    void setStep(int step, Type_of_elem typeOfEnemy) final;
    void setItem(Type_of_item item) final;
    int getMaxHp() const;
    void setMaxHp(int maxHp);
};