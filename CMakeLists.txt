cmake_minimum_required(VERSION 3.17)
project(ProiectPDP)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
add_executable(ProiectPDP main.cpp Disponibilitate.h Profesor.h Clasa.h Materie.h Orar.h Controller.h)
target_link_libraries(ProiectPDP ${Boost_LIBRARIES})