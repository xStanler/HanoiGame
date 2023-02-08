#ifndef POLE_HPP
#define POLE_HPP

#include <SFML/Graphics.hpp>
#include <stack>

using namespace sf;

class Pole : public sf::Drawable 
{
	int number;
	sf::Vector2f position;
	sf::Vector2f stackSize;
	sf::RectangleShape pole;

public:
	float width;
	std::stack<sf::RectangleShape> poleStack;
	Pole(int number);

	void push(sf::RectangleShape button);
	void setPosition(float x, float y);
	void setWidth(float width);
	// Button top();
	sf::RectangleShape pop();
	
	// bool isClicked(const sf::Window &relativeTo);
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

#endif