cmake_minimum_required(VERSION 3.25)
project(ExelParser LANGUAGES CXX)

find_package(libxlsxwriter REQUIRED)
find_package(libqrencode REQUIRED)
find_package(PNG REQUIRED)


#глобальные настройки с++ стандарта :
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_C_EXTENSIONS off)

add_subdirectory(src/ExelParser/librarys)
add_subdirectory(src/ExelParser/Executable)