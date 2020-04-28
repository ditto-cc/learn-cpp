cmake_minimum_required(VERSION 3.16)
project(AbstractFactory)

set(CMAKE_CXX_STANDARD 11)

add_executable(AbstractFactory Factory Product main.cpp DBDao.h)