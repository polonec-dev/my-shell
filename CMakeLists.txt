

cmake_minimum_required(VERSION 4.3.4)

project(Shell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(shell
	src/main.cpp
	src/interface.cpp
)