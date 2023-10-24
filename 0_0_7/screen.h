#ifndef SCREEN_H
#define SCREEN_H

struct SCREEN {
	int selector = 0;
	std::vector<std::string> n;
	std::vector<int> cursor_x;
	std::vector<int> cursor_y;
	SCREEN();
} screen;

SCREEN :: SCREEN(){
	n.push_back("main_menu");
	cursor_x.push_back(192);
	cursor_y.push_back(416);

	n.push_back("item_menu");
	cursor_x.push_back(416);
	cursor_y.push_back(32);
};

#endif