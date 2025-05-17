#include "game_of_life.h"
#include <sstream>
#include <cmath>

void GameOfLife::drawGrid() {
    if (showGrid && cellSize > 4) {
        for (int x = 0; x <= gridWidth; ++x) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x * cellSize, 0), gridColor),
                sf::Vertex(sf::Vector2f(x * cellSize, gridHeight * cellSize), gridColor)
            };
            window.draw(line, 2, sf::Lines);
        }
        
        for (int y = 0; y <= gridHeight; ++y) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, y * cellSize), gridColor),
                sf::Vertex(sf::Vector2f(gridWidth * cellSize, y * cellSize), gridColor)
            };
            window.draw(line, 2, sf::Lines);
        }
    }
}

void GameOfLife::drawCells() {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            if (grid[y][x]) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - (showGrid ? 1 : 0), 
                                  cellSize - (showGrid ? 1 : 0)));
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(aliveColor);
                window.draw(cell);
            }
        }
    }
}

void GameOfLife::drawInfo() {
    if (showInfo) {
        std::ostringstream oss;
        oss << "Generation: " << generation << "\n"
            << "Population: " << population << "\n"
            << "Speed: " << std::round(1.0f / updateSpeed) << " updates/sec\n"
            << "Cell size: " << cellSize << "px\n"
            << "Grid: " << gridWidth << "x" << gridHeight << "\n"
            << "World: " << (toroidalWorld ? "Toroidal" : "Bounded") << "\n"
            << "Pattern: ";
            
        switch (currentPattern) {
            case GLIDER: oss << "Glider"; break;
            case GOSPER_GUN: oss << "Gosper Gun"; break;
            case R_PENTOMINO: oss << "R-pentomino"; break;
            case SPACESHIP: oss << "Spaceship"; break;
        }
        
        oss << "\n\nControls:\n"
            << "Space - Pause/Resume\n"
            << "R - Randomize\n"
            << "C - Clear\n"
            << "G - Add pattern\n"
            << "P - Cycle patterns\n"
            << "T - Toggle world\n"
            << "L - Toggle grid\n"
            << "I - Toggle info\n"
            << "Up/Down - Change speed\n"
            << "Left/Right - Change cell size\n"
            << "Click/Drag - Draw cells\n"
            << "Right drag - Erase cells";
        
        infoText.setString(oss.str());
        window.draw(infoText);
    }
}

void GameOfLife::render() {
    window.clear(deadColor);
    drawGrid();
    drawCells();
    drawInfo();
    window.display();
}
