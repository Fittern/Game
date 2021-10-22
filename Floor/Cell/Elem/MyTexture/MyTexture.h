#ifndef GAME_MYTEXTURE_H
#define GAME_MYTEXTURE_H

#include <SFML/Graphics.hpp>


class MyTexture {
private:
    //texture of cell
    sf::Texture _texture_of_cell_normal;
    sf::Texture _texture_of_cell_exit;
    sf::Texture _texture_of_cell_entry;
    sf::Texture _texture_of_cell_wall;

    //texture of the cell element(e.g. enemy, player, item)
    // TODO: текстуры элементов клеток
    //  sf::Texture* _texture_of_elem_;

public:
    sf::Texture getTextureOfCellNormal() const;
    void setTextureOfCellNormal(const std::string& filename);
    sf::Texture getTextureOfCellExit() const;
    void setTextureOfCellExit(const std::string& filename);
    sf::Texture getTextureOfCellEntry() const;
    void setTextureOfCellEntry(const std::string& filename);
    sf::Texture getTextureOfCellWall() const;
    void setTextureOfCellWall(const std::string& filename);
};


#endif //GAME_MYTEXTURE_H
