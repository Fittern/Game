#pragma once

#include "iostream"
#include "stdlib.h"
#include <SFML/Graphics.hpp>
#include "../../Elem/AllElem.h"
#include "../../Graphics/MyTexture/MyTexture.h"


enum class Type : unsigned short {
    NORMAL,
    WALL,
    ENTRY,
    EXIT,
    FULL,
    PLACE_OF_POWER
};

class Cell {
private:
    Elem* _elem = nullptr;
    int random = rand();
    Type _type;
    Coords _position;
    sf::Sprite* _sprite;
    sf::Texture* _texture;

public:
    Cell(sf::Texture* texture, Coords position, Elem* elem , Type type);
    //Cell(sf::Sprite sprite, Coords position, Elem* elem , Type type);
    Cell(const Cell&) = default;
    Cell(Cell&&) = default;
    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);
    ~Cell();

    sf::Texture* getTexture() const;

    const Coords &getPosition() const;
    void setSprite(sf::Texture* texture);
    sf::Sprite* getSprite();
    void setElem(Elem* elem);
    Elem* getElem();
    void setType(Type type);
    Type getType();

    int getRandom() const;

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
};
