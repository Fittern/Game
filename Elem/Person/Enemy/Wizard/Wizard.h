#pragma once

#include "../Enemy.h"

class Wizard: public Enemy{
public:
    int speed_flag = 0;


    Wizard(sf::Texture* texture, Coords position);
    Type_of_elem getType() final;
    int getMove() final;
    std::string GetLog() final;
};
