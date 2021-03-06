//
// Created by denis on 23.10.2021.
//

#include "Enemy.h"

Enemy::Enemy(sf::Texture *Texture, Coords Position): position(Position) {
    texture = new sf::Texture;
    texture = Texture;
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(WIDTH * position.x, WIDTH * position.y);
}

int Enemy::getDamage()  {
    return atc;
}

void Enemy::setDamage(int damage)  {
    hp = hp - damage;
}

int Enemy::getSpeed()  {
    return speed;
}

int Enemy::getMove()  {
    step++;
    hp += hp_step;
    mp += mp_step;
    atc += atc_step;
    int side = rand()%4;
    return side;
}

Enemy::~Enemy() {
    delete sprite;
}

sf::Sprite *Enemy::getSprite()  {
    return sprite;
}

Type_of_elem Enemy::getType()  {
    return Type_of_elem::SOLDER;
}

int Enemy::getStep()  {
    return (int)(step/10);
}

void Enemy::setStep(int step, Type_of_elem type)  {
    hp += hp_step * step;
    mp += mp_step * step;
    atc += atc_step * step;
}

void Enemy::setItem(Type_of_item item) {
    if (item == Type_of_item::ATC){
        atc += 500;
    }
    else if (item == Type_of_item::HP){
        hp += 1000;
    }
    else{
        mp += 300;
    }
}

Coords Enemy::getPosition() {
    return position;
}

void Enemy::setPosition(Coords position) {
    Enemy::position = position;
}

int Enemy::getHp() {
    return hp;
}

int Enemy::getIp() {
    return ip;
}

std::string Enemy::getIsLive() {
    if (isLive == 1){
        return "Live";
    } else{
        return "Dead";
    }
}

void Enemy::setDead() {
    isLive = 0;
}

int Enemy::getIdSt() const {
    return id_st;
}

void Enemy::setIdSt(int idSt) {
    id_st = idSt;
}


