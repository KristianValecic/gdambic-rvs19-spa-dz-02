#include <SFML/Graphics.hpp>
#include "game_of_life.h"

int main()
{
	const int width = 50;
	const int height = 20;

	sf::RenderWindow window(sf::VideoMode(width, height), "Game of Life");
	window.setFramerateLimit(60);
	
	game_of_life game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		game.iscrtaj();
		game.sljedeca_generacija();

		window.display();
	}

	return 0;
}