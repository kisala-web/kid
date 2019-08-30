cmake_minimum_required(VERSION 3.0)

add_compile_options(-o3)

link_libraries(
    kid
)

add_executable(rand rand.cc)
add_executable(uuid uuid.cc)