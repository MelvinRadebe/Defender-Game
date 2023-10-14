#include "GameStateManager.h"

GameStateManager::GameStateManager() {}

GameStateManager::~GameStateManager() {}
// responsible for state movement transitions.
void GameStateManager::replaceState(unique_ptr<GameState> state)
{
    _state = move(state);
}
// responsible for processing and rendering of the current state.
void GameStateManager::processState()
{
    _state->intialiser();
}
// Responsible for returning the state.
unique_ptr<GameState> &GameStateManager::getCurrentState()
{
    return _state;
}
