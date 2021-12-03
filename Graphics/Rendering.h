#pragma once

#include "MyTexture/MyTexture.h"
#include "../Floor/Floor.h"
#include <sstream>

class Rendering {
public:
    Floor &_floor;
    sf::RenderWindow *_window;
    MyTexture game_texture;
    Player* _player;
    Rendering(Floor &floor, MyTexture g_texture, Player* player);
    PAction winda();

    void drawFloor();
    //TODO: Тааак, надо переместить отрисовку из Floor сюда
    //TODO: возможно стоит забрать у клеток и элементов клеток текстуры и оставить их только в графике, но спорно

};
