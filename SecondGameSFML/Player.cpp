#include "Player.hpp"

void Player::InitVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 3;
	this->hp = this->hpMax;
	this->points = 0;
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

const sf::RectangleShape& Player::GetShape()
{
	return this->shape;
}

const int Player::GetPoints()
{
	return this->points;
}

void Player::AddPoint()
{
	this->points++;
}

void Player::Update(const sf::RenderTarget *target)
{
	this->UpdateInput();

	//Window bounds collision
	UpdateWindowBounceCollision(target);
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
	//UPDATING BOUNDS AFTER EVERY POSITION CHANGE
	
	//Left
	if (this->shape.getGlobalBounds().left <= 0.f) {
		this->shape.setPosition(sf::Vector2f(0.1f, this->shape.getGlobalBounds().top));
	}
	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
		this->shape.setPosition(sf::Vector2f(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top));
	}

	//Top
	if (this->shape.getGlobalBounds().top <= 0.f) {
		this->shape.setPosition(sf::Vector2f(this->shape.getGlobalBounds().left , 0.1f));
	}
	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
		this->shape.setPosition(sf::Vector2f(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height));
	}
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
