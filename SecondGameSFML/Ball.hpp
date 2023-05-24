#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Ball
{
private:
	sf::CircleShape shape;
	
	void InitShape();

public:
	Ball();
	~Ball();

	void Update();
	void Render();
};

