//
// Created by denis on 26.11.2021.
//
#include "Rendering.h"

Rendering::Rendering(Floor &floor, MyTexture g_texture, Player* player) : _floor(floor), game_texture(g_texture), _player(player) {
    _window = new sf::RenderWindow(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, (WIDTH_OF_FLOOR + 3) * WIDTH), "OOP: Lab 1");
}


void Rendering::drawFloor() {
    for (int i = 0; i < _floor.height; ++i) {
        for (int j = 0; j < _floor.width; ++j) {
            //cells[i][j]->setSprite(cells[i][j]->getTexture());
            _window->draw(*_floor.cells[i][j]->getSprite());
            if (_floor.cells[i][j]->getElem() != nullptr) {
                _floor.cells[i][j]->getElem()->getSprite()->setPosition(WIDTH * i, WIDTH * j);
                _window->draw(*_floor.cells[i][j]->getElem()->getSprite());
            }
        }
    }
    for (int i = 0; i < _floor.height; ++i) {
        for (int j = _floor.width; j < _floor.width + 3; ++j) {
            auto texture = new sf::Texture;
            texture = game_texture.getTextureOfCellNormal();
            auto sprite = new sf::Sprite(*texture);
            sprite->setPosition(WIDTH * i, WIDTH * j);
            _window->draw(*sprite);
        }
    }
    sf::Font font;//шрифт
    font.loadFromFile("/home/denis/CLionProjects/Game/Graphics/Font/20085.ttf");
    sf::Text text("", font, 18);
    sf::Color color(0, 0, 0, 150);
    text.setColor(color);
    //text.setStyle(sf::Text::Bold);
    std::ostringstream playerScoreString;
    playerScoreString << _player->hp << '/' << _player->max_hp;
    text.setString("HP: " + playerScoreString.str());
    text.setPosition(10, _floor.width*WIDTH + 5);
    _window->draw(text);
    playerScoreString.str("");
    playerScoreString << _player->mp;
    text.setString("MP: " + playerScoreString.str());
    text.setPosition(10, (_floor.width + 1)*WIDTH + 5);
    _window->draw(text);
    playerScoreString.str("");
    playerScoreString << _player->atc;
    text.setString("ATC: " + playerScoreString.str());
    text.setPosition(10, (_floor.width + 2)*WIDTH + 5);
    _window->draw(text);//рисую этот текст

    _window->display();
}

PAction Rendering::winda() {
    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                _window->close();
                return PAction::END;
            }
            if (event.type == sf::Event::KeyReleased) //проверка на отпускание
            {
                if (event.key.code == sf::Keyboard::A) //указываешь кнопку
                {
                    return PAction::LEFT;
                }
                if (event.key.code == sf::Keyboard::D) //указываешь кнопку
                {
                    return PAction::RIGHT;
                }
                if (event.key.code == sf::Keyboard::W) //указываешь кнопку
                {
                    return PAction::UP;
                }
                if (event.key.code == sf::Keyboard::S) //указываешь кнопку
                {
                    return PAction::DOWN;
                }
            }
        }
        //_floor.Draw_Floor(_window);
        _window->display();
        //while (window2.pollEvent(event1)) {
        //    if (event1.type == sf::Event::Closed)
        //        window2.close();
        //}
        //floor1->Draw_Floor(&window2);
        //window2.display();
    }

    /*while (window2.isOpen()){
        sf::Event event, event1;
        while (window2.pollEvent(event1)) {
            if (event1.type == sf::Event::Closed)
                window2.close();
        }
        floor1->Draw_Floor(&window2);
        window2.display();
    }*/
}

