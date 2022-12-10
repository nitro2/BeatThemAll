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

if(MSVC OR MSYS OR MINGW) # for detecting Windows compilers
    message("Build on Windows")
    set(SFML_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/SFML/libWindows")
    list(APPEND EXTRA_LIBS
     "${SFML_LIB_PATH}/sfml-audio-d.lib"
     "${SFML_LIB_PATH}/sfml-graphics-d.lib"
     "${SFML_LIB_PATH}/sfml-network-d.lib"
     "${SFML_LIB_PATH}/sfml-system-d.lib"
     "${SFML_LIB_PATH}/sfml-window-d.lib"
    )
    list(APPEND EXTRA_DLL
     "${SFML_LIB_PATH}/sfml-audio-d-2.dll"
     "${SFML_LIB_PATH}/sfml-graphics-d-2.dll"
     "${SFML_LIB_PATH}/sfml-network-d-2.dll"
     "${SFML_LIB_PATH}/sfml-system-d-2.dll"
     "${SFML_LIB_PATH}/sfml-window-d-2.dll"
    )
    file(COPY ${EXTRA_DLL} DESTINATION ${PROJECT_BINARY_DIR}/Debug)
    file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION ${PROJECT_BINARY_DIR}/Debug)
elseif(APPLE) # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
    message("Build on Mac OSX")
    set(SFML_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64")
    list(APPEND EXTRA_LIBS
     "${SFML_LIB_PATH}/libsfml-audio.2.5.dylib"
     "${SFML_LIB_PATH}/libsfml-graphics.2.5.dylib"
     "${SFML_LIB_PATH}/libsfml-network.2.5.dylib"
     "${SFML_LIB_PATH}/libsfml-system.2.5.dylib"
     "${SFML_LIB_PATH}/libsfml-window.2.5.dylib"
    )
elseif(UNIX AND NOT APPLE) # for Linux, BSD, Solaris, Minix
    message("Build on Linux")
    set(SFML_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/SFML/libOSX_x86_64")
    # TODO add SFML dynamic library
    message(FATAL_ERROR "Not add libraries yet")
else() # Undefined
    message(FATAL_ERROR "Undefined build system")
endif()


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
                            PUBLIC ${EXTRA_DLL}
                           )

add_custom_target(assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)
add_dependencies("${ProjectName}" assets)