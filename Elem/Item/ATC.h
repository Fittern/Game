#pragma once

#include "IItem.h"


class ATC: public IItem {
public:
    Type_of_elem type;
    sf::Texture* texture;
    sf::Sprite* sprite;
    Coords position;
    int isLive = 1;
    int id;
    int id_st;


    ATC(sf::Texture* Texture, Coords Position);
    sf::Sprite* getSprite() override;
    Type_of_elem getType() override;
    Type_of_item getItem() final;
    std::string GetLog() final;
    std::string getIsLive() final;
    void setDead() final;

    int getId() const;

    void setId(int id);

    int getIdSt() const;

    void setIdSt(int idSt);

    Coords &getPosition() final;

    void setPosition(const Coords &position);
};
