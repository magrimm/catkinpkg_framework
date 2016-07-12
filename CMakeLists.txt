cmake_minimum_required(VERSION 2.8.3)
project(catkinpkg_framework)

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

add_definitions(-std=c++11)

#############
# LIBRARIES #
#############
cs_add_library(${PROJECT_NAME}
        src/framework_processor.cpp)

############
# BINARIES #
############
cs_add_executable(catkinpkg_framework_node
        src/catkinpkg_framework_node.cpp)
target_link_libraries(catkinpkg_framework_node ${PROJECT_NAME})

##########
# EXPORT #
##########
cs_install()
cs_export()