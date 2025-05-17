set(SOURCES
    main.cpp
    init.cpp
    grid.cpp
    patterns.cpp
    logic.cpp
    render.cpp
    input.cpp
)

add_executable(life_game ${SOURCES})

target_include_directories(life_game 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(life_game
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)