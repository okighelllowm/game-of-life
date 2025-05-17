#include "game_of_life.h"
#include <random>
#include <sstream>
#include <cmath>
#include <iostream>

GameOfLife::GameOfLife(int width, int height) : 
    gridWidth(width), gridHeight(height), cellSize(10),
    isPaused(true), showInfo(true), toroidalWorld(true), showGrid(true),
    updateSpeed(0.1f), generation(0), population(0), currentPattern(GLIDER),
    aliveColor(sf::Color::Black), deadColor(sf::Color::White), 
    gridColor(sf::Color(200, 200, 200)) {
    
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Failed to load font, using default\n";
        font = sf::Font();
    }
    
    infoText.setFont(font);
    infoText.setCharacterSize(14);
    infoText.setFillColor(sf::Color::Black);
    infoText.setPosition(5, 5);
    
    initializeGrid();
    resizeWindow();
}

void GameOfLife::run() {
    sf::Clock clock;
    
    while (window.isOpen()) {
        handleEvents();
        
        if (!isPaused && clock.getElapsedTime().asSeconds() > updateSpeed) {
            update();
            clock.restart();
        }
        
        render();
    }
}