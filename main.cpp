#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stack>
#include "Button.hpp"
#include "Pole.hpp"

		using namespace sf;

		enum screen {
			MAIN_MENU = 0,
			GAME_SCREEN = 1,
			GAME_WIN = 2,
			GAME_MENU = 3,
			TUTORIAL = 4,
			DIFFICULTY = 5
		};

		enum keyClicked {
			null = 0,
			Num1 = 1,
			Num2 = 2,
			Num3 = 3
		};

		int main()
		{
			RenderWindow window(VideoMode(800, 600), "Hanoi Game", Style::Default);

			window.setFramerateLimit(60);

			Font font;
			font.loadFromFile("./font/Righteous/Righteous-Regular.ttf");

			Text text("Hanoi Game", font, 30);
			Text playText("Play", font, 20);
			Text tutorialText("How to play?", font, 20);
			Text tutorialTitleText("How to play?", font, 40);
			Text tutorialHowToText("aksjhfhgajshf", font, 20);
			Text exitText("Exit", font, 20);
			Text easyText("Easy", font, 20);
			Text mediumText("Medium", font, 20);
			Text hardText("Hard", font, 20);
			Text moveFrom("Move from:", font, 20);
			Text moveTo("Move to:", font, 20);
			Text oneText("1", font, 20);
			Text twoText("2", font, 20);
			Text threeText("3", font, 20);
			Text movesMade("", font, 20);
			Text wonText("YOU WON!", font, 40);
			Text wonInMovesText("", font, 20);
			Text difficultyText("Choose your difficulty!", font, 40);

			Button Play(playText, 0, 0);
			Button Tutorial(tutorialText, 0, 0);
			Button Exit(exitText, 0, 0);
			Button Easy(easyText, 0, 0);
			Button Medium(mediumText, 0, 0);
			Button Hard(hardText, 0, 0);

			text.setPosition(((float) (window.getSize().x) - text.getLocalBounds().width) / 2  , ((float) (window.getSize().y) - text.getLocalBounds().height * 1.75) / 2.5);

			Play.text.setStyle(Text::Bold);
			Play.text.setFillColor(Color(0, 0, 0, 123));
			Play.setPosition(text.getPosition().x + (text.getLocalBounds().width / 3), (text.getPosition().y + (text.getLocalBounds().height * 1.5)));

			Tutorial.text.setStyle(Text::Bold);
			Tutorial.text.setFillColor(Color(0, 0, 0, 123));
			Tutorial.setPosition(text.getPosition().x + (text.getLocalBounds().width / 8), (text.getPosition().y + (text.getLocalBounds().height * 3)));

			tutorialTitleText.setStyle(Text::Bold);
			tutorialTitleText.setFillColor(Color(0, 0, 0, 123));
			tutorialTitleText.setPosition((window.getSize().x - tutorialTitleText.getLocalBounds().width) / 2, 100);

			tutorialHowToText.setFillColor(Color(0, 0, 0, 123));
			tutorialHowToText.setPosition(window.getSize().x / 2 - tutorialTitleText.getLocalBounds().width, 120 + tutorialTitleText.getLocalBounds().height);
			tutorialHowToText.setString("Game controls are very easy :) \nFirst: select key on keyboard cooresponding to \n\t\t  pole (left - 1, middle - 2, rigth - 3) to choose \n\t\t  from which pole move disc.\nSecond: select key like in first point to choose \n\t\t  to wich pole move disc.\nThird: In the WON screen press space or enter to \n\t\t  get back to menu");

			Exit.text.setStyle(Text::Bold);
			Exit.text.setFillColor(Color(0, 0, 0, 123));
			Exit.setPosition(text.getPosition().x + (text.getLocalBounds().width / 3), (text.getPosition().y + (text.getLocalBounds().height * 4.5)));

			difficultyText.setPosition((window.getSize().x / 2 - difficultyText.getLocalBounds().width / 2) , (window.getSize().y / 2 - 100));

			Easy.text.setStyle(Text::Bold);
			Easy.text.setFillColor(Color(0, 0, 0, 123));
			Easy.setPosition((window.getSize().x / 3), (text.getPosition().y + (text.getLocalBounds().height * 2.5)));

			Medium.text.setStyle(Text::Bold);
			Medium.text.setFillColor(Color(0, 0, 0, 123));
			Medium.setPosition(window.getSize().x / 2.25, (text.getPosition().y + (text.getLocalBounds().height * 2.5)));

			Hard.text.setStyle(Text::Bold);
			Hard.text.setFillColor(Color(0, 0, 0, 123));
			Hard.setPosition(window.getSize().x / 1.75, (text.getPosition().y + (text.getLocalBounds().height * 2.5)));

			oneText.setPosition(120, window.getSize().y - (oneText.getLocalBounds().height * 4.5) - 120);
			twoText.setPosition(window.getSize().x / 2 - 15, window.getSize().y - (twoText.getLocalBounds().height * 4.5) - 120);
			threeText.setPosition(window.getSize().x * 5 / 6 - 15, window.getSize().y - (threeText.getLocalBounds().height * 4.5) - 120);

			moveFrom.setPosition(100, window.getSize().y - (moveFrom.getLocalBounds().height * 4.5) - 75);
			moveTo.setPosition(100, window.getSize().y - (moveTo.getLocalBounds().height * 3) - 75);
			movesMade.setPosition(100, window.getSize().y - (moveTo.getLocalBounds().height * 1.5) - 75);

			wonText.setPosition((window.getSize().x / 2) - (wonText.getLocalBounds().width / 2), (window.getSize().y/2) - (wonText.getLocalBounds().height));
			wonText.setStyle(Text::Bold);
			wonText.setFillColor(Color::Black);

			wonInMovesText.setPosition(wonText.getPosition().x, wonText.getPosition().y + 50);
			wonInMovesText.setFillColor(Color::Black);

			int numberOfDiscs = 6;

			Pole poleOne(numberOfDiscs);
			poleOne.setPosition(0, 100);
			poleOne.setWidth(250);

			Pole poleTwo(numberOfDiscs);
			poleTwo.setPosition(window.getSize().x / 3, 100);
			poleTwo.setWidth(250);

			Pole poleThree(numberOfDiscs);
			poleThree.setPosition(window.getSize().x * 2 / 3, 100);
			poleThree.setWidth(250);

			RectangleShape one;
			one.setSize(Vector2f(42, 42));
			one.setFillColor(Color(248, 177, 149));

			RectangleShape two;
			two.setSize(Vector2f(84, 42));
			two.setFillColor(Color(246, 114, 128));

			RectangleShape three;
			three.setSize(Vector2f(126, 42));
			three.setFillColor(Color(192, 108, 132));

			RectangleShape four;
			four.setSize(Vector2f(168, 42));
			four.setFillColor(Color(108, 91, 123));

			RectangleShape five;
			five.setSize(Vector2f(210, 42));
			five.setFillColor(Color(53, 92, 125));

			RectangleShape six;
			six.setSize(Vector2f(252, 42));
			six.setFillColor(Color(27, 46, 63));


			int currentScreen = MAIN_MENU;

			int firstKey = null;

			int moves = 0;

			while(window.isOpen())
			{

				//GAME SCREEN
				if(currentScreen == GAME_SCREEN)
				{
					Event gameEvent;

					while(window.pollEvent(gameEvent))
					{
						if(gameEvent.type == Event::Closed)
				    window.close();

						if(gameEvent.type == Event::KeyPressed)
						{
							if(gameEvent.key.code == Keyboard::Escape)
							{
								currentScreen = MAIN_MENU;
							}else if(gameEvent.key.code == Keyboard::Num1 && firstKey == null)
							{
								if(!poleOne.poleStack.empty())
								{
									moveFrom.setString("Move from: 1");
									firstKey = Num1;
								}
							}else if(gameEvent.key.code == Keyboard::Num2 && firstKey == null)
							{
								if(!poleTwo.poleStack.empty())
								{
									moveFrom.setString("Move from: 2");
									firstKey = Num2;
								}
							}else if(gameEvent.key.code == Keyboard::Num3 && firstKey == null)
							{
								if(!poleThree.poleStack.empty())
								{
									moveFrom.setString("Move from: 3");
									firstKey = Num3;
								}
							}

							if(!poleOne.poleStack.empty())
							{
								if(gameEvent.key.code == Keyboard::Num2 && firstKey == Num1)
								{
									moveTo.setString("Move to: 2");
									if(poleTwo.poleStack.empty()){
										poleTwo.push(poleOne.pop());
										moves++;
									}else if(poleTwo.poleStack.top().getSize().x >= poleOne.poleStack.top().getSize().x)
									{
										poleTwo.push(poleOne.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 2 - Error");
									}
									firstKey = null;
								}

								if(gameEvent.key.code == Keyboard::Num3 && firstKey == Num1)
								{
									moveTo.setString("Move to: 3");
									if(poleThree.poleStack.empty())
									{
										poleThree.push(poleOne.pop());
										moves++;
									}else if(poleThree.poleStack.top().getSize().x >= poleOne.poleStack.top().getSize().x)
									{
										poleThree.push(poleOne.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 3 - Error");
									}
									firstKey = null;
								}
							}

							if(!poleTwo.poleStack.empty())
							{

								if(gameEvent.key.code == Keyboard::Num1 && firstKey == Num2)
								{
									moveTo.setString("Move to: 1");
									if(poleOne.poleStack.empty()){
										poleOne.push(poleTwo.pop());
										moves++;	
									}else if(poleOne.poleStack.top().getSize().x >= poleTwo.poleStack.top().getSize().x)
									{
										poleOne.push(poleTwo.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 1 - Error");
									}
									firstKey = null;
								}

								if(gameEvent.key.code == Keyboard::Num3 && firstKey == Num2)
								{
									moveTo.setString("Move to: 3");
									if(poleThree.poleStack.empty())
									{
										poleThree.push(poleTwo.pop());
										moves++;
									}else if(poleThree.poleStack.top().getSize().x >= poleTwo.poleStack.top().getSize().x)
									{
										poleThree.push(poleTwo.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 3 - Error");
									}
									firstKey = null;
								}
							}

							if(!poleThree.poleStack.empty())
							{

								if(gameEvent.key.code == Keyboard::Num1 && firstKey == Num3)
								{
									moveTo.setString("Move to: 1");
									if(poleOne.poleStack.empty())
									{
										poleOne.push(poleThree.pop());
										moves++;
									}else if(poleOne.poleStack.top().getSize().x >= poleThree.poleStack.top().getSize().x)
									{
										poleOne.push(poleThree.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 1 - Error");
									}
									firstKey = null;
								}

								if(gameEvent.key.code == Keyboard::Num2 && firstKey == Num3)
								{
									moveTo.setString("Move to: 2");
									if(poleTwo.poleStack.top().getSize().x >= poleThree.poleStack.top().getSize().x)
									{
										poleTwo.push(poleThree.pop());
										moves++;
									}else if(poleTwo.poleStack.empty())
									{
										poleTwo.push(poleThree.pop());
										moves++;
									}else{
										moveTo.setString("Move to: 2 - Error");
									}
									firstKey = null;
								}
							}
						}
					}

					if(poleTwo.poleStack.size() == numberOfDiscs || poleThree.poleStack.size() == numberOfDiscs)
					{
						currentScreen = GAME_WIN;
					}

					window.clear(Color(156, 207, 216));
					window.draw(poleOne);
					window.draw(poleTwo);
					window.draw(poleThree);
					window.draw(oneText);
					window.draw(twoText);
					window.draw(threeText);
					window.draw(moveFrom);
					window.draw(moveTo);
					movesMade.setString("Moves: " + std::to_string(moves));
					window.draw(movesMade);
					window.display();
				}
			//MAIN MENU
		if(currentScreen == MAIN_MENU){
			Event menuEvent;
			while(window.pollEvent(menuEvent))
			{
				if(menuEvent.type == Event::Closed)
		    	window.close();
			}
			if(Play.isClicked(window))
			{
				currentScreen = DIFFICULTY;
			}
		

			if(Tutorial.isClicked(window))
			{
				currentScreen = TUTORIAL;
			}

			if(Exit.isClicked(window))
			{
				window.close();
			}

			window.clear(Color(123, 255, 123));
			window.draw(text);
			window.draw(Play);
			window.draw(Tutorial);
			window.draw(Exit);
			window.display();
		}

		//TUTORIAL
		if(currentScreen == TUTORIAL)
		{
			Event tutorialEvent;

			while(window.pollEvent(tutorialEvent))
			{
				if(tutorialEvent.type == Event::Closed)
                    window.close();
			}

			if(Keyboard::isKeyPressed(Keyboard::Escape))
			{
				currentScreen = MAIN_MENU;
			}

			window.clear(Color(255, 123, 123));
			window.draw(tutorialTitleText);
			window.draw(tutorialHowToText);
			window.display();
		}

		if(currentScreen == GAME_WIN)
		{
			Event tutorialEvent;

			while(window.pollEvent(tutorialEvent))
			{
				if(tutorialEvent.type == Event::Closed)
                    window.close();
			}

			if(Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space))
			{
				currentScreen = MAIN_MENU;
			}

			window.clear(Color(138, 95, 237));
			window.draw(wonText);
			std::string test = "In " + std::to_string(moves) + " moves!";
			wonInMovesText.setString(test);
			window.draw(wonInMovesText);
			window.display();
		}


		if(currentScreen == DIFFICULTY)
		{
			Event tutorialEvent;

			while(window.pollEvent(tutorialEvent))
			{
				if(tutorialEvent.type == Event::Closed)
                    		window.close();
			}

			if(Keyboard::isKeyPressed(Keyboard::Escape))
			{
				currentScreen = MAIN_MENU;
			}

			if(Easy.isClicked(window))
			{
				numberOfDiscs = 3;
				currentScreen = GAME_SCREEN;
			}

			if(Medium.isClicked(window))
			{
				numberOfDiscs = 5;
				currentScreen = GAME_SCREEN;
			}
			
			if(Hard.isClicked(window))
			{
				numberOfDiscs = 6;
				currentScreen = GAME_SCREEN;
			}
				
			for(int i = 0, n = poleOne.poleStack.size(); i < n; i++)
			{
				poleOne.pop();
			}
			for(int i = 0, n = poleTwo.poleStack.size(); i < n; i++)
			{
				poleTwo.pop();
			}
			for(int i = 0, n = poleThree.poleStack.size(); i < n; i++)
			{
				poleThree.pop();
			}
			
			switch(numberOfDiscs)
			{
			case 6:
				poleOne.push(six);
			case 5:
				poleOne.push(five);
				poleOne.push(four);
			case 3:
				poleOne.push(three);
				poleOne.push(two);
				poleOne.push(one);
				break;
			}

			moves = 0;
			moveFrom.setString("Moves from: ");
			moveTo.setString("Moves to: ");

			window.clear(Color(196, 167, 231));
			window.draw(difficultyText);
			window.draw(Easy);
			window.draw(Medium);
			window.draw(Hard);
			window.display();
		}
	}	
}
