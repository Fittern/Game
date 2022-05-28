#pragma once

#include "../Floor/FloorBuilder.h"
#include "../Floor/FloorBuilderConst.h"
#include "../Floor/FloorBuilderTree.h"
#include "../Floor/FloorDirector.h"
#include "../Graphics/MyTexture/MyTexture.h"

template <int T>
class RulesBuilder{
private:
    int builderID = T;
    int now_code = 0;
public:
    Floor* GetFloorFromBuilder(){
        MyTexture game_texture;
        FloorBuilder* builder;
        if(builderID == 0){
            builder = new FloorBuilderConst(game_texture);
        }
        else if(builderID < 0){
            unsigned int a = time(0);
            now_code = a;
            srand(static_cast<unsigned int>(a));
            builder = new FloorBuilderTree(game_texture);
        }
        else{
            srand(static_cast<unsigned int>(T));
            builder = new FloorBuilderTree(game_texture);
        }
        auto director = FloorDirector(builder);
        director.Builder_FloorBuilderTree();
        Floor* floor = builder->getFloor();
        delete builder;
        return floor;
    }
    int GetInt(){
        if(builderID >= 0) {
            return builderID;
        }
        else{
            return now_code;
        }
    }
};