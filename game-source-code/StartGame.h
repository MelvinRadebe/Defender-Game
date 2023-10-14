#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
#include "SplashScreen.h"
#include "GameConfig.h" // Include GameConfig header file

class StartGame
{
public:
    StartGame();
    void initialize();
    void createWindow();
    void startScreen();
    void run();
    void processGameState();
    void handleInputAndUpdates();
    void drawCurrentState();

private:
    GameConfig config; // Create an instance of GameConfig
    sf::Clock clock;
    std::shared_ptr<GameStateManager> manager = std::make_shared<GameStateManager>();
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>();
};
