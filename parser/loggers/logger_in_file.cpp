#include "logger_in_file.h"

namespace parser {

LoggerIn::LoggerIn(const std::string& path) {
    std::string real_path = path.empty() ? "output.txt" : path;
    in.open(real_path, std::ios::app);
    if (!in.is_open()) {
        valid_ = false;
    }
}

LoggerIn::~LoggerIn() {
    in.close();
}

void LoggerIn::LogIn(const std::string& messege) {
    in << messege;
}

bool LoggerIn::valid() {
    return valid_;
}

} //namespace parser