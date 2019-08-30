cmake_minimum_required(VERSION 3.0)

add_compile_options(-o3)
aux_source_directory(src KID_SRC)

add_library(kid ${KID_SRC})

add_subdirectory(benchmark)

