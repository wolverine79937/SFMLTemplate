cmake_minimum_required(VERSION 3.21)

project(shooter)
set(EXECUTABLE_NAME "template")
set(shooter_VERSION_MAJOR 0)
set(shooter_VERSION_MINOR 0)

set(CMAKE_BINARY_DIRECTORY "dist")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "dist")

if(NOT SFML_DIR)
	set(SFML_DIR "/usr/local")
endif()

add_compile_options("-I.")

if(APPLE)
	add_compile_options("-I${SFML_DIR}/include")
	add_link_options("-F${SFML_DIR}/Frameworks")
	add_link_options("-Wl,-rpath,${SFML_DIR}/Frameworks")
	link_libraries("-framework sfml-graphics")
	link_libraries("-framework sfml-window")
	link_libraries("-framework sfml-system")
elseif(UNIX)
	add_compile_options("-I${SFML_DIR}/include")
	add_link_options("-F${SFML_DIR}/lib")
	link_libraries("-lsfml-graphics")
	link_libraries("-lsfml-window")
	link_libraries("-lsfml-system")
endif()

configure_file("src/config.hh.in" "config.hh")

file(GLOB_RECURSE src src/*.cpp src/*.hh)
# file(GLOB_RECURSE media media/*)

add_executable(${EXECUTABLE_NAME} "${src}")
# file(COPY "Media" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")