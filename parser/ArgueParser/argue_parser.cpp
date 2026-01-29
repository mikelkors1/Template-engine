#include "argue_parser.h"

namespace parser {

Paths& ArgParser::GetParseObj() {
    return value;
}

std::string Paths::GetDataPath() {
    if (data_file.empty()) {
        return "";
    }
    return data_file;
}

std::string Paths::GetOutputPath() {
    if (output_file.empty()) {
        return "";
    }
    return output_file;
}

std::string Paths::GetTemplPath() {
    if (template_file.empty()) {
        return "";
    }
    return template_file;
}

bool Paths::IsDataEven() {
    if (!data_file.empty()) {
            return true;
    }
    return false;
}

bool Paths::IsOutputEven() {
    if (!output_file.empty()) {
        return true;
    }
    return false;
}

bool Paths::IsTempleEven() {
    if (!template_file.empty()) {
        return true;
    }
    return false;
}

void Paths::SetTemplate(const std::string& templ_path) {
    if (templ_path.empty()) {
        template_file = "";
    }
    template_file = templ_path;
}

void Paths::SetData(const std::string& data_path) {
    if (data_path.empty()) {
        data_file = "";
    }
    data_file = data_path;
}

void Paths::SetOutPut(const std::string& output_path) {
    if (output_path.empty()) {
            output_file = "";
    }
    output_file = output_path;
}

ArgParser::ArgParser(int a, char** args) 
    : argc(a) , argv(args) 
    {}

bool ArgParser::IsValid() {
    return valid;
}

void ArgParser::parse() {
    if (argc <= 1) {
        valid = false;
    }

    for (int i = 1; i < argc; ++i) {
        std::string curr_arg = argv[i];
        if (curr_arg.substr(0,11) == "--template=") {
            value.SetTemplate(curr_arg.substr(11));
        } else if (curr_arg == "-t" && i + 1 < argc) {
            value.SetTemplate(argv[++i]);
        } else if (curr_arg.substr(0,9) == "--output=") {
            value.SetOutPut(curr_arg.substr(9));
        } else if (curr_arg == "-o" && i + 1 < argc) {
            value.SetOutPut(argv[++i]);
        } else if (curr_arg.substr(0,7) == "--data=") {
            value.SetData(curr_arg.substr(7));
        } else if (curr_arg == "-d"  && i + 1 < argc) {
            value.SetData(argv[++i]);
        } else {
            valid = false;
        }
    }

    if (!value.IsTempleEven() || !value.IsDataEven()) {
        valid = false;
    }
}

} //namespace parser
