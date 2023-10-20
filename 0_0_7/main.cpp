// ◊ MAIN
// ────────────────────────────

#include <SFML/Graphics.hpp>

#include <iostream>

struct VIDEO {
	const int screen_width = 640;
	const int screen_height = 480;

	sf::RenderWindow window{sf::VideoMode(screen_width,screen_height), "window"};
	sf::Event event;
	sf::Font font;
	sf::Time last_time;

	VIDEO();
	~VIDEO();
	
	void poll_events();
	void render();
	void render_grid(int size);
	void render_re_menu();
	void render_ff_menu();
	
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;
	sf::Texture texture_4;
} video;

VIDEO :: VIDEO() {
	std::cout << "CONSTRUCTOR\n";
	font.loadFromFile("file/tahoma.ttf");
	texture_1.loadFromFile("file/re_player.bmp");
	texture_2.loadFromFile("file/re_player2.bmp");
	texture_3.loadFromFile("file/re_item_none.bmp");
	texture_4.loadFromFile("file/re_item_anti.bmp");
};

VIDEO :: ~VIDEO() {
	std::cout << "DESTRUCTOR\n";

};

void VIDEO :: poll_events(){
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
};

void VIDEO :: render_grid(int size) {
	for (int i = 0; i < screen_width; i+=size) {
		for (int j = 0; j < screen_height; j+=size) {
			sf::Vertex line_vert[2] = {
				sf::Vertex(sf::Vector2f(i,j), sf::Color::Red),
				sf::Vertex(sf::Vector2f(i,j+size), sf::Color::Red)
			};
			window.draw(line_vert,  2, sf::Lines);

			sf::Vertex line_horz[2] = {
				sf::Vertex(sf::Vector2f(i,j), sf::Color::Blue),
				sf::Vertex(sf::Vector2f(i+size,j), sf::Color::Blue)
			};
			window.draw(line_horz,  2, sf::Lines);
		}
	}

	for (int i = 0; i < screen_width; i+=size/2) { 
		for (int j = 0; j < screen_height; j+=size/2) {
			sf::Vertex point(sf::Vector2f(i,j), sf::Color::White);
			window.draw(&point, 1, sf::Points);
		};
	};
}

void VIDEO :: render(){
	render_grid(32);
	render_ff_menu();
};

void VIDEO :: render_ff_menu(){
	sf::RectangleShape rect_1(sf::Vector2f(32*12,32*3));
	rect_1.setTexture(&texture_3);
	rect_1.setPosition(16,16);
	window.draw(rect_1);

	sf::RectangleShape rect_3(sf::Vector2f(32*12,32*3));
	rect_3.setTexture(&texture_3);
	rect_3.setPosition(16,16+32*3);
	window.draw(rect_3);

	sf::RectangleShape rect_4(sf::Vector2f(32*12,32*3));
	rect_4.setTexture(&texture_3);
	rect_4.setPosition(16,16+32*6);
	window.draw(rect_4);

	sf::RectangleShape rect_5(sf::Vector2f(32*12,32*3));
	rect_5.setTexture(&texture_3);
	rect_5.setPosition(16,16+32*9);
	window.draw(rect_5);

	sf::RectangleShape rect_2(sf::Vector2f(32*5,32*10));
	rect_2.setTexture(&texture_3);
	rect_2.setPosition(16+32*14,16);
	window.draw(rect_2);
};

void VIDEO :: render_re_menu(){
	sf::RectangleShape rect_1(sf::Vector2f(32*3,32*3));
	rect_1.setTexture(&texture_1);
	rect_1.setPosition(16,16);
	window.draw(rect_1);

	sf::RectangleShape rect_2(sf::Vector2f(32*7,32*3));
	rect_2.setTexture(&texture_2);
	rect_2.setPosition(16+32*3+16,16);
	window.draw(rect_2);
	
	sf::RectangleShape rect_3(sf::Vector2f(32*8,32*3));
	//rect_3.setFillColor(sf::Color::Black);
	rect_3.setTexture(&texture_3);
	rect_3.setPosition(16+32*11,16);
	window.draw(rect_3);

	sf::RectangleShape rect_4(sf::Vector2f(32*12,32*11));
	//rect_4.setFillColor(sf::Color::Black);
	rect_4.setTexture(&texture_3);
	rect_4.setPosition(16,32*3+16+8);
	window.draw(rect_4);

	sf::RectangleShape rect_5(sf::Vector2f(32*6+16,32*11));
	rect_5.setFillColor(sf::Color::Black);
	rect_5.setPosition(32*12+32,32*3+16+8);
	window.draw(rect_5);

	sf::RectangleShape rect_6(sf::Vector2f(32*3,32*3));
	//rect_6.setFillColor(sf::Color::Blue);
	rect_6.setTexture(&texture_4);
	rect_6.setPosition(32*12+32,32*3+16+8);
	window.draw(rect_6);

	sf::RectangleShape rect_7(sf::Vector2f(32*3,32*3));
	//rect_7.setFillColor(sf::Color::White);
	rect_7.setTexture(&texture_3);
	rect_7.setPosition(32*12+32+32*3,32*3+16+8);
	window.draw(rect_7);

	sf::RectangleShape rect_8(sf::Vector2f(32*3,32*3));
	//rect_8.setFillColor(sf::Color::White);
	rect_8.setTexture(&texture_3);
	rect_8.setPosition(32*12+32,32*3+16+8+32*3);
	window.draw(rect_8);

	sf::RectangleShape rect_9(sf::Vector2f(32*3,32*3));
	//rect_9.setFillColor(sf::Color::Blue);
	rect_9.setTexture(&texture_3);
	rect_9.setPosition(32*12+32+32*3,32*3+16+8+32*3);
	window.draw(rect_9);

	sf::RectangleShape rect_10(sf::Vector2f(32*3,32*3));
	//rect_10.setFillColor(sf::Color::Blue);
	rect_10.setTexture(&texture_3);
	rect_10.setPosition(32*12+32,32*3+16+8+32*6);
	window.draw(rect_10);

	sf::RectangleShape rect_11(sf::Vector2f(32*3,32*3));
	//rect_11.setFillColor(sf::Color::White);
	rect_11.setTexture(&texture_3);
	rect_11.setPosition(32*12+32+32*3,32*3+16+8+32*6);
	window.draw(rect_11);
};

int main(int argc, char* argv[]) {
	sf::Clock clock;
	video.last_time = clock.getElapsedTime();

	video.window.clear();
	video.render();
	video.window.display();

	while (video.window.isOpen()) {
		sf::Time time = clock.getElapsedTime();
		int desired_framerate = 1;
		double delta = time.asMilliseconds() - video.last_time.asMilliseconds();

		if (delta >= 1000*3 / desired_framerate){
			std::cout << video.last_time.asMilliseconds() << ' ' << time.asMilliseconds() << '\n';
			video.last_time = clock.getElapsedTime();

			video.window.clear();
			video.render();
			video.window.display();
		}

		video.poll_events();
	}
	return 0;
};