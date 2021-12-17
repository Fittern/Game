#pragma once

#include <ctime>

#include "../Floor/FloorDirector.h"
#include "../Floor/FloorBuilderTree.h"
#include "../Floor/FloorBuilderConst.h"
#include "../Actions/Actions.h"
#include "../Graphics/Rendering.h"
#include "../VecOfElem/VecOfItem/VecOfItem.h"
#include "../Logger/ConcreteLog.h"

#include "../Logger/Observer.h"
#include "../Logger/Subject.h"
#include "../Logger/Decorator/ConsoleLogger.h"
#include "../Logger/Decorator/FileLogger.h"
#include "../Logger/Logger.h"
#include "../Logger/LoggerImplication.h"
#include "../Logger/Decorator/Decorator.h"

#include "../Rules/RulesBuilder.h"
#include "../Rules/RuleEnd.h"

template<typename R1, typename R2>

class GameStart {
private:
    R1 ruleBuilder;
    R2 ruleEnd;
    int code_of_map;
    Floor* floor;
public:
    GameStart(){
        floor = ruleBuilder.GetFloorFromBuilder();
        code_of_map = ruleBuilder.GetInt();
    };

    void StartGame(){
        VecOfPerson per(*floor);
        VecOfItem item(*floor);
        MyTexture game_texture;

        Actions actions(per, item, *floor);
        Rendering rendering(*floor, game_texture, (Player*)per.persons[0]);
        rendering.drawFloor();
        PAction pressed = NOTHING;

        while (pressed) {
            pressed = rendering.winda();
            if (pressed == LEFT) {
                pressed = actions.move(PAction::LEFT);
                rendering.drawFloor();
            }
            else if (pressed == RIGHT) {
                pressed = actions.move(PAction::RIGHT);
                rendering.drawFloor();
            }
            else if (pressed == UP) {
                pressed = actions.move(PAction::UP);
                rendering.drawFloor();
            }
            else if (pressed == DOWN) {
                pressed = actions.move(PAction::DOWN);
                rendering.drawFloor();
            }
            if (pressed == WIN){
                pressed = ruleEnd.GetInt(per.getQuantity()-1);
                if (pressed == NOTHING){
                    pressed = actions.move(PAction::NOTHING);
                    rendering.drawFloor();
                    continue;
                }
                printf("You have completed the map №%d in %d steps, with %d enemy!!!", code_of_map, per.persons[0]->getStep(), per.start_quantity);
                pressed = END;
            }
            if (pressed == DEAD){
                printf("You died on the map №%d", code_of_map);
                pressed = END;
            }
        }
    };
};
