#include "SplashScreen.h"
#include "GameLoop.h"
#include <SFML/System/Clock.hpp>
#include <iostream>

SplashScreen::SplashScreen(std::shared_ptr<GameStateManager> manager, std::shared_ptr<sf::RenderWindow> window)
{
    _window = window;
    _manager = manager;
    colorSwitchTimer.restart();
    isWhiteColor = true; // Initialize as white
}

void SplashScreen::intialiser()
{
    if (!font.loadFromFile("resources/SportypoReguler-OVGwe.ttf"))
    {
        cout << "Could not load resource (SplashScreen_FONT)" << endl;
    }

    if (!font2.loadFromFile("resources/EvilEmpire-4BBVK.ttf"))
    {
        cout << "Could not load resource (EvilEmpire-4BBVK)" << endl;
    }
    // Select the font
    text.setFont(font);

    // Set the string to display
    text.setString("DEFENDER \nPRESS SPACE TO START ");

    // Set the character size
    text.setCharacterSize(30);

    // Set the initial color to white
    text.setFillColor(sf::Color::White);

    // Load the background texture
    if (!backgroundTexture.loadFromFile("resources/airShip.png"))
    {
        cout << "Could not load resource SplashScreen_background" << endl;
    }

    // Set the background sprite's texture
    backgroundSprite.setTexture(backgroundTexture);

    // Calculate the position to center the background
    float x = (_window->getSize().x - backgroundSprite.getLocalBounds().width) / 2;
    float y = (_window->getSize().y - backgroundSprite.getLocalBounds().height) / 2;
    backgroundSprite.setPosition(x, y);

    // Create a new Text object for instructions

    instructions.setFont(font2);
    instructions.setString("INSTRUCTIONS\nUp Arrow: move Up\nDown Arrow: move Down\nLeft arrow: Turn Left\nRight arrow: Turn Right\nSpace: To Shoot");
    instructions.setCharacterSize(20);
    instructions.setFillColor(sf::Color::White);

    // Position the instructions at the middle of the rightmost side
    float instructionsX = _window->getSize().x - instructions.getLocalBounds().width - 500; // Adjust the position as needed
    float instructionsY = (_window->getSize().y - instructions.getLocalBounds().height) - 10;
    instructions.setPosition(instructionsX, instructionsY);

    // Draw the instructions text to the screen
}

void SplashScreen::handleInput()
{
    Event event;
    while (_window->pollEvent(event))
    {
        if (Event::Closed == event.type)
        {
            _window->close();
        }

        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Space)
            {
                _window->close();
                GameLoop gameLoop; // Create an instance of GameLoop
                gameLoop.run();    // Start and run the game loop
            }
        }
    }
}

void SplashScreen::update(float dt)
{
    // Add color switching logic here
    if (colorSwitchTimer.getElapsedTime().asSeconds() > 1.f) // Adjust the switch speed as needed
    {
        if (isWhiteColor)
        {
            text.setFillColor(sf::Color::Black);
        }
        else
        {
            text.setFillColor(sf::Color::White);
        }
        isWhiteColor = !isWhiteColor; // Toggle color
        colorSwitchTimer.restart();
    }
}

void SplashScreen::draw()
{
    // Draw the background first
    _window->draw(backgroundSprite);

    // Then draw the text with the current color
    _window->draw(text);
    _window->draw(instructions);

    _window->display();
}
