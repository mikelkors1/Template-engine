#include "logger_out_file.h"

namespace parser {

DataLogger::DataLogger(const std::string& path) : in(path) {
        if (!in.is_open()) {
            valid_ = false;
        }
    }

void DataLogger::parse() {
    std::string buff;
    while (getline(in,buff)) {
        data_.push_back(buff);
    }
}

bool DataLogger::valid() {
    return valid_;
}

std::vector<std::string> DataLogger::GetData() {
        return data_;
}

DataLogger::~DataLogger() {
    in.close();
}

}