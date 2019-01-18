#pragma once
#include "Classes.h"

int globalState = 0; //state of project
Button startBtn, infoBtn, exitBtn; //Global 0
Button backInfoBtn; //Global 1
Button backGameBtn, newGameBtn; //Global 2
float windwScale;
int Scores = 0;

//game settings 
int widBlocks = 47;
int heigBlocks = 23;
int blockSize = 40;
vector<Point> Snake;
int direction = -1;
Point food;
int Speed = 200;
bool backPressed_inGame = false;


void SnakeLogo() {
	FillRectangle(1150, 200, 40, 40);
	FillRectangle(1150 + 40, 200, 40, 40);
	FillRectangle(1150 + 40, 200 - 40, 40, 40);
	FillRectangle(1150 + 40 * 2, 200 - 40, 40, 40);
	FillRectangle(1150 + 40 * 3, 200 - 40, 40, 40);
	FillRectangle(1150 + 40 * 3, 200, 40, 40);
	FillRectangle(1150 + 40 * 4, 200, 40, 40);
	FillRectangle(1150 + 40 * 5, 200, 40, 40);
	FillRectangle(1150 + 40 * 5, 200 - 40, 40, 40);
	FillRectangle(1150 + 40 * 5, 200 - 40 * 2, 40, 40);
	FillRectangle(1150 + 40 * 5, 200 - 40 * 3, 40, 40);
	FillRectangle(1150 + 40 * 6, 200 - 40 * 3, 40, 40);
}

//start menu
void DrawFirstScene() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Orange();
	SnakeLogo();
	Color::White();
	glWrite((1920-5*32) / 2, 200, "Snake");
	startBtn.Draw();
	infoBtn.Draw();
	exitBtn.Draw();
}
//Info
void DrawSecondScene() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Aqua();
	DrawRectangle((1920-1650)/2, 250, 1650, 750, 4);
	backInfoBtn.Draw();
	Color::White();
	glWrite(200, 300, "Author: megagem.");
	glWrite(200, 350, "Simple realisation of game \"Snake\".");
	glWrite(200, 400, "Recomended using standart window size.");
	glWrite(200, 450, "Controls:");
	glWrite(300, 500, "W - up");
	glWrite(300, 550, "S - down");
	glWrite(300, 600, "D - right");
	glWrite(300, 650, "A - left");
	glWrite(200, 750, "C++ OpenGL Microsoft Visual Studio 2015.");
	glWrite(200, 800, "Github: https://github.com/medmene/SnakeGL");
}
//test
void DrawGrid() {
	for (int i = 0; i < 47; ++i)
		for (int j = 0; j < 23; ++j)
			DrawRectangle(20 + i * 40, 20 + j * 40, 40, 40, 2);
}

void inline DrawSnake() {
	for (int i = 0; i < Snake.size(); ++i) 
		FillRectangle(20+Snake[i].x * 40 + 1, 20+Snake[i].y * 40 + 1, 38, 38);	
}

bool inline CheckSnake() {
	for (int i = 1; i < Snake.size(); ++i) 
		if (Snake[i] == Snake[0]) return false;	
	return true;
}

//Game
void DrawThirdScene() { 
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	newGameBtn.Draw();
	backGameBtn.Draw();
	Color::Aqua();
	DrawSnake();
	Color::Crimson();
	FillRectangle(25 + food.x * 40, 25 + food.y * 40, 30, 30);
	Color::White();
	DrawRectangle(18, 18, 1890, 930, 3);
	glWrite(100, 1030, "Score:");
	glWrite(250, 1030, std::to_string(Scores));
}
