
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/map.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/character.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/knight.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/ninja.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/skeleton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/warrior.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/wizard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug/grid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug/box.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/obstruction/wall.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/select_character_screen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/transform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/spring.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/spring_text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/collision_detection.cpp
)

list(APPEND COMMON_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/game.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/character.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/map.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug/grid.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug/box.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/obstruction/wall.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gamecfg.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/select_character_screen.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/transform.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/spring.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/spring_text.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/selector/collision_detection.hpp
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
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/obstruction"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/debug"
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
