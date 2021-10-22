#include "MyTexture.h"

sf::Texture *MyTexture::getTextureOfCellNormal() const {
    return _texture_of_cell_normal;
}

void MyTexture::setTextureOfCellNormal(const std::string& filename) {
    _texture_of_cell_normal = new sf::Texture;
    _texture_of_cell_normal->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfCellExit() const {
    return _texture_of_cell_exit;
}

void MyTexture::setTextureOfCellExit(const std::string& filename) {
    _texture_of_cell_exit = new sf::Texture;
    _texture_of_cell_exit->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfCellEntry() const {
    return _texture_of_cell_entry;
}

void MyTexture::setTextureOfCellEntry(const std::string& filename) {
    _texture_of_cell_entry = new sf::Texture;
    _texture_of_cell_entry->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfCellWall() const {
    return _texture_of_cell_wall;
}

void MyTexture::setTextureOfCellWall(const std::string& filename) {
    _texture_of_cell_wall = new sf::Texture;
    _texture_of_cell_wall->loadFromFile(filename);
}
