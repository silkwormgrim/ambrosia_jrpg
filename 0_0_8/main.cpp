// ◊ MAIN
// ────────────────────────────
#include <SFML/Graphics.hpp>
#include <iostream>

#include "video.h"

int main(int argc, char* argv[]) {
	std::cout << "hello, world\n";

	VIDEO video;
	video.window_loop();

	return 0;
};