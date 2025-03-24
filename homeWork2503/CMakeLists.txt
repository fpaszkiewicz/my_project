cmake_minimum_required(VERSION 3.16)

project(homeWork2503 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(homeWork2503 main.cpp
    Time.h
    Time.cpp
    invoice.h invoice.cpp
    item.h item.cpp)

include(GNUInstallDirs)
install(TARGETS homeWork2503
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
