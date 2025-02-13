add_library(lib)


target_link_libraries(lib 
PRIVATE
fmt::fmt
xlnt::xlnt)

#Добавляет в таргет исходные файлы
target_sources(lib
PRIVATE
 Lib.cpp
PUBLIC
 includes/Lib/Lib.hpp
)

#команда для препроцессора и компилятора, 
#подключает в таргет проекта папки для препроцессора и компилятора 
#(при включении заголовочного файла в исполняемый файл, 
#помогает препроцессору и компилятору обнаружить 
#заголовочник и его исполняемый файл )
target_include_directories(lib PUBLIC includes)

add_library(Cmake_example::lib ALIAS lib)