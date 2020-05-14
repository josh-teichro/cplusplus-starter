cmake_minimum_required(VERSION 2.6)
project(myproject)

# Macros
MACRO(GET_DIRECTORIES root_dir return_list)
    FILE(GLOB_RECURSE new_list "${root_dir}/*")
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list} ${root_dir})
ENDMACRO()

# Add project files
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib/include/")
set(INC_DIR "${CMAKE_SOURCE_DIR}/include/")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src/")
GET_DIRECTORIES("${INC_DIR}" INC_DIRS)
GET_DIRECTORIES("${LIB_DIR}" LIB_DIRS)
include_directories("${INC_DIRS}" "${LIB_DIRS}")
file(GLOB_RECURSE SRC_FILES 
    ${LIB_DIR}/*.cpp* 
    ${LIB_DIR}/*.h* 
    ${LIB_DIR}/*.hpp*
    ${INC_DIR}/*.cpp* 
    ${INC_DIR}/*.h* 
    ${INC_DIR}/*.hpp*
    ${SRC_DIR}/*.cpp* 
    ${SRC_DIR}/*.h* 
    ${SRC_DIR}/*.hpp*)
list(APPEND SRC_FILES main.cpp)

# Create filters (visual studio)
foreach(_source IN ITEMS ${SRC_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

# Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Visual studio properties
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
