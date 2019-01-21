#pragma once
#include "Control.h"


void onKeyboard(unsigned char key, int x, int y) {
	if (gameProps::globalState == 2) {
		switch (key) {
		case 'W': case 'w':
			Scenes::direction = 0;
			break;
		case 'A': case 'a':
			Scenes::direction = 3;
			break;
		case 'S': case 's':
			Scenes::direction = 2;
			break;
		case 'D': case 'd':
			Scenes::direction = 1;
			break;
		case 27: exit(0); break;
		}
		Draw();
	}
}