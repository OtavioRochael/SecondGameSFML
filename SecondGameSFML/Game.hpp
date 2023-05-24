#pragma once

#include <iostream>
#include <ctime>

#include "Player.hpp"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	
	Player player;

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

	void Update();
	void Render();
};

