cmake_minimum_required (VERSION 3.14)

###############################################################################
# PROJECT
###############################################################################
project(suraimuengine)

# Look for additional cmake modules within this project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${suraimuengine_SOURCE_DIR}/cmake")

###############################################################################
# SUBDIRECTORIES
###############################################################################
add_subdirectory(libsuraimuengine)
add_subdirectory(tests)