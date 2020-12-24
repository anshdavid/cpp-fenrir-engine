cmake_minimum_required(VERSION 3.16)
project(fenrir)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

link_directories(${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
    fenrir.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/vendor/*.h
    ${PROJECT_SOURCE_DIR}/vendor/*.hpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/vendor)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

#######################################
# LOOK for the packages that we need! #
#######################################

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    link_libraries(${OPENGL_LIBRARIES})
    message(STATUS "OpenGL included at ${OPENGL_INCLUDE_DIR}")
endif()

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
    message(STATUS "GLEW included at ${GLEW_INCLUDE_DIRS}")
endif()

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
include_directories(${SDL2_INCLUDE_DIR})
    message(STATUS "found sdl2")
endif()

find_package(SDL2_image REQUIRED)
if (SDL2_image_FOUND)
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})
    message(STATUS "found SDL2_image_FOUND")
endif()

find_package(SDL2_ttf REQUIRED)
if (SDL2_ttf_FOUND)
    include_directories(${SDL2_TTF_INCLUDE_DIR})
    message(STATUS "found SDL2_ttf_FOUND")
endif()

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)
