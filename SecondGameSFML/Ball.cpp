#include "Ball.hpp"

void Ball::InitShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 20 + 1));
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1); //Nunca dara (0,0,0) pois essa cor é preto que é igual o fundo
	this->shape.setFillColor(color);

	float shapePosX = static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width);
	float shapePosY = static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height);

	if (shapePosX < 0.f) {
		shapePosX = 0.f;
	}

	if(shapePosY < 0.f){
		shapePosY = 0.f;
 	}

	this->shape.setPosition(sf::Vector2f(shapePosX, shapePosY));
}

Ball::Ball(const sf::RenderWindow& window)
{
	this->InitShape(window);
}

Ball::~Ball()
{
}

const sf::CircleShape& Ball::GetShape()
{
	return this->shape;
}

void Ball::Update(const sf::RenderTarget* target)
{

}

void Ball::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
