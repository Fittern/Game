#ifndef GAME_FLOOR_H
#define GAME_FLOOR_H

#define HEIGTH_OF_FLOOR 25
#define WIDTH_OF_FLOOR 15
#define MIN_SIZE_OF_FLOOR 9

#define NORMAL_TEXTURE_PATH "../Game_Obj/Normal.jpg"

#include "Cell/Cell.h"

class Floor {
public:
    Cell*** cells;
    sf::Vector2i entry, exit;
    int height, width;


    Floor(int height, int width);
    Floor(const Floor& other);
    Floor(Floor&& other);
    Floor& operator=(const Floor& other);
    Floor& operator=(Floor&& other);
    void Draw_Floor(sf::RenderWindow* window);
    void Reset();
    ~Floor();
};


#endif //GAME_FLOOR_H
