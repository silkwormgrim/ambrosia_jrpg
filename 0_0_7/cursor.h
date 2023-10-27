#ifndef CURSOR_H
#define CURSOR_H

struct CURSOR {
	int list[8][2] = {
		{416,32},
		{416,32*2},
		{416,32*3},
		{416,32*4},
		{416,32*5},
		{416,32*6},
		{416,32*7},
		{416,32*8},
	};

	int x = list[0][0];
	int y = list[0][1];
	bool visible = true;
	int selector = 0;
	const int max = 7;

	int list_2[4][2] = {
		{0,32},
		{0,128},
		{0,224},
		{0,320}
	};

	int x_2 = list_2[0][0];
	int y_2 = list_2[0][1];
	bool visible_2 = false;
	int selector_2 = 0;
	const int max_2 = 3;

	CURSOR();
	
	void move(char direction);
	void activate();
	void reset();

} cursor;

CURSOR :: CURSOR() {
	reset();
};

void CURSOR :: move(char direction){
	std::cout << "[CURSOR]: " << x << ',' << y << '\n';
	std::cout << "[CURSOR_2]: " << x_2 << ',' << y_2 << '\n';
	std::cout << "[SELECTOR]: " << selector << '\n';

	if (visible_2 == false){
	switch (direction){
		case 'f':
			selector++;
			if (selector > max) {
				selector = 0;
			}
			x = list[selector][0];
			y = list[selector][1];
		break;
		case 'b':
			selector--;
			if (selector < 0) {
				selector = max;
			}
			x = list[selector][0];
			y = list[selector][1];
		break;
	}
	}
	
	if (visible_2 == true){
	switch (direction){
		case 'f':
			selector_2++;
			if (selector_2 > max_2) {
				selector_2 = 0;
			}
			x_2 = list_2[selector_2][0];
			y_2 = list_2[selector_2][1];
		break;
		case 'b':
			selector_2--;
			if (selector_2 < 0) {
				selector_2 = max_2;
			}
			x_2 = list_2[selector_2][0];
			y_2 = list_2[selector_2][1];
		break;
	}
	}
	
};

void CURSOR :: activate(){
	if (visible_2 == true) {
		visible_2 = false;
	}
	else {
		visible_2 = true;
	}

	switch(cursor.selector) {
		case 0:
			std::cout << "[Selector]: " << "Item" << '\n';
			break;
		case 1:
			std::cout << "[Selector]: " << "Equipment" << '\n';
			break;
		case 2:
			std::cout << "[Selector]: " << "Status" << '\n';
			break;
		case 3:
			std::cout << "[Selector]: " << "Save" << '\n';
			break;
		case 4:
			std::cout << "[Selector]: " << " " << '\n';
			break;
		case 5:
			std::cout << "[Selector]: " << " " << '\n';
			break;
		case 6:
			std::cout << "[Selector]: " << " " << '\n';
			break;
		case 7:
			std::cout << "[Selector]: " << " " << '\n';
			break;
	}
	
	switch (cursor.selector_2) {
		case 0:
			std::cout << "[Selector]: " << "Player_1" << '\n';
			break;
		case 1:
			std::cout << "[Selector]: " << "Player_2" << '\n';
			break;
		case 2:
			std::cout << "[Selector]: " << "Player_3" << '\n';
			break;
		case 3:
			std::cout << "[Selector]: " << "Player_4" << '\n';
			break;
	}
};

void CURSOR :: reset(){
	int s = screen.selector;
	x = screen.cursor_x.at(s);
	y = screen.cursor_y.at(s);
};

#endif