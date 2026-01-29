cmake_minimum_required(VERSION 3.10.0)
project(generator VERSION 0.1.0 LANGUAGES C CXX)

SET(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_executable(${PROJECT_NAME} 
    main.cpp
    parser/ArgueParser/argue_parser.cpp
    parser/DataParser/data_parse.cpp
    parser/ValueParser/value_parse.cpp
    parser/loggers/logger_out_file.cpp
    parser/loggers/logger_in_file.cpp
)

add_subdirectory(tests)
