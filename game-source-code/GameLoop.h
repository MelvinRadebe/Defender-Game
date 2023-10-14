#pragma once

#include "GameEngine.h"
#include "GameConfig.h"
// Make sure to include the header file for the Game class

using namespace std;

class GameLoop
{
public:
  GameLoop(); // constructor
  void run(); // method to start the game loop
private:
  GameConfig gameConfig; // game configuration object
  Game game;             // game object
  void initGame();       // method to initialize game
};