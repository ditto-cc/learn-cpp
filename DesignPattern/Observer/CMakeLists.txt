cmake_minimum_required(VERSION 3.16)
project(Observer)

set(CMAKE_CXX_STANDARD 11)

add_executable(Observer main.cpp FileProcess.h Form.h MainForm.h FileProcessProgress.h ProgressBar.h ConsoleObserver.h)