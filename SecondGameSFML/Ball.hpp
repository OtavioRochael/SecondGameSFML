#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum BallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class Ball
{
private:
	sf::CircleShape shape;
	int type;
	
	void InitShape(const sf::RenderWindow& window);

public:
	Ball(const sf::RenderWindow& window, int type);
	~Ball();

	const sf::CircleShape& GetShape();
	const int & GetType();

	void Update(const sf::RenderTarget* target);
	void Render(sf::RenderTarget* target);
};

