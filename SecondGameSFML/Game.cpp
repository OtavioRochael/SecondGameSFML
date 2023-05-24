#include "Game.hpp"

//Initialization
void Game::InitVariables()
{
	this->endGame = false;
	this->player;
}

void Game::InitWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game()
{
	InitVariables();
	InitWindow();
}

Game::~Game()
{
	delete(this->window);
}

const bool Game::RunningGame()
{
	return this->window->isOpen();
}

//Functions
void Game::PollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->PollEvents();
	player.Update(this->window);
}

void Game::Render()
{
	this->window->clear();

	//Render stuff

	player.Render(this->window);
	this->window->display();
}
