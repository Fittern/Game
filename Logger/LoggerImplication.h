#pragma once

#include "Subject.h"

class LoggerImplication{
public:
    virtual void Out(Subject* sub) = 0;
    virtual ~LoggerImplication() = default;
};