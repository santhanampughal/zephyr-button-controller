cmake_minimum_required(VERSION 3.20.0)
find_pacakge(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zl2_button)
target_sources(app PRIVATE src.main.c)