#pragma once

#include "Cell/Cell.h"

class Floor {
public:
    Cell*** cells;
    Coords entry, exit;
    int height, width;


    Floor(int height, int width);
    Floor(const Floor& other);
    Floor(Floor&& other);
    Floor& operator=(const Floor& other);
    Floor& operator=(Floor&& other);
    void Draw_Floor(sf::RenderWindow* window);
    void setAllCell(sf::Texture* texture);
    ~Floor();
};