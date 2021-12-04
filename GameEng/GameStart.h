#pragma once

#include <ctime>

#include "../Floor/FloorDirector.h"
#include "../Floor/FloorBuilderTree.h"
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


class GameStart {
public:
    static void StartGame();
};
