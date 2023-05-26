#include "Game.hpp"

//Initialization
void Game::InitVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = spawnTimerMax;
	this->maxBalls = 10;
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

void Game::SpawnBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else {
		if (this->balls.size() < this->maxBalls) {
			this->balls.push_back(Ball(*this->window));

			this->spawnTimer = 0.f;

		}	
	}
}

void Game::UpdateCollision()
{	
	//Check the collision and erase the ball inside the vector<ball>
	for (size_t i = 0; i < this->balls.size(); i++) {
		if (this->player.GetShape().getGlobalBounds().intersects(this->balls[i].GetShape().getGlobalBounds()))
		{
			this->balls.erase(this->balls.begin() + i);
			player.AddPoint();
			std::cout << player.GetPoints() << std::endl;
		}
	}
	
}

void Game::Update()
{
	this->PollEvents();
	this->SpawnBalls();
	this->UpdateCollision();

	player.Update(this->window);
}

void Game::Render()
{
	this->window->clear();

	//Render stuff

	player.Render(this->window);

	//Render the ball in vector balls
	for (auto a : balls) {
		a.Render(this->window);
	}

	this->window->display();
}
