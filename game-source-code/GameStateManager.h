#pragma once

#include <memory>
#include "GameState.h"

using namespace std;

class GameStateManager
{
public:
    GameStateManager();
    ~GameStateManager();
    void replaceState(unique_ptr<GameState> state); // responsible for state movement transitions.
    void processState();                            // responsible for processing and rendering of the current state.
    unique_ptr<GameState> &getCurrentState();

private:
    unique_ptr<GameState> _state;
};

// notes Responsible for managing the states of the screen.