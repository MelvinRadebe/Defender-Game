#pragma once

// Abstract game class for all game states
// Example instructions, start, game over and main game
// State classes will be dervied from this class
class GameState
{
private:
public:
    virtual void intialiser() = 0; ////Have different variable names
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};

// notes
// States are the screen you could name it screenmanager.
