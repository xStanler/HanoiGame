#include "Button.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

Button::Button()
{
	container.setSize(Vector2f(100, 100));
	setContainerColor(Color::Transparent);
	setPosition(0, 0);
}

Button::Button(Text text, int width, int height)
{
	this->text = text;

	setSize(width, height);

	this->container.setSize(Vector2f(this->width, this->height));
	setContainerColor(Color::Transparent);
	this->text.setFillColor(Color(0, 0, 0));
	setPosition(0, 0);
}

void Button::setSize(int width, int height)
{
	if(width < this->text.getLocalBounds().width)
	{
		this->width = this->text.getLocalBounds().width + 10;
	}else{
		this->width = width;
	}

	if(height < this->text.getLocalBounds().height)
	{
		this->height = this->text.getLocalBounds().height + 10;
	}else{
		this->height = height;
	}

	container.setSize(Vector2f(this->width, this->height));
}

void Button::setPosition(int x, int y)
{
	container.setPosition(Vector2f(x,y));
	text.setPosition(Vector2f(x +((container.getSize().x - text.getLocalBounds().width) / 2), y + ((container.getSize().y - text.getLocalBounds().height*1.75) / 2)));
}

void Button::setContainerColor(Color color)
{
	container.setFillColor(color);
}

bool Button::isClicked(const Window &relativeTo)
{
	if(Mouse::getPosition(relativeTo).x > container.getPosition().x && Mouse::getPosition(relativeTo).x < (container.getPosition().x + container.getSize().x))
	{
		if(Mouse::getPosition(relativeTo).y > container.getPosition().y && Mouse::getPosition(relativeTo).y < (container.getPosition().y + container.getSize().y))
		{
			if(Mouse::isButtonPressed(Mouse::Left))
			{
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(container, states);
	target.draw(text, states);
}