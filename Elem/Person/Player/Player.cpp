//
// Created by denis on 23.10.2021.
//

#include "Player.h"

Player::Player(sf::Texture *Texture, sf::Vector2i Position) {
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
    return side;
}

int Player::setSide(Side now_side) {
    side = now_side;
}

int Player::getStep() {
    return 500;
}

void Player::setStep(int step, Type_of_elem typeOfEnemy) {
    if (typeOfEnemy == Type_of_elem::WIZARD){
        atc += step*2;
        hp += step;
        mp += step*7;
    }
    else if (typeOfEnemy == Type_of_elem::TANK){
        atc += step*3;
        hp += step*6;
        mp += step;
    }
    else {
        atc += step*5;
        hp += step*3;
        mp += step*2;
    }
}

void Player::setItem(Type_of_item item) {
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
