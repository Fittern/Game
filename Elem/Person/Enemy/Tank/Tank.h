#pragma once

#include "../Enemy.h"

class Tank: public Enemy{
public:

    Tank(sf::Texture* texture, Coords position);
    Type_of_elem getType() final;
    int getMove() final;
    std::string GetLog() final;
};
