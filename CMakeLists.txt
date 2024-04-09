cmake_minimum_required(VERSION 3.10)
project(Phonebook VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(Phonebook main.cpp contact.cpp phonebook.cpp userinterface.cpp fsmui.cpp)