#include "Floor.h"

Floor::Floor(int height, int width): height(height), width(width) {
    cells = new Cell**[this->height];
    for (int i = 0; i < this->height; i++) cells[i] = new Cell*[this->width];
};

Floor::Floor(const Floor& other){
    this->height = other.height;
    this->width = other.width;
    for(int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            *(this->cells[i][j]) = *(other.cells[i][j]);
        }
    }
}

Floor& Floor::operator=(const Floor& other) {
    this->height = other.height;
    this->width = other.width;
    cells = new Cell**[height];
    exit = other.exit;
    entry = other.entry;
    for (int i = 0; i < height; i++) cells[i] = new Cell*[width];
    for (int i = 0; i < height; ++i) for (int j = 0; j < width; ++j){
        cells[i][j] = new Cell(other.cells[i][j]->getTexture(), other.cells[i][j]->getPosition(), other.cells[i][j]->getElem(), other.cells[i][j]->getType());
        //cells[i][j] = &cell;
    }
    /*for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // TODO: разобраться с копированием cell
            *(cells[i][j]) = *(other.cells[i][j]);
        }
    }*/
    return *this;
}

Floor::Floor(Floor &&other) {
    this->height = other.height;
    other.height = 0;
    this->width = other.width;
    other.width = 0;
    for(int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            *(this->cells[i][j]) = *(other.cells[i][j]);
            delete other.cells[i][j];
        }
    }
}

Floor& Floor::operator=(Floor&& other){
    this->height = other.height;
    other.height = 0;
    this->width = other.width;
    other.width = 0;
    for(int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            *(this->cells[i][j]) = *(other.cells[i][j]);
            delete other.cells[i][j];
        }
    }
    return *this;
};

void Floor::Draw_Floor(sf::RenderWindow* window) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            window->draw(*this->cells[i][j]->getSprite());
        }
    }
};

Floor::~Floor() {
    for (int i = 0; i < height; ++i) delete cells[i];
    delete cells;
}

void Floor::setAllCell(sf::Texture* texture) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j] = new Cell(texture, sf::Vector2i(i, j), nullptr, Type::NORMAL);
        }
    }
}
