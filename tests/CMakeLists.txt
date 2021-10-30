cmake_minimum_required(VERSION 3.14)

###############################################################################
# GOOGLETEST
###############################################################################
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

###############################################################################
# PROJECT
###############################################################################
project (testrunner)

###############################################################################
# SOURCES
###############################################################################
set (TEST_SRCS 
    src/testrunner.cpp
    src/game/gametest.cpp
)

###############################################################################
# RESOURCES
###############################################################################
set (TEST_RESOURCES
)
file(COPY ${TEST_RESOURCES} DESTINATION resources)

###############################################################################
# TARGETS
###############################################################################
add_executable(${PROJECT_NAME} ${TEST_SRCS})
# Use C++11
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

###############################################################################
# LINK
###############################################################################
target_link_libraries(${PROJECT_NAME} gtest libsuraimuengine)
