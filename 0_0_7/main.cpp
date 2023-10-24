// ◊ MAIN
// ────────────────────────────

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

struct GAME {
	bool debug_mode = false;
} game;

#include "screen.h"
#include "cursor.h"
#include "input.h"
#include "video.h"

int main(int argc, char* argv[]) {
	sf::Clock clock;

	VIDEO video;
	video.last_time = clock.getElapsedTime();

	video.window.create(sf::VideoMode(video.screen_width, video.screen_height), "window");

	video.window.clear();
	video.window.display();
	
	while (video.window.isOpen()) {
		sf::Time time = clock.getElapsedTime();
		int desired_framerate = 30;
		double delta = time.asMilliseconds() - video.last_time.asMilliseconds();

		if (delta >= 1000 / desired_framerate){
			if (game.debug_mode == true) {
				std::cout << video.last_time.asMilliseconds() << ' ' << time.asMilliseconds() << '\n';
			}
			video.last_time = time;

			video.window.clear();

			switch (screen.selector) {
				case 0:
					video.render_menu_0();
					video.render_cursor();
					break;
				case 1:
					video.render_grid(32);
					video.render_menu_1();
					video.render_cursor();
					break;
				default:
					video.render_grid(16);
					break;
			};

			video.window.display();
		}

		video.poll_events();
	}
	return 0;
};