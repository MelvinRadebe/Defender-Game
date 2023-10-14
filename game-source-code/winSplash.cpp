#include "WinSplash.h"
#include <iostream>

SplashScreen::SplashScreen(sf::RenderWindow* parentWindow)
    : window(parentWindow)
{
    if (!backgroundTexture.loadFromFile("resources/Outcome.png"))
    {
        std::cout << "Could not load background image" << std::endl;
        return;
    }

    if (!font.loadFromFile("resources/SportypoReguler-OVGwe.ttf"))
    {
        std::cout << "Could not load font" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);

    text.setFont(font);
    text.setString("You Won!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    // Center the text
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(parentWindow->getSize().x / 2.0f, parentWindow->getSize().y / 2.0f);
}

void SplashScreen::showSplashScreen()
{
    sf::RenderWindow splashWindow(sf::VideoMode(700, 400), "You Won!");

    // Main loop for the splash screen
    while (splashWindow.isOpen())
    {
        sf::Event event;
        while (splashWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                splashWindow.close();
            }
        }

        splashWindow.clear();
        splashWindow.draw(backgroundSprite);
        splashWindow.draw(text);
        splashWindow.display();
    }
}
