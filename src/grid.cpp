#include "game_of_life.h"
#include <random>

void GameOfLife::initializeGrid() {
    grid.assign(gridHeight, std::vector<bool>(gridWidth, false));
    nextGrid.assign(gridHeight, std::vector<bool>(gridWidth, false));
}

void GameOfLife::resizeWindow() {
    window.create(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), 
                "Conway's Game of Life", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
}

void GameOfLife::randomize(float density) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            grid[y][x] = dis(gen) < density;
        }
    }
    generation = 0;
    updatePopulation();
}

void GameOfLife::clear() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), false);
    }
    generation = 0;
    population = 0;
}

void GameOfLife::updatePopulation() {
    population = 0;
    for (const auto& row : grid) {
        for (bool cell : row) {
            if (cell) population++;
        }
    }
}