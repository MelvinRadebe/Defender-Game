#pragma once

#include "GameStateManager.h"
#include "GameState.h"
#include "StartGame.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SplashScreen : public GameState
{
public:
    SplashScreen(shared_ptr<GameStateManager> manager, shared_ptr<RenderWindow> window);

    void handleInput() override;
    void update(float dt) override;
    void draw() override;
    void intialiser() override;

private:
    shared_ptr<GameStateManager> _manager;
    shared_ptr<RenderWindow> _window;
    Clock clock;
    Font font;
    Font font2;
    Text text;
    Texture backgroundTexture;  // Added for background
    Sprite backgroundSprite;    // Added for background
    sf::Clock colorSwitchTimer; // Added for color switching text
    bool isWhiteColor;          // Added for color switching textt
    sf::Text instructions;
};
