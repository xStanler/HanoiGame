#include "Pole.hpp"
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>

Pole::Pole(int number)
{
	this->number = number;
	this->pole.setFillColor(Color(105, 58, 30));
	this->pole.setSize(Vector2f(50, 600));
}

void Pole::push(sf::RectangleShape button)
{
	if(poleStack.size() < number)
	{
		poleStack.push(button);
		poleStack.top().setPosition(position.x + ((width - poleStack.top().getSize().x) / 2), position.y + (number * poleStack.top().getSize().y) - ((poleStack.size() - 1) * poleStack.top().getSize().y));
		this->stackSize.x = poleStack.top().getSize().x;
		this->stackSize.y = poleStack.top().getSize().y;
	}else{
		std::cout<<"Error: Stack out of bounds"<<std::endl;
	}
}

void Pole::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void Pole::setWidth(float width)
{
	this->width = width;
}

sf::RectangleShape Pole::pop()
{
	sf::RectangleShape tmp = poleStack.top();
	poleStack.pop();
	return tmp;
}

void Pole::draw(RenderTarget& target, RenderStates states) const
{
	for (std::stack<sf::RectangleShape> dump = poleStack; !dump.empty(); dump.pop())
        target.draw(dump.top(), states);
}