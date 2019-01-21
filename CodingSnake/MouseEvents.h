#pragma once
#include "KeyboardEvents.h"


void onMouse(int button, int state, int x, int y) {
	x = gameProps::windwScale * x; y = gameProps::windwScale * y;
	switch (gameProps::globalState)
	{
	case 0: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Scenes::startBtn.Hover(x, y)) { Scenes::startBtn.onClick = true; }
			else if (Scenes::infoBtn.Hover(x, y)) { Scenes::infoBtn.onClick = true; }
			else if (Scenes::exitBtn.Hover(x, y)) { Scenes::exitBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Scenes::startBtn.onClick) { 
				Scenes::startBtn.onClick = false; 
				gameProps::globalState = 2;
				srand(time(0));
				Scenes::Snake.clear();
				Scenes::Snake.push_back(Point(rand() % 46, rand() % 22));
				Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22;
				while (Scenes::food == Scenes::Snake[0]) { Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22; }
				glutTimerFunc(1000, TimerFunction, 1);
				Scenes::backPressed_inGame = false;
			}
			else if (Scenes::infoBtn.onClick) { Scenes::infoBtn.onClick = false; gameProps::globalState = 1;}
			else if (Scenes::exitBtn.onClick) { Scenes::exitBtn.onClick = false; exit(0); }
		}
		break;
	}
	case 1: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Scenes::backInfoBtn.Hover(x, y)) { Scenes::backInfoBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Scenes::backInfoBtn.onClick) { Scenes::backInfoBtn.onClick = false; gameProps::globalState = 0; }
		}
		break;
	}
	case 2: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Scenes::backGameBtn.Hover(x, y)) { Scenes::backGameBtn.onClick = true; }
			else if (Scenes::newGameBtn.Hover(x, y)) { Scenes::newGameBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Scenes::backGameBtn.onClick) { Scenes::backGameBtn.onClick = false; 
			gameProps::globalState = 0;
			Scenes::backPressed_inGame = true;  }
			else if (Scenes::newGameBtn.onClick) {
				Scenes::newGameBtn.onClick = false;
				Scenes::Scores = 0;
				srand(time(0));
				Scenes::Snake.clear();
				Scenes::Snake.push_back(Point(rand() % 46, rand() % 22));
				Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22;
				while (Scenes::food == Scenes::Snake[0]) { Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22; }
				glutTimerFunc(1000, TimerFunction, 1);
				Scenes::backPressed_inGame = false;
			}
		}
		break;
	}
	}	
	Draw();
}
