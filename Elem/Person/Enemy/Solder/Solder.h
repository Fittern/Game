#pragma once

#include "../Enemy.h"


class Solder: public Enemy{
public:

    Solder(sf::Texture* texture, Coords position);
    Type_of_elem getType() final;
    int getMove() final;
    std::string GetLog() final;
};
