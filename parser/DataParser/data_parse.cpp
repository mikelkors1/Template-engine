#include "data_parse.h"

namespace parser {

static std::string Trim(const std::string& line) {
    if (line.empty()) {
        return "";
    }
    
    size_t l = 0;
    while (l < line.size() && line[l] == ' ') {
        ++l;
    }

    if (l == line.size()) {
        return "";
    }

    size_t r = line.size() - 1;
    while(r >= l && line[r] == ' ') {
        --r;
    }

    return line.substr(l, r - l + 1);
}

DataParser::DataParser(const std::string& path) 
    : path_to_data_(path) 
    {}

std::map<std::string,std::string> DataParser::GetDict() {
    return dict_;
}

bool DataParser::valid() {
    return valid_;
}

void DataParser::ParseData() {
    DataLogger p(path_to_data_);
    if (!p.valid()) {
        valid_ = false;
    }

    p.parse();
    auto lines = p.GetData();

    if (lines.empty()) {
        return;
    }
    
    for (int i = lines.size() - 1; i >= 0; --i) {
        std::string line = Trim(lines[i]);
        
        if (line.empty() || line[0] == '#' || 
            (line.size() >= 2 && line.substr(0, 2) == "//")) {
            continue;
        }
        
        size_t index = line.find('=');
        if (index == std::string::npos) {
            continue;
        }

        std::string key = Trim(line.substr(0, index));
        std::string value = Trim(line.substr(index + 1));
        
        if (!key.empty() && dict_.find(key) == dict_.end()) {
            dict_[key] = value;
        }
    }
}

} //namespace parser
