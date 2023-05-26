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
	
	void InitShape(const sf::RenderWindow& window);

public:
	Ball(const sf::RenderWindow& window);
	~Ball();

	const sf::CircleShape& GetShape();

	void Update(const sf::RenderTarget* target);
	void Render(sf::RenderTarget* target);
};

