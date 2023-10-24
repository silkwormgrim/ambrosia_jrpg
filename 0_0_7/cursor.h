#ifndef CURSOR_H
#define CURSOR_H

struct CURSOR {
	int x = 0;
	int y = 0;
	
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

	int selector = 0;
	int max = 7;
	
	bool visible = true;

	CURSOR();
	
	void move(char direction);
	void activate();
	void reset();

} cursor;

CURSOR :: CURSOR() {
	/*
	cursor.x = cursor.list[0][0];
	cursor.y = cursor.list[0][1];

	cursor_2.visible = false;

	cursor_2.list[0][0] = 0;
	cursor_2.list[0][1] = 32;

	cursor_2.list[1][0] = 0;
	cursor_2.list[1][1] = 128;

	cursor_2.list[2][0] = 0;
	cursor_2.list[2][1] = 224;

	cursor_2.list[3][0] = 0;
	cursor_2.list[3][1] = 320;

	cursor_2.max = 3;

	cursor_2.x = cursor_2.list[0][0];
	cursor_2.y = cursor_2.list[0][1];
	*/
	reset();
};

void CURSOR :: move(char direction){
	std::cout << "[CURSOR]: " << x << ',' << y << '\n';
	std::cout << "[SELECTOR]: " << selector << '\n';

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
};

void CURSOR :: activate(){
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
};

void CURSOR :: reset(){
	int s = screen.selector;
	x = screen.cursor_x.at(s);
	y = screen.cursor_y.at(s);
};

#endif