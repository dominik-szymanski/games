cmake_minimum_required(VERSION 3.10)

# set the project name
project(game)

set(CMAKE_MODULE_PATH "/home/dominik/Dokumenty/projects/games/;${CMAKE_MODULE_PATH}")
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic  -Wunused -O0 -g -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -pedantic  -Wunused -Ofast")

add_library(SFML_Impl sfmlImp/SFMLObject.cpp sfmlImp/SFMLWindowManager.cpp)

# add the executable
add_executable(game main.cpp object.cpp)

# link libraries
message(STATUS ${SFML_LIBRARY} )
target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../box2d/include")
target_link_libraries(game SFML_Impl ${SFML_LIBRARY})
target_link_libraries(game ${CMAKE_CURRENT_SOURCE_DIR}/../box2d/build/src/libbox2d.a)