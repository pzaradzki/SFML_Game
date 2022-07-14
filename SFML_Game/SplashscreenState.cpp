#include "SplashscreenState.h"


SplashscreenState::SplashscreenState(sf::RenderWindow* window) 
    : GameState(window)
{
    backgroundTexture.loadFromFile("Images/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    titleTexture.loadFromFile("Images/title.png");
    titleSprite.setTexture(titleTexture);
}

SplashscreenState::~SplashscreenState()
{
}

void SplashscreenState::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::MouseButtonPressed)
        if (event->mouseButton.button == sf::Mouse::Left)
                Game::state = Game::Menu;
}

void SplashscreenState::update(float elapsedTime)
{

}

void SplashscreenState::draw()
{
	window->draw(backgroundSprite);
	window->draw(titleSprite);
}
