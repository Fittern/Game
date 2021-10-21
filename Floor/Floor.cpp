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
            *(this->cells[i][j] = other.cells[i][j]);
        }
    }
}

Floor& Floor::operator=(const Floor& other) {
    height = other.height;
    width = other.width;
    cells = new Cell**[height];
    for (int i = 0; i < height; i++) cells[i] = new Cell*[width];
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *(cells[i][j]) = *(other.cells[i][j]);
        }
    }
    return *this;
}

Floor::Floor(Floor &&other) {
    this->height = other.height;
    other.height = 0;
    this->width = other.width;
    other.width = 0;
    for(int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = other.cells[i][j];
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
            this->cells[i][j] = other.cells[i][j];
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

void Floor::Reset() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j] = new Cell(NORMAL_TEXTURE_PATH, sf::Vector2i(i, j), nullptr, Type::NORMAL);
        }
    }
}