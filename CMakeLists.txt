cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(whatever)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

find_package(PCL 1.8 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3)

include_directories(include)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# TODO rename this
add_executable (main main.cc)
target_link_libraries (main ${PCL_LIBRARIES} ${OpenCV_LIBS})
