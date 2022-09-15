cmake_minimum_required(VERSION 3.23)
project(CS_151)

set(CMAKE_CXX_STANDARD 14)
#Module 1
#add_executable(SortNumbers Mod1/HW/SortNumbers/SortNumbers.cpp)
#add_executable(SortCountries Mod1/HW/SortCountries/SortCountries.cpp Mod1/HW/SortCountries/Country.cpp)
#Module 2
add_executable(pi Mod2/review.cpp)
add_executable(DtB Mod2/HW/DecimalToBinary/DecimalToBinary.cpp)

add_executable(DanglingPointers Mod3/Lab/DanglingPointers.cpp)