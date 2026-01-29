#include "parser/ValueParser/value_parse.h"

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

static std::string ParseLine(const std::string& line, const std::map<std::string, std::string>& dict) {
    std::string result;
    size_t pos = 0;

    while (pos < line.size()) {
        size_t start = line.find("{{", pos);

        if (start == std::string::npos) {
            result += line.substr(pos);
            break;
        }

        result += line.substr(pos, start - pos);

        size_t end = line.find("}}", start + 2);
        if (end == std::string::npos) {
            throw 4;
        }

        std::string key = Trim(line.substr(start + 2, end - (start + 2)));

        auto it = dict.find(key);
        if (it != dict.end()) {
            result += it->second;
        } else {
            throw 3;
        }
        pos = end + 2;
    }

    return result;
}

TemplateParser::TemplateParser(const std::string& path_to_temp, const std::string& path_to_out,std::map<std::string,std::string> data) 
    : path_to_templ_(path_to_temp), path_to_output_(path_to_out) , dict_(data) 
    {}

bool TemplateParser::IsValid() {
    return valid_;
}

void TemplateParser::parse() {
    DataLogger logger(path_to_templ_);
    if (!logger.valid()) {
        valid_ = false;
    }

    logger.parse();
    auto lines = logger.GetData();

    if (lines.empty()) {
        return;
    }

    LoggerIn LogIn(path_to_output_);
    for (size_t i = 0 ; i < lines.size(); ++i) {
        std::string curr = ParseLine(lines[i], dict_);
        if (i != lines.size()-1) {
            curr += '\n';
        }
        LogIn.LogIn(curr);
    }
}



} //namespace parser