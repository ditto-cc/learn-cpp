cmake_minimum_required(VERSION 3.16)
project(Strategy)

set(CMAKE_CXX_STANDARD 11)

add_executable(Strategy main.cpp SalesOrder.h Strategy/TaxStrategy.h Context.h Strategy/CNTaxStrategy.h Strategy/USTaxStrategy.h Strategy/DETaxStrategy.h Strategy/TaxStrategyFactory.h Strategy/CNTaxStrategyFactory.h Strategy/DETaxStrategyFactory.h Strategy/USTaxStrategyFactory.h)