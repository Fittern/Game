#pragma once

#include <fstream>
#include <iostream>
#include "../Subject.h"
#include "Decorator.h"

class FileLogger:public Decorator{
private:
    std::ofstream output;
public:
    FileLogger(LoggerImplication* log);
    ~FileLogger() override;
    void Out(Subject* sub) final;
};