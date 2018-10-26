#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	using namespace sf;
	RenderWindow window(sf::VideoMode(800, 600), "GameOver");


	Texture herotexture;
	herotexture.loadFromFile("images/heroimage.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 96, 96));
	herosprite.setPosition(50, 50);

	Clock clock;
	float CurrentFrame = 0;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 2) CurrentFrame -= 2;
			herosprite.setTextureRect(IntRect(288 * int(CurrentFrame) + 96, 0, -96, 96));
			herosprite.move(-0.1*time, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 2) CurrentFrame -= 2;
			herosprite.setTextureRect(IntRect(192* int(CurrentFrame), 0,96, 96));
			herosprite.move(0.1*time, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
				herosprite.move(0,-0.1*time);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 1) CurrentFrame -= 1;
				herosprite.setTextureRect(IntRect(288 * int(CurrentFrame), 96, 96, 96));
				herosprite.move(0,0.1*time);
			}
		
			window.clear();
			window.draw(herosprite);
			window.display();
		}

		return 0;
	}