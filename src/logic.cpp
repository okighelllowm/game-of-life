#include "game_of_life.h"

bool GameOfLife::isValidCell(int x, int y) {
    if (toroidalWorld) return true;
    return x >= 0 && x < gridWidth && y >= 0 && y < gridHeight;
}

void GameOfLife::getCellCoordinates(int& x, int& y) {
    if (toroidalWorld) {
        x = (x + gridWidth) % gridWidth;
        y = (y + gridHeight) % gridHeight;
    }
}

int GameOfLife::countLiveNeighbors(int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            
            int nx = x + dx;
            int ny = y + dy;
            
            if (toroidalWorld) {
                nx = (nx + gridWidth) % gridWidth;
                ny = (ny + gridHeight) % gridHeight;
                if (grid[ny][nx]) count++;
            } else {
                if (nx >= 0 && nx < gridWidth && ny >= 0 && ny < gridHeight) {
                    if (grid[ny][nx]) count++;
                }
            }
        }
    }
    return count;
}

void GameOfLife::update() {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            int neighbors = countLiveNeighbors(x, y);
            nextGrid[y][x] = (grid[y][x] && (neighbors == 2 || neighbors == 3)) || 
                            (!grid[y][x] && neighbors == 3);
        }
    }
    
    grid.swap(nextGrid);
    generation++;
    updatePopulation();
}