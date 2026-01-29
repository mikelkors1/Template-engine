#include <iostream>
#include "parser/ArgueParser/argue_parser.h"
#include "parser/DataParser/data_parse.h"
#include "parser/ValueParser/value_parse.h"

using namespace parser;

int main(int argc, char** argv) {
    ArgParser v(argc, argv);
    v.parse();

    if (!v.IsValid()) {
        std::cerr << "ERROR";
        throw 2;
    }

    Paths paths = v.GetParseObj();

    DataParser data_file(paths.GetDataPath());

    if (!data_file.valid()) {
        std::cerr << "ERROR";
        return 1;
    }

    data_file.ParseData();
    std::map<std::string,std::string> dict = data_file.GetDict();

    TemplateParser s(paths.GetTemplPath(), paths.GetOutputPath(), dict);
    s.parse();

    if (s.IsValid()) {
        std::cout << "succesfull parse";
        return 0;
    } else {
        std::cerr << "ERROR";
        throw 4;
    }
}
