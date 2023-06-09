#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player
{
private:
	sf::RectangleShape shape;

	float movementSpeed;

	void InitVariables();
	void InitShape();

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();

	void Update(const sf::RenderTarget* target);
	void UpdateInput();
	void UpdateWindowBounceCollision(const sf::RenderTarget* target);
	void Render(sf::RenderTarget* target);
};

