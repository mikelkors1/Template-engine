#pragma once

#include "parser/loggers/logger_out_file.h"
#include "parser/loggers/logger_in_file.h"
#include <string>
#include <map>
#include <vector>

namespace parser {

class TemplateParser {
public:
    TemplateParser(const std::string& path_to_temp, const std::string& path_to_out, std::map<std::string,std::string> data);

    bool IsValid();

    void parse();
private:
    std::string path_to_templ_;
    std::string path_to_output_;
    std::vector<std::string> lines;
    std::map<std::string,std::string> dict_;

    bool valid_ = true;
};

} //namespace parser