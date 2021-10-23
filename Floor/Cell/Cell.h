#ifndef GAME_CELL_H
#define GAME_CELL_H
#define WIDTH 32

#include "iostream"
#include "stdlib.h"
#include <SFML/Graphics.hpp>
#include "../../Elem/IElem.h"
#include "../../MyTexture/MyTexture.h"


enum class Type : unsigned short {
    NORMAL,
    WALL,
    ENTRY,
    EXIT,
    PLACE_OF_POWER
};

class Cell {
private:
    IElem* _elem = nullptr;
    Type _type;
    sf::Vector2i _position;
    sf::Sprite* _sprite;
    sf::Texture* _texture;

public:
    Cell(sf::Texture* texture, sf::Vector2i position, IElem* elem , Type type);
    //Cell(sf::Sprite sprite, sf::Vector2i position, IElem* elem , Type type);
    Cell(const Cell&) = default;
    Cell(Cell&&) = default;
    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);
    ~Cell();

    sf::Texture* getTexture() const;

    const sf::Vector2i &getPosition() const;
    void setSprite(sf::Texture* texture);
    sf::Sprite* getSprite();
    void setElem(IElem* elem);
    IElem* getElem();
    void setType(Type type);
    Type getType();

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
};


#endif //GAME_CELL_H
