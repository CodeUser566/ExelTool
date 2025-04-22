add_executable(executable)
target_sources(executable
PRIVATE
 main.cpp)


target_link_libraries(executable
PRIVATE
Cmake_example::lib
libxlsxwriter::libxlsxwriter
libqrencode::libqrencode
PNG::PNG)