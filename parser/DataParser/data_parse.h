#pragma once
#include <string>
#include <map>
#include "parser/loggers/logger_out_file.h"

namespace parser {

class DataParser {
public:
    DataParser(const std::string& path);

    std::map<std::string,std::string> GetDict();

    void ParseData();

    bool valid();
private:
    std::string path_to_data_;
    std::map<std::string,std::string> dict_;

    bool valid_ = true;
};
    


} //namespace parser