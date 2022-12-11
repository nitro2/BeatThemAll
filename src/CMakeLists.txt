
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/character.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.cpp
)

list(APPEND COMMON_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/game.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/character.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.hpp
)

target_sources(gamecore
    PRIVATE
        ${COMMON_SOURCES}
    PUBLIC
        ${COMMON_HEADERS}
)


target_include_directories(gamecore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/character"
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
