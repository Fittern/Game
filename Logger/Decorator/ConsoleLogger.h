#pragma once

#include <iostream>
#include "../Subject.h"
#include "Decorator.h"

class ConsoleLogger:public Decorator{
public:
    ConsoleLogger(LoggerImplication* log): Decorator(log){};
    ~ConsoleLogger() override;
    void Out(Subject* sub) override;
};
