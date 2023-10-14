#pragma once

#include <SFML/Graphics.hpp>

class SplashScreen {
public:
    SplashScreen(sf::RenderWindow* parentWindow);

    void showSplashScreen();

private:
    sf::RenderWindow* window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text text;
};
