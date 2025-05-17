#include "game_of_life.h"

void GameOfLife::addPattern(int x, int y, Pattern pattern) {
    switch (pattern) {
        case GLIDER:
            if (isValidCell(x+1, y)) grid[y][x+1] = true;
            if (isValidCell(x+2, y+1)) grid[y+1][x+2] = true;
            if (isValidCell(x, y+2)) grid[y+2][x] = true;
            if (isValidCell(x+1, y+2)) grid[y+2][x+1] = true;
            if (isValidCell(x+2, y+2)) grid[y+2][x+2] = true;
            break;
            
        case GOSPER_GUN:
            if (isValidCell(x+24, y)) grid[y][x+24] = true;
            
            if (isValidCell(x+22, y+1)) grid[y+1][x+22] = true;
            if (isValidCell(x+24, y+1)) grid[y+1][x+24] = true;
            
            if (isValidCell(x+12, y+2)) grid[y+2][x+12] = true;
            if (isValidCell(x+13, y+2)) grid[y+2][x+13] = true;
            if (isValidCell(x+20, y+2)) grid[y+2][x+20] = true;
            if (isValidCell(x+21, y+2)) grid[y+2][x+21] = true;
            if (isValidCell(x+34, y+2)) grid[y+2][x+34] = true;
            if (isValidCell(x+35, y+2)) grid[y+2][x+35] = true;
            
            if (isValidCell(x+11, y+3)) grid[y+3][x+11] = true;
            if (isValidCell(x+15, y+3)) grid[y+3][x+15] = true;
            if (isValidCell(x+20, y+3)) grid[y+3][x+20] = true;
            if (isValidCell(x+21, y+3)) grid[y+3][x+21] = true;
            if (isValidCell(x+34, y+3)) grid[y+3][x+34] = true;
            if (isValidCell(x+35, y+3)) grid[y+3][x+35] = true;
            
            if (isValidCell(x, y+4)) grid[y+4][x] = true;
            if (isValidCell(x+1, y+4)) grid[y+4][x+1] = true;
            if (isValidCell(x+10, y+4)) grid[y+4][x+10] = true;
            if (isValidCell(x+16, y+4)) grid[y+4][x+16] = true;
            if (isValidCell(x+20, y+4)) grid[y+4][x+20] = true;
            if (isValidCell(x+21, y+4)) grid[y+4][x+21] = true;
            
            if (isValidCell(x, y+5)) grid[y+5][x] = true;
            if (isValidCell(x+1, y+5)) grid[y+5][x+1] = true;
            if (isValidCell(x+10, y+5)) grid[y+5][x+10] = true;
            if (isValidCell(x+14, y+5)) grid[y+5][x+14] = true;
            if (isValidCell(x+16, y+5)) grid[y+5][x+16] = true;
            if (isValidCell(x+17, y+5)) grid[y+5][x+17] = true;
            if (isValidCell(x+22, y+5)) grid[y+5][x+22] = true;
            if (isValidCell(x+24, y+5)) grid[y+5][x+24] = true;
            
            if (isValidCell(x+10, y+6)) grid[y+6][x+10] = true;
            if (isValidCell(x+16, y+6)) grid[y+6][x+16] = true;
            if (isValidCell(x+24, y+6)) grid[y+6][x+24] = true;
            
            if (isValidCell(x+11, y+7)) grid[y+7][x+11] = true;
            if (isValidCell(x+15, y+7)) grid[y+7][x+15] = true;
            
            if (isValidCell(x+12, y+8)) grid[y+8][x+12] = true;
            if (isValidCell(x+13, y+8)) grid[y+8][x+13] = true;
            break;
            
        case R_PENTOMINO:
            if (isValidCell(x+1, y)) grid[y][x+1] = true;
            if (isValidCell(x+2, y)) grid[y][x+2] = true;
            if (isValidCell(x, y+1)) grid[y+1][x] = true;
            if (isValidCell(x+1, y+1)) grid[y+1][x+1] = true;
            if (isValidCell(x+1, y+2)) grid[y+2][x+1] = true;
            break;
            
        case SPACESHIP:
            if (isValidCell(x+1, y)) grid[y][x+1] = true;
            if (isValidCell(x+2, y)) grid[y][x+2] = true;
            if (isValidCell(x+3, y)) grid[y][x+3] = true;
            if (isValidCell(x+4, y)) grid[y][x+4] = true;
            if (isValidCell(x, y+1)) grid[y+1][x] = true;
            if (isValidCell(x+4, y+1)) grid[y+1][x+4] = true;
            if (isValidCell(x+4, y+2)) grid[y+2][x+4] = true;
            if (isValidCell(x, y+3)) grid[y+3][x] = true;
            if (isValidCell(x+3, y+3)) grid[y+3][x+3] = true;
            break;
    }
    updatePopulation();
}

void GameOfLife::cyclePattern() {
    currentPattern = static_cast<Pattern>((currentPattern + 1) % 4);
}