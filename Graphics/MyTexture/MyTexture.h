#pragma once

#include <SFML/Graphics.hpp>

/*
#define NORMAL_TEXTURE_PATH "../Game_Obj/Tiles/tile_0019.png"
#define ENTRY_TEXTURE_PATH "../Game_Obj/Tiles/tile_0048.png"
#define EXIT_TEXTURE_PATH "../Game_Obj/Tiles/tile_0083.png"
#define WALL_TEXTURE_PATH "../Game_Obj/Tiles/tile_0013.png"
*/
#define NORMAL_TEXTURE_PATH "../Game_Obj/Normal.jpg"
#define ENTRY_TEXTURE_PATH "../Game_Obj/Entry.jpg"
#define EXIT_TEXTURE_PATH "../Game_Obj/Exit.jpg"
#define WALL_TEXTURE_PATH "../Game_Obj/Wall.jpg"

#define HP_TEXTURE_PATH "../Game_Obj/HP.jpg"
#define MP_TEXTURE_PATH "../Game_Obj/MP.jpg"
#define ATC_TEXTURE_PATH "../Game_Obj/ATC.jpg"

#define PLAYER_TEXTURE_PATH "../Game_Obj/Player.jpg"

#define TANK_TEXTURE_PATH "../Game_Obj/Tank.jpg"
#define SOLDER_TEXTURE_PATH "../Game_Obj/Solder.jpg"
#define WIZARD_TEXTURE_PATH "../Game_Obj/Wizard.jpg"

class MyTexture {
private:
    //texture of cell
    sf::Texture* _texture_of_cell_normal;
    sf::Texture* _texture_of_cell_exit;
    sf::Texture* _texture_of_cell_entry;
    sf::Texture* _texture_of_cell_wall;

    sf::Texture* _texture_of_elem_HP;
    sf::Texture* _texture_of_elem_MP;
    sf::Texture* _texture_of_elem_ATC;

    sf::Texture* _texture_of_elem_player;

    sf::Texture* _texture_of_elem_tank;
    sf::Texture* _texture_of_elem_solder;
    sf::Texture* _texture_of_elem_wizard;

public:
    //TODO: из класса GameStart сюда пихнуть создание элемента класса
    //TODO: хорошо бы переместить этот класс в отрисовку

    MyTexture();

    sf::Texture *getTextureOfCellNormal() const;
    void setTextureOfCellNormal(const std::string& filename);
    sf::Texture *getTextureOfCellExit() const;
    void setTextureOfCellExit(const std::string& filename);
    sf::Texture *getTextureOfCellEntry() const;
    void setTextureOfCellEntry(const std::string& filename);
    sf::Texture *getTextureOfCellWall() const;
    void setTextureOfCellWall(const std::string& filename);

    sf::Texture *getTextureOfElemHp() const;
    void setTextureOfElemHp(const std::string& filename);
    sf::Texture *getTextureOfElemMp() const;
    void setTextureOfElemMp(const std::string& filename);
    sf::Texture *getTextureOfElemAtc() const;
    void setTextureOfElemAtc(const std::string& filename);

    sf::Texture *getTextureOfElemPlayer() const;
    void setTextureOfElemPlayer(const std::string& filename);

    sf::Texture *getTextureOfElemTank() const;
    void setTextureOfElemTank(const std::string& filename);
    sf::Texture *getTextureOfElemSolder() const;
    void setTextureOfElemSolder(const std::string& filename);
    sf::Texture *getTextureOfElemWizard() const;
    void setTextureOfElemWizard(const std::string& filename);
};
