#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class GameOfLife {
public:
    enum Pattern { GLIDER, GOSPER_GUN, R_PENTOMINO, SPACESHIP };

    GameOfLife(int width = 80, int height = 60);
    void run();
    
    void randomize(float density = 0.3f);
    void clear();
    void addPattern(int x, int y, Pattern pattern);
    void cyclePattern();
    void update();

private:
    void initializeGrid();
    void resizeWindow();
    bool isValidCell(int x, int y);
    void getCellCoordinates(int& x, int& y);
    void updatePopulation();
    int countLiveNeighbors(int x, int y);
    void handleEvents();
    void render();
    void drawGrid();
    void drawCells();
    void drawInfo();

    // Конфигурация
    int cellSize;
    int gridWidth;
    int gridHeight;
    
    // Состояние игры
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;
    bool isPaused;
    bool showInfo;
    bool toroidalWorld;
    bool showGrid;
    float updateSpeed;
    int generation;
    int population;
    Pattern currentPattern;

    // Графика
    sf::RenderWindow window;
    sf::Font font;
    sf::Text infoText;
    sf::Color aliveColor;
    sf::Color deadColor;
    sf::Color gridColor;
};

#endif // GAME_OF_LIFE_H