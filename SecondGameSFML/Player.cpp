#include "Player.hpp"

void Player::InitVariables()
{
	movementSpeed = 5.f;
}

void Player::InitShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y)
{
	//Passing the x and y to set the spawn position of the player
	this->shape.setPosition(x, y);

	this->InitShape();
	this->InitVariables();
}

Player::~Player()
{
}

void Player::Update(const sf::RenderTarget *target)
{
	//Window bounds collision
	UpdateWindowBounceCollision(target);

	this->UpdateInput();

}

void Player::UpdateInput()
{
	//Keyboard input

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(sf::Vector2f(-1.f * movementSpeed, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(sf::Vector2f(1.f * movementSpeed, 0.f));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(sf::Vector2f(0.f, -1.f * movementSpeed));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(sf::Vector2f(0.f, 1.f * movementSpeed));
	}
}

void Player::UpdateWindowBounceCollision(const sf::RenderTarget* target)
{
	sf::Vector2f playerCurrentPosition = (this->shape.getPosition());
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();

	//Left
	if (playerBounds.left <= 0.f) {
		this->shape.setPosition(sf::Vector2f(0.f, playerCurrentPosition.y));
	}
	//Right
	else if (playerBounds.left + this->shape.getSize().x >= target->getSize().x) {
		this->shape.setPosition(sf::Vector2f(target->getSize().x - this->shape.getSize().x, playerCurrentPosition.y));
	}
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
