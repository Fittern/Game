#ifndef GAME_GAMESTART_H
#define GAME_GAMESTART_H

#include "Floor/FloorDirector.h"
#include "Floor/FloorBuilderTree.h"
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

class GameStart {
public:
    static void StartGame();
};


#endif //GAME_GAMESTART_H
