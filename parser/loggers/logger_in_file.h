#pragma once

#include <fstream>
#include <string>

namespace parser {
    
class LoggerIn {
public:
    LoggerIn(const std::string& path);

    void LogIn(const std::string& messege);

    bool valid();

    ~LoggerIn();
private:
    std::fstream in;
    bool valid_ = true;
};

} // namespace name
