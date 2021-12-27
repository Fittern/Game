#pragma once

#include "../Elem.h"

class IItem: public Elem {
public:
    virtual int getId() const = 0;
    virtual void setId(int id) = 0;
    virtual Type_of_item getItem() = 0;
    virtual void setDead() = 0;
    virtual std::string getIsLive() = 0;
    virtual int getIdSt() const = 0;
    virtual void setIdSt(int idSt) = 0;
    virtual Coords &getPosition() = 0;
};