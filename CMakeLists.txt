cmake_minimum_required(VERSION 3.13)

set(ProjectName BeatThemAll)
# set the project name and version
project("${ProjectName}" VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(BUILD_SHARED_LIBS OFF)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

add_library(gamecore "")
add_subdirectory(src)

list(APPEND EXTRA_LIBS
    "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64/libsfml-audio.2.5.dylib"
    "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64/libsfml-graphics.2.5.dylib"
    "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64/libsfml-network.2.5.dylib"
    "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64/libsfml-system.2.5.dylib"
    "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64/libsfml-window.2.5.dylib"
)
list(APPEND EXTRA_INCLUDES 
    "${PROJECT_SOURCE_DIR}/include"
)


# add the executable
add_executable("${ProjectName}" main.cpp)

target_link_libraries("${ProjectName}"
    PUBLIC ${EXTRA_LIBS}    
    PUBLIC gamecore
)

target_include_directories("${ProjectName}"
    PUBLIC "${PROJECT_SOURCE_DIR}"
    PUBLIC ${EXTRA_INCLUDES}
)
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories("${ProjectName}"
                            PUBLIC "${PROJECT_BINARY_DIR}"
                            PUBLIC ${EXTRA_LIBS}  
                           )
