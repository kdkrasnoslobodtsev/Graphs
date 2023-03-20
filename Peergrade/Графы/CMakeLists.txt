cmake_minimum_required(VERSION 3.22)
project(peergrade)

set(CMAKE_CXX_STANDARD 20)

add_executable(peergrade main.cpp help.h help.cpp)
