cmake_minimum_required(VERSION 3.15)
project(DemoGame)
include(WynterStorm/CMakeLists.txt)

define_game(DemoGame
    MODULES
    Core
    Platform_Sokol)