#pragma once

#include "FloorBuilder.h"

class FloorDirector {
private:
    FloorBuilder* builder;

public:
    FloorDirector(FloorBuilder* b);

    void setBuilder(FloorBuilder* b);

    void Builder_FloorBuilderTree();

};
