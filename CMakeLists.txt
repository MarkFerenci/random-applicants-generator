cmake_minimum_required(VERSION 3.5)
project(RandomApplicantDataGenerator)

set(CMAKE_CXX_STANDARD 23)

add_executable(generator generator.cc)

target_compile_options(generator PRIVATE -O3 -Wall -Werror)