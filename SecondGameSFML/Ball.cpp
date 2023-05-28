#include "Ball.hpp"

void Ball::InitShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 20 + 1));
	sf::Color color;
	
	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color::White;
		break;

	case DAMAGING:
		color = sf::Color::Red;
		break;

	case HEALING:
		color = sf::Color::Green;
		break;
	}
	
	//sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1); //Nunca dara (0,0,0) pois essa cor é preto que é igual o fundo
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(2.f);
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

Ball::Ball(const sf::RenderWindow& window, int type):type(type)
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

const int & Ball::GetType() {
	return this->type;
}

void Ball::Update(const sf::RenderTarget* target)
{

}

void Ball::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
