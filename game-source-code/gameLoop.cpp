#include "GameLoop.h"

GameLoop::GameLoop()
{
    // Set up gameConfig here
    // Example: gameConfig.setWindowWidth(800);
    // gameConfig.setWindowHeight(600);
    // ... configure other parameters ...
    initGame(); // initialize game with the configured gameConfig object
}

void GameLoop::initGame()
{
    game.initWindow(gameConfig); // Initialize the window using the configured GameConfig object
}

void GameLoop::run()
{
    while (game.isPlaying())
    {
        game.update(); // update game state
        game.render(); // render game state
    }
}
