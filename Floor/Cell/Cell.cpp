#include "Cell.h"

Cell::Cell(sf::Texture* texture, sf::Vector2i position, Elem* elem, Type type): _position(position), _elem(elem), _type(type){
    _texture = new sf::Texture;
    *(_texture) = *(texture);
    _sprite = new sf::Sprite(*texture);
    _sprite->setPosition(WIDTH*position.x, WIDTH*position.y);
}

void Cell::setSprite(sf::Texture* texture){
    _texture = new sf::Texture;
    _texture = texture;
    _sprite = new sf::Sprite(*texture);
    _sprite->setPosition(WIDTH*_position.x, WIDTH*_position.y);
};

sf::Sprite* Cell::getSprite(){
    return _sprite;
};

Cell::~Cell() {
    //delete _sprite;
}

void Cell::setElem(Elem* elem){
    _elem = elem;
};

Elem* Cell::getElem(){
    return _elem;
};

void Cell::setType(Type type){
    _type = type;
};

Type Cell::getType(){
    return _type;
}

Cell &Cell::operator=(const Cell &other) {
    /*if(this->_elem){
        this->_elem = new Elem;
    }
    *(this->_elem) = *(other._elem);
    // TODO: копирование элемента клетки
     */

    //this = Cell(*(other._sprite), other._position, nullptr, other._type);
    //if(this->_sprite){
    //    this->_sprite = new sf::Sprite;
    //}
    this->_position = other._position;
    this->_texture = new sf::Texture;
    *(this->_texture) = *(other._texture);
    this->_sprite = new sf::Sprite(*other._texture);
    this->_sprite->setPosition(WIDTH* this->_position.x, WIDTH* this->_position.y);
    //*(this->_sprite) = *(other._sprite);

    this->_type = other._type;
    return *this;
}

Cell &Cell::operator=(Cell &&other) {

    //*(this->_elem) = *((Elem*)other._elem);

    if(this->_sprite){
        this->_sprite = new sf::Sprite;
    }
    *(this->_sprite) = *(other._sprite);
    delete other._sprite;

    this->_type = other._type;
    this->_position = other._position;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "_type: " << (int)cell._type;
    return os;
}

/*Cell::Cell(sf::Sprite sprite, sf::Vector2i position, Elem *elem, Type type): _position(position), _elem(elem), _type(type){
    _sprite = &sprite;
}*/

const sf::Vector2i &Cell::getPosition() const {
    return _position;
}

sf::Texture* Cell::getTexture() const {
    return _texture;
}
