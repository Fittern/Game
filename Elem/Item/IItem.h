#pragma once

#include "../Elem.h"

class IItem: public Elem {
public:
    virtual Type_of_item getItem() = 0;
};