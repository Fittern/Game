#include "GameStart.h"

void GameStart::StartGame() {
    sf::RenderWindow window(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1");
    sf::RenderWindow window2(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1 w2");
    auto builder = new FloorBuilderTree();
    auto director = FloorDirector(builder);
    director.Builder_FloorBuilderTree();
    Floor* floor = builder->getFloor();
    Floor *floor1;
    *floor1 = *floor;
    floor->Reset();
    while (window2.isOpen() || window.isOpen()) {
        sf::Event event, event1;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        floor1->Draw_Floor(&window2);
        window2.display();
        while (window2.pollEvent(event1)) {
            if (event1.type == sf::Event::Closed)
                window2.close();
        }
        floor->Draw_Floor(&window);
        window.display();
    }
    delete builder;
}

/*#include "GameStart.h"

void GameStart::StartGame() {
    sf::RenderWindow window(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1");
    sf::RenderWindow window2(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1 w2");
    auto builder = new FloorBuilderTree();
    auto director = FloorDirector(builder);
    director.Builder_FloorBuilderTree();
    Floor* floor = builder->getFloor();
    Floor* floor1;
    *floor1 = *floor;
    floor->Reset();

    while (window2.isOpen() || window.isOpen()) {
        sf::Event event, event1;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        floor1->Draw_Floor(&window2);
        window2.display();
        while (window2.pollEvent(event1)) {
            if (event1.type == sf::Event::Closed)
                window2.close();
        }
        floor->Draw_Floor(&window);
        window.display();
    }



    delete builder;
}
*/
