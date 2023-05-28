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
	int hp;
	int hpMax;

	void InitVariables();
	void InitShape();

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();

	//Acessors
	const sf::RectangleShape& GetShape();
	const int & GetHealth();
	const int & GetMaxHealth();

	//Functions

	void TakeDamage(const int damage);
	void GainHealth(const int health);

	//Updates
	void Update(const sf::RenderTarget* target);
	void UpdateInput();
	void UpdateWindowBounceCollision(const sf::RenderTarget* target);

	//Render
	void Render(sf::RenderTarget* target);
};

