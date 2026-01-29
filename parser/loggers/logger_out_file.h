#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace parser {

class DataLogger {
    friend class TemplateParser;
    friend class DataParser;
public:
    void parse();

    std::vector<std::string> GetData();

    bool valid();
private:
    bool valid_ = true;

    DataLogger(const std::string& path);
    ~DataLogger();

    std::fstream in;
    std::vector<std::string> data_;
};

} //namespace parser