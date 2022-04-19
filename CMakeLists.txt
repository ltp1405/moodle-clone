cmake_minimum_required(VERSION 3.15)
project(moodle-clone VERSION 0.1.0)

file(GLOB APP_SRC CONFIGURE_DEPENDS "Personnel/*.cpp" "School/*.cpp" "UserInterface/*.cpp" "UserInterface/Menu/*.cpp" "utils/*.cpp")

add_executable(moodle-clone ${APP_SRC})

add_custom_target(data_link ALL
	COMMAND ${CMAKE_COMMAND} -E create_symlink
		"${CMAKE_SOURCE_DIR}/data"
		"${CMAKE_CURRENT_BINARY_DIR}/data")
