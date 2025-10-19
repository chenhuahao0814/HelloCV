cmake_minimum_required(VERSION 3.10)
project(CryptoTool LANGUAGES CXX)
include_directories(includes)
add_executable(My_cryptoTool 
    src/Crypto.cpp 
    src/FileHandler.cpp 
    src/Menu.cpp 
    src/main.cpp
)
