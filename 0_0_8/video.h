#ifndef VIDEO_H
#define VIDEO_H

struct VIDEO {
	sf::Clock clock;
	sf::Time last_time;
	sf::Event event;
	sf::RenderWindow window;

	bool silent = true;
	VIDEO();
	~VIDEO();
	void window_loop();
};

#endif