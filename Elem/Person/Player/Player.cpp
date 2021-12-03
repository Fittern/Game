//
// Created by denis on 23.10.2021.
//

#include "Player.h"

Player::Player(sf::Texture *Texture, Coords Position): position(Position){
    texture = new sf::Texture;
    texture = Texture;
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(WIDTH * position.x, WIDTH * position.y);
}

Player::~Player() {
    delete texture;
    delete sprite;
}

sf::Sprite *Player::getSprite() {
    return sprite;
}

Type_of_elem Player::getType() {
    return Type_of_elem::PLAYER;
}

int Player::getDamage() {
    return atc;
}

void Player::setDamage(int damage) {
    hp = hp - damage;
}

int Player::getSpeed() {
    return speed;
}

int Player::getMove() {
    step++;
    return side;
}

void Player::setSide(PAction now_side) {
    side = (int)now_side - 1;
}

int Player::getStep() {
    return step;
}

void Player::setStep(int step, Type_of_elem typeOfEnemy) {
    if (typeOfEnemy == Type_of_elem::WIZARD){
        atc += step*2;
        hp += step;
        max_hp += step;
        mp += step*7;
    }
    else if (typeOfEnemy == Type_of_elem::TANK){
        atc += step*3;
        hp += step*6;
        max_hp += step*6;
        mp += step;
    }
    else {
        atc += step*5;
        hp += step*3;
        max_hp += step*3;
        mp += step*2;
    }
}

void Player::setItem(Type_of_item item) {
    if (item == Type_of_item::ATC){
        atc += 500;
    }
    else if (item == Type_of_item::HP){
        hp += 1000;
        max_hp += 1000;
    }
    else{
        mp += 300;
    }
}

Coords Player::getPosition() {
    return position;
}

void Player::setPosition(Coords position) {
    Player::position = position;
}

int Player::getMaxHp() const {
    return max_hp;
}

void Player::setMaxHp(int maxHp) {
    max_hp = maxHp;
}

int Player::getHp() {
    return hp;
}

int Player::getIp() {
    return ip;
}
