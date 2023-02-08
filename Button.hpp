#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Button : public Drawable
{
		RectangleShape container;
	public:
		int width, height;
		Text text;

		enum type {
			eContainer = 1,
			eText = 2,
		};

		Button();
		Button(Text text, int width, int height);

		//Settery
		void setPosition(int x, int y);
		void setContainerColor(Color color);
		void setSize(int width, int height);
		//TODO gettery i settery
		bool isClicked(const Window &relativeTo);
	private:
		virtual void draw(RenderTarget& target, RenderStates states) const;
};

#endif // BUTTON_HPP