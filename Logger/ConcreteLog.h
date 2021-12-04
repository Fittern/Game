#pragma once

#include "LoggerImplication.h"

class ConcreteLog: public LoggerImplication{
public:
    ConcreteLog(){};
    void Out(Subject* sub) override{};
};
