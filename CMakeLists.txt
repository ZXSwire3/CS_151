cmake_minimum_required(VERSION 3.23)
project(CS_151)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortNumbers Mod1/HW1/SortNumbers/main.cpp)
add_executable(SortCountries Mod1/HW1/SortCountries/main.cpp Mod1/HW1/SortCountries/Country.cpp)