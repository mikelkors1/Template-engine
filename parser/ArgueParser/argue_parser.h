#pragma once
#include <string>

namespace parser {

class ArgParser;

class Paths {
    friend class ArgParser;
public:
    std::string GetTemplPath();
    std::string GetDataPath();
    std::string GetOutputPath();

    bool IsTempleEven();
    bool IsOutputEven();
    bool IsDataEven();

    void SetTemplate(const std::string& templ_path);
    void SetOutPut(const std::string& output_path);
    void SetData(const std::string& data_path);
private:
    Paths() = default;
    
    std::string template_file;
    std::string data_file;
    std::string output_file;
};

class ArgParser {
public:
    ArgParser(int a, char** args);

    bool IsValid();

    void parse();

    Paths& GetParseObj();
private:
    int argc;
    char** argv;

    bool valid = true;

    Paths value;
};




} //namespace parser