#include "Collisions.h"
#include "GameEngine.h"
#include "Player.h"
#include "LostSplash.h"
#include "WinSplash.h"

void Game::isGameOver()
{

    Collision collision;
    if (fuelCount == 0)
    {
        for (int i = 0; i < 20; i++)
        {
            Play.getSprite().move(0, 5.f);
        }
        if (Play.getSprite().getPosition().y > 380)
            fell = true;

        if (fell)
        {
                        window->close();

            // Create a new SplashScreen object and show the splash screen
            LostScreen lostScreen(window);
            lostScreen.showLostScreen();
        }
    }
    else
    {

        for (auto &enemy : enemies)
        {
            if (collision.areSpritesColliding(Play.getSprite(), enemy->getSprite()) & enemy->isVisible())
            {
                                     window->close();

            // Create a new SplashScreen object and show the splash screen
            LostScreen lostScreen(window);
            lostScreen.showLostScreen();
            }
        }

        for (auto &bullet : enemy_bullets)
        {
            if (collision.areSpritesColliding(Play.getSprite(), bullet->getSprite()) & bullet->isVisible())
            {

                                    window->close();

            // Create a new SplashScreen object and show the splash screen
            LostScreen lostScreen(window);
            lostScreen.showLostScreen();
            }
        }

        for (auto &fuel : _fuel)
        {
            if (collision.areSpritesColliding(Play.getSprite(), fuel->getSprite()) & fuel->isVisible())
            {
                fuel->removeFromScreen();
                fuelCount = fuelCount + 20 > 100 ? fuelCount + 20 : 100;
            }
        }

        for (auto &bullet : bullets)
        {
            for (auto &enemy : enemies)
            {
                if (collision.areSpritesColliding(bullet->getSprite(), enemy->getSprite()) & bullet->isVisible() & enemy->isVisible())
                {
                    bullet->removeFromScreen();
                    enemy->removeFromScreen();
                }
            }
        }
        auto count_enemies = 0;

        for (auto &enemy : enemies)
        {
            if (enemy->isVisible())
            {
                count_enemies++;
            }
        }
        if (count_enemies == 0)
        {
            // Close the existing window
            window->close();

            // Create a new SplashScreen object and show the splash screen
            SplashScreen splashScreen(window);
            splashScreen.showSplashScreen();
        }
    }
}
