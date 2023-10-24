#ifndef INPUT_H
#define INPUT_H

struct INPUT {
	void poll_events(sf::Event event);
} input;

void INPUT :: poll_events(sf::Event event){
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cursor.x -= 32;
			std::cout << "[CURSOR]: " << cursor.x << ',' << cursor.y << '\n';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cursor.x += 32;
			std::cout << "[CURSOR]: " << cursor.x << ',' << cursor.y << '\n';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			cursor.y -= 32;
			std::cout << "[CURSOR]: " << cursor.x << ',' << cursor.y << '\n';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			cursor.y += 32;
			std::cout << "[CURSOR]: " << cursor.x << ',' << cursor.y << '\n';
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			cursor.move('b');
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			cursor.move('f');
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			cursor.activate();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			screen.selector = 0;
			cursor.reset();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			screen.selector = 1;
			cursor.reset();
		}
	}
};

#endif