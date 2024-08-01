cmake_minimum_required(VERSION 3.23)
project(Rocket_Pro C)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 99)


file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(file ${files})
get_filename_component(name ${file} NAME)
add_executable(${name} ${file} main.c central_val_init.c central_val_solver.c chorin_projection_solver.c gauss_seidel_solver.c
        next_field_init.c node_init.c optimizer.c other_field_init.c PDE_solver.c prev_field_init.c tent_field_init.c)
endforeach()