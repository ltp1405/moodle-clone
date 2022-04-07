cmake_minimum_required(VERSION 3.0.0)
project(moodle-clone VERSION 0.1.0)

file(GLOB APP_SRC CONFIGURE_DEPENDS "Personnel/*.cpp" "School/*.cpp" "UserInterface/*.cpp" "UserInterface/Menu/*.cpp" "utils/*.cpp")
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(moodle-clone ${APP_SRC})
