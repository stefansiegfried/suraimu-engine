cmake_minimum_required(VERSION 3.14)
###############################################################################
# NLOHMANN::JSON LIBRARY
###############################################################################
include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.10.4
)
FetchContent_MakeAvailable(nlohmann_json)
## Do not build nlohmann_json tests
set(JSON_BuildTests OFF CACHE INTERNAL "")

###############################################################################
# PROJECT
###############################################################################
project (libsuraimuengine)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

###############################################################################
# SOURCES
###############################################################################
set (LIB_SRCS
    src/game.cpp
)

###############################################################################
# TARGETS
###############################################################################
add_library(${PROJECT_NAME} ${LIB_SRCS})

# Disable automatic 'lib' prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
# Use C++11
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

###############################################################################
# INCLUDES
###############################################################################
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS}
)

###############################################################################
# LINK
###############################################################################
target_link_libraries(${PROJECT_NAME}
    PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES}
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE nlohmann_json::nlohmann_json
)