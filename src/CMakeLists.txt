
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.cpp
)

list(APPEND COMMON_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.hpp
)

target_sources(gameobject
    PRIVATE
        ${COMMON_SOURCES}
    PUBLIC
        ${COMMON_HEADERS}
)


target_include_directories(gameobject
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)

message("nngodebug ${CMAKE_CURRENT_SOURCE_DIR}")