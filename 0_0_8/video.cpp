#include <SFML/Graphics.hpp>
#include <iostream>

bool silent = true;

void hello_from_function() {
	sf::Clock clock;
	sf::Time last_time;
	last_time = clock.getElapsedTime();
	
	sf::Event event;
	
	sf::RenderWindow window;
	
	window.create(sf::VideoMode(640, 480), "window");
	window.clear();

	while (window.isOpen()) {
		sf::Time time = clock.getElapsedTime();
		int desired_framerate = 30;
		double delta = time.asMilliseconds() - last_time.asMilliseconds();

		if (delta >= 1000 / desired_framerate){
			if (!silent) {std::cout << last_time.asMilliseconds() << ' ' << time.asMilliseconds() << '\n';}

			last_time = time;

			window.clear();
			
			// render here

			window.display();
		}

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
				}
			}
		}
	}

	window.display();
};