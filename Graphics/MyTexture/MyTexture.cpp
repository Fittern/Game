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

sf::Texture *MyTexture::getTextureOfElemHp() const {
    return _texture_of_elem_HP;
}

void MyTexture::setTextureOfElemHp(const std::string& filename) {
    _texture_of_elem_HP = new sf::Texture;
    _texture_of_elem_HP->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemMp() const {
    return _texture_of_elem_MP;
}

void MyTexture::setTextureOfElemMp(const std::string& filename) {
    _texture_of_elem_MP = new sf::Texture;
    _texture_of_elem_MP->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemAtc() const {
    return _texture_of_elem_ATC;
}

void MyTexture::setTextureOfElemAtc(const std::string& filename) {
    _texture_of_elem_ATC = new sf::Texture;
    _texture_of_elem_ATC->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemPlayer() const {
    return _texture_of_elem_player;
}

void MyTexture::setTextureOfElemPlayer(const std::string& filename) {
    _texture_of_elem_player = new sf::Texture;
    _texture_of_elem_player->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemTank() const {
    return _texture_of_elem_tank;
}

void MyTexture::setTextureOfElemTank(const std::string& filename) {
    _texture_of_elem_tank = new sf::Texture;
    _texture_of_elem_tank->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemSolder() const {
    return _texture_of_elem_solder;
}

void MyTexture::setTextureOfElemSolder(const std::string& filename) {
    _texture_of_elem_solder = new sf::Texture;
    _texture_of_elem_solder->loadFromFile(filename);
}

sf::Texture *MyTexture::getTextureOfElemWizard() const {
    return _texture_of_elem_wizard;
}

void MyTexture::setTextureOfElemWizard(const std::string& filename) {
    _texture_of_elem_wizard = new sf::Texture;
    _texture_of_elem_wizard->loadFromFile(filename);
}

MyTexture::MyTexture() {
    setTextureOfCellEntry(ENTRY_TEXTURE_PATH);
    setTextureOfCellExit(EXIT_TEXTURE_PATH);
    setTextureOfCellNormal(NORMAL_TEXTURE_PATH);
    setTextureOfCellWall(WALL_TEXTURE_PATH);

    setTextureOfElemHp(HP_TEXTURE_PATH);
    setTextureOfElemMp(MP_TEXTURE_PATH);
    setTextureOfElemAtc(ATC_TEXTURE_PATH);

    setTextureOfElemPlayer(PLAYER_TEXTURE_PATH);

    setTextureOfElemTank(TANK_TEXTURE_PATH);
    setTextureOfElemSolder(SOLDER_TEXTURE_PATH);
    setTextureOfElemWizard(WIZARD_TEXTURE_PATH);
}
