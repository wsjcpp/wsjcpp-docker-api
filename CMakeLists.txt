cmake_minimum_required(VERSION 3.0)

project(wsjcpp-docker-api C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-docker-api_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_docker_api.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_docker_api.cpp")

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (wsjcpp-docker-api ${WSJCPP_SOURCES})

target_link_libraries(wsjcpp-docker-api ${WSJCPP_LIBRARIES})

install(
    TARGETS
        wsjcpp-docker-api
    RUNTIME DESTINATION
        /usr/bin
)

