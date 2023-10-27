#ifndef VIDEO_H
#define VIDEO_H

struct VIDEO {
	const int screen_width = 640;
	const int screen_height = 480;

	sf::RenderWindow window;
	sf::Event event;
	sf::Font font;
	sf::Time last_time;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;
	sf::Texture texture_4;

	VIDEO();
	~VIDEO();

	void poll_events();
	
	void render_cursor();
	
	void render_grid(int size);
	
	void render_menu_0();	
	void render_menu_1();
	void render_menu_1_cluster_1();
	void render_menu_1_cluster_2();
	
};

void VIDEO :: render_cursor(){
	if (cursor.visible) {
		sf::RectangleShape rect(sf::Vector2f(32,32));
		rect.setFillColor(sf::Color::White);
		rect.setPosition(cursor.x,cursor.y);
		window.draw(rect);
	}

	if (cursor.visible_2) {
		sf::RectangleShape rect(sf::Vector2f(32,32));
		rect.setFillColor(sf::Color::White);
		rect.setPosition(cursor.x_2,cursor.y_2);
		window.draw(rect);
	}};

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
		input.poll_events(event);
	}
};

VIDEO :: VIDEO() {
	std::cout << "CONSTRUCTOR\n";
	
	font.loadFromFile("file/tahoma.ttf");
	texture_1.loadFromFile("file/re_player.bmp");
	texture_2.loadFromFile("file/re_player2.bmp");
	texture_3.loadFromFile("file/re_item_none.bmp");
	texture_4.loadFromFile("file/re_item_anti.bmp");
	
	/*
	int rows = sizeof cursor_2.list / sizeof cursor_2.list[0];
	int columns = sizeof cursor_2.list[0] / sizeof(int);
	std::cout << rows << ' ' << columns << '\n';
	*/
};

VIDEO :: ~VIDEO() {
	std::cout << "DESTRUCTOR\n";
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
	/*
	for (int i = 0; i < screen_width; i+=size/2) { 
		for (int j = 0; j < screen_height; j+=size/2) {
			sf::Vertex point(sf::Vector2f(i,j), sf::Color::White);
			window.draw(&point, 1, sf::Points);
		}
	}
	*/
};

void VIDEO :: render_menu_0(){
	sf::RectangleShape rect_1(sf::Vector2f(32*5,32*1));
	rect_1.setTexture(&texture_3);
	rect_1.setPosition(320-32*2,416);
	window.draw(rect_1);
	
	sf::Text text_1;
	text_1.setFont(font);
	text_1.setString("New_Game");
	text_1.setCharacterSize(24);
	text_1.setFillColor(sf::Color::White);
	text_1.setPosition(320-32*2,416);
	window.draw(text_1);
};

void VIDEO :: render_menu_1(){
	render_menu_1_cluster_1();
	render_menu_1_cluster_2();
};

void VIDEO :: render_menu_1_cluster_1(){
	int x = 32;
	int y = 32;

	sf::RectangleShape rect_1(sf::Vector2f(32*5,32*1));
	rect_1.setTexture(&texture_3);
	rect_1.setPosition(x+32*13,y);
	window.draw(rect_1);
	
	sf::Text text_1;
	text_1.setFont(font);
	text_1.setString("Item");
	text_1.setCharacterSize(24);
	text_1.setFillColor(sf::Color::White);
	text_1.setPosition(x+32*13,y);
	window.draw(text_1);

	sf::RectangleShape rect_2(sf::Vector2f(32*5,32*1));
	rect_2.setTexture(&texture_3);
	rect_2.setPosition(x+32*13,y+32*1);
	window.draw(rect_2);

	sf::Text text_2;
	text_2.setFont(font);
	text_2.setString("Equipment");
	text_2.setCharacterSize(24);
	text_2.setFillColor(sf::Color::White);
	text_2.setPosition(x+32*13,y+32*1);
	window.draw(text_2);

	sf::RectangleShape rect_3(sf::Vector2f(32*5,32*1));
	rect_3.setTexture(&texture_3);
	rect_3.setPosition(x+32*13,y+32*2);
	window.draw(rect_3);

	sf::Text text_3;
	text_3.setFont(font);
	text_3.setString("Status");
	text_3.setCharacterSize(24);
	text_3.setFillColor(sf::Color::White);
	text_3.setPosition(x+32*13,y+32*2);
	window.draw(text_3);

	sf::RectangleShape rect_4(sf::Vector2f(32*5,32*1));
	rect_4.setTexture(&texture_3);
	rect_4.setPosition(x+32*13,y+32*3);
	window.draw(rect_4);

	sf::Text text_4;
	text_4.setFont(font);
	text_4.setString("Save");
	text_4.setCharacterSize(24);
	text_4.setFillColor(sf::Color::White);
	text_4.setPosition(x+32*13,y+32*3);
	window.draw(text_4);

	sf::RectangleShape rect_5(sf::Vector2f(32*5,32*1));
	rect_5.setTexture(&texture_3);
	rect_5.setPosition(x+32*13,y+32*4);
	window.draw(rect_5);

	sf::Text text_5;
	text_5.setFont(font);
	text_5.setString("Quit");
	text_5.setCharacterSize(24);
	text_5.setFillColor(sf::Color::White);
	text_5.setPosition(x+32*13,y+32*4);
	window.draw(text_5);

	sf::RectangleShape rect_6(sf::Vector2f(32*5,32*1));
	rect_6.setTexture(&texture_3);
	rect_6.setPosition(x+32*13,y+32*5);
	window.draw(rect_6);

	sf::RectangleShape rect_7(sf::Vector2f(32*5,32*1));
	rect_7.setTexture(&texture_3);
	rect_7.setPosition(x+32*13,y+32*6);
	window.draw(rect_7);

	sf::RectangleShape rect_8(sf::Vector2f(32*5,32*1));
	rect_8.setTexture(&texture_3);
	rect_8.setPosition(x+32*13,y+32*7);
	window.draw(rect_8);
};

void VIDEO :: render_menu_1_cluster_2(){
	int x = 32;
	int y = 32;

	sf::RectangleShape rect_1(sf::Vector2f(32*12,32*3));
	rect_1.setTexture(&texture_3);
	rect_1.setPosition(x,y);
	window.draw(rect_1);

	sf::Text text_1;
	text_1.setFont(font);
	text_1.setString("Player_1");
	text_1.setCharacterSize(24);
	text_1.setFillColor(sf::Color::White);
	text_1.setPosition(x,y);
	window.draw(text_1);

	sf::RectangleShape rect_2(sf::Vector2f(32*12,32*3));
	rect_2.setTexture(&texture_3);
	rect_2.setPosition(x,y+32*3);
	window.draw(rect_2);

	sf::Text text_2;
	text_2.setFont(font);
	text_2.setString("Player_2");
	text_2.setCharacterSize(24);
	text_2.setFillColor(sf::Color::White);
	text_2.setPosition(x,y+32*3);
	window.draw(text_2);

	sf::RectangleShape rect_3(sf::Vector2f(32*12,32*3));
	rect_3.setTexture(&texture_3);
	rect_3.setPosition(x,y+32*6);
	window.draw(rect_3);

	sf::Text text_3;
	text_3.setFont(font);
	text_3.setString("Player_3");
	text_3.setCharacterSize(24);
	text_3.setFillColor(sf::Color::White);
	text_3.setPosition(x,y+32*6);
	window.draw(text_3);

	sf::RectangleShape rect_4(sf::Vector2f(32*12,32*3));
	rect_4.setTexture(&texture_3);
	rect_4.setPosition(x,y+32*9);
	window.draw(rect_4);

	sf::Text text_4;
	text_4.setFont(font);
	text_4.setString("Player_4");
	text_4.setCharacterSize(24);
	text_4.setFillColor(sf::Color::White);
	text_4.setPosition(x,y+32*9);
	window.draw(text_4);
};

#endif