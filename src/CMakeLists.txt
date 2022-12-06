
list(APPEND COMMON_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.cpp
)

list(APPEND COMMON_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/gameobject.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/character/character.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/weapon/weapon.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.hpp
)

target_sources(gameobject
    PRIVATE
        ${COMMON_SOURCES}
    PUBLIC
        ${COMMON_HEADERS}
)


target_include_directories(gameobject
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/character"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/weapon"
)

message("nngodebug ${CMAKE_CURRENT_SOURCE_DIR}")