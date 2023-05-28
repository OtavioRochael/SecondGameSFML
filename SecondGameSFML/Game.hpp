#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.hpp"
#include "Ball.hpp"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	
	Player player;

	std::vector<Ball> balls;
	
	int points;

	sf::Font font;
	sf::Text guiText;

	float spawnTimerMax;
	float spawnTimer;

	short unsigned int maxBalls;

	bool endGame;

	void InitVariables();
	void InitWindow();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Acessors

	//Modifiers

	//Functions
	const bool RunningGame();

	void PollEvents();

	void SpawnBalls();
	void UpdateCollision();
	void Update();
	void Render();
};

