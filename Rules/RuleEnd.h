#pragma once

#include "../Elem/Person/IPerson.h"

template <int T>
class RuleEnd{
private:
    int End_ID = T;
public:
    PAction GetInt(int q_now){
        if (End_ID < 0){
            return PAction::WIN;
        }
        else if(End_ID >= q_now) {
            return PAction::WIN;
        }
        else{
            return PAction::NOTHING;
        }
    }
};