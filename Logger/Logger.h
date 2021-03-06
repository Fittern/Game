#pragma once

#include "Observer.h"
#include "Subject.h"
#include "LoggerImplication.h"

class Logger:public Observer{
protected:
    static Logger* logger;
    Subject* subject;
    LoggerImplication* log;
    Logger(Subject* sub, LoggerImplication* log): subject(sub), log(log){}

public:
    Logger(Logger &other) = delete;
    void operator=(const Logger &) = delete;
    static Logger* GetInstance(Subject* sub, LoggerImplication* log);
    void Update() final;
};
