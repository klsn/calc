
cmake_minimum_required(VERSION 3.10)

project(calc CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions(-g)

add_executable(
	calc 
	./main.cpp
	)

