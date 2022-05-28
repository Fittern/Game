//#include "GameStart.h"
//
//template<typename R1>
//void GameStart<R1>::StartGame() {
//    unsigned int a = time(0);
//    srand(static_cast<unsigned int>(a));//527, 55, 123, 77, 1638560379, 1638567804
//
////    floor = ruleBuilder.GetFloorFromBuilder();
//
//    VecOfPerson per(*floor);
//    VecOfItem item(*floor);
//    MyTexture game_texture;
//
////    int type;
////    LoggerImplication* base;
////    std::cin >> type;
////    switch(type) {
////        case 0: {
////            LoggerImplication *log = new ConcreteLog();
////            base = new FileLogger(log);
////            break;
////        }
////        case 1: {
////            LoggerImplication *log = new ConcreteLog();
////            base = new ConsoleLogger(log);
////            break;
////        }
////        default: {
////            LoggerImplication *log = new ConcreteLog();
////            LoggerImplication *log1 = new FileLogger(log);
////            base = new ConsoleLogger(log1);
////            break;
////        }
////    }
////    Logger *logger = Logger::GetInstance(nullptr, base);
//
//    Actions actions(per, item, *floor);
//    Rendering rendering(*floor, game_texture, (Player*)per.persons[0]);
//    rendering.drawFloor();
//    PAction pressed = NOTHING;
//
//    while (pressed) {
//        pressed = rendering.winda();
//        if (pressed == LEFT) {
//            pressed = actions.move(PAction::LEFT);
//            rendering.drawFloor();
//        }
//        else if (pressed == RIGHT) {
//            pressed = actions.move(PAction::RIGHT);
//            rendering.drawFloor();
//        }
//        else if (pressed == UP) {
//            pressed = actions.move(PAction::UP);
//            rendering.drawFloor();
//        }
//        else if (pressed == DOWN) {
//            pressed = actions.move(PAction::DOWN);
//            rendering.drawFloor();
//        }
//        if (pressed == WIN){
//            printf("You have completed the map №%d in %d steps, with %d enemy!!!", a, per.persons[0]->getStep(), per.getQuantity());
//            pressed = END;
//        }
//        if (pressed == DEAD){
//            printf("You died on the map №%d", a);
//            pressed = END;
//        }
////        logger->Update();
//    }
//
//
//    /*while (window2.isOpen()){
//        sf::Event event, event1;
//        while (window2.pollEvent(event1)) {
//            if (event1.type == sf::Event::Closed)
//                window2.close();
//        }
//        floor1->Draw_Floor(&window2);
//        window2.display();
//    }*/
//}
//
//template<typename R1>
//GameStart<R1>::GameStart(R1 ruleBuilder) {
//    floor = ruleBuilder.GetFloorFromBuilder();
//}
//
///*#include "GameStart.h"
//
//void GameStart::StartGame() {
//    sf::RenderWindow window(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1");
//    sf::RenderWindow window2(sf::VideoMode(HEIGTH_OF_FLOOR * WIDTH, WIDTH_OF_FLOOR * WIDTH), "OOP: Lab 1 w2");
//    auto builder = new FloorBuilderTree();
//    auto director = FloorDirector(builder);
//    director.Builder_FloorBuilderTree();
//    Floor* floor = builder->getFloor();
//    Floor* floor1;
//    *floor1 = *floor;
//    floor->Reset();
//
//    while (window2.isOpen() || window.isOpen()) {
//        sf::Event event, event1;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        floor1->Draw_Floor(&window2);
//        window2.display();
//        while (window2.pollEvent(event1)) {
//            if (event1.type == sf::Event::Closed)
//                window2.close();
//        }
//        floor->Draw_Floor(&window);
//        window.display();
//    }
//
//
//
//    delete builder;
//}
//*/
