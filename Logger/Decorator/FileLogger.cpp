#include "FileLogger.h"

FileLogger::~FileLogger(){
    output.close();
    delete [] logger;
}
void FileLogger::Out(Subject* sub) {
    Decorator::Out(sub);
    output << sub;
}

FileLogger::FileLogger(LoggerImplication *log) : Decorator(log) {
    output.open("/home/denis/CLionProjects/Game/Logger/log.txt");
    if (output.fail())
    {
        throw std::iostream::failure("Cannot open file: log.txt");
    }
}
