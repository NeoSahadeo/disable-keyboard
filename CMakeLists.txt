cmake_minimum_required(VERSION 4.4.3)

project(disable-keyboard C)

include(GNUInstallDirs)

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(disable-keyboard evtest.c)

install(TARGETS disable-keyboard DESTINATION ${CMAKE_INSTALL_BINDIR})
