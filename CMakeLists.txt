cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcd_read)

find_package(PCL 1.8 REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
link_libraries(stdc++fs)
link_libraries(-lstdc++fs)

add_executable (pcd_read read.cpp)
#add_executable (pcd_read pcl_visualizer_demo.cpp)

target_link_libraries (pcd_read ${PCL_LIBRARIES})