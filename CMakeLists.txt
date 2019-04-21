cmake_minimum_required(VERSION 3.13)

project(init)
project(key_gen)
project(encrypt)
project(decrypt)
project(test)

set(CMAKE_C_STANDARD 11)

include_directories("./")

add_executable(init init.c)
add_executable(key_gen key_gen.c)
add_executable(encrypt encrypt.c)
add_executable(decrypt decrypt.c)
add_executable(test test.c)