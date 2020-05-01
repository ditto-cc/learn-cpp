cmake_minimum_required(VERSION 3.16)
project(Singleton)

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_CXX_FLAGS "-lpthread -std=c++11 ${CMAKE_CXX_FLAGS}")
add_executable(Singleton main.cpp Singleton1.h Singleton2.h Singleton3.h Singleton4.h Singleton5.h)