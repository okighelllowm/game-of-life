#include "game_of_life.h"

void GameOfLife::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Space: isPaused = !isPaused; break;
                case sf::Keyboard::R: randomize(); break;
                case sf::Keyboard::C: clear(); break;
                case sf::Keyboard::G: addPattern(0, 0, currentPattern); break;
                case sf::Keyboard::P: cyclePattern(); break;
                case sf::Keyboard::I: showInfo = !showInfo; break;
                case sf::Keyboard::T: toroidalWorld = !toroidalWorld; break;
                case sf::Keyboard::L: showGrid = !showGrid; break;
                case sf::Keyboard::Up: updateSpeed = std::max(0.01f, updateSpeed * 0.8f); break;
                case sf::Keyboard::Down: updateSpeed = std::min(1.0f, updateSpeed * 1.2f); break;
                case sf::Keyboard::Right: cellSize++; resizeWindow(); break;
                case sf::Keyboard::Left: if (cellSize > 2) { cellSize--; resizeWindow(); } break;
                case sf::Keyboard::Escape: window.close(); break;
                default: break;
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / cellSize;
                int y = event.mouseButton.y / cellSize;
                if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
                    grid[y][x] = !grid[y][x];
                    updatePopulation();
                }
            }
        }
        else if (event.type == sf::Event::MouseMoved) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                int x = event.mouseMove.x / cellSize;
                int y = event.mouseMove.y / cellSize;
                if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
                    grid[y][x] = true;
                    updatePopulation();
                }
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                int x = event.mouseMove.x / cellSize;
                int y = event.mouseMove.y / cellSize;
                if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
                    grid[y][x] = false;
                    updatePopulation();
                }
            }
        }
    }
}