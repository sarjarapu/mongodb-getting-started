cmake_minimum_required(VERSION 3.14)
project("mongo-demo")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
include_directories(include)
file(GLOB "SOURCES" "src/*.cpp")

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS})

add_compile_options(-Wall -Wextra -Wpedantic)
add_executable("${PROJECT_NAME}" "${SOURCES}")

target_link_libraries("${PROJECT_NAME}" "${LIBMONGOCXX_LIBRARIES}" "${lIBBSONCXX_LIBRARIES}")

