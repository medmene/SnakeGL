#include "Inits.h"

/*void Initialize()
{
	startBtn = Button(800, 300, 400, 100, "Start");
	infoBtn = Button(800, 500, 400, 100, "Info");
	exitBtn = Button(800, 700, 400, 100, "Exit");
	backInfoBtn = Button(100, 80, 400, 100, "Back");
	backGameBtn = Button(1550, 970, 300, 80, "Back");
	newGameBtn = Button(1200, 970, 300, 80, "New Game");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 1080, 0);
}
void MouseFunc(int button, int state, int x, int y)
{
	x = windwScale * x; y = windwScale * y;
	switch (globalState)
	{
	case 0: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Hover(x, y, startBtn.GetFiled())) { startBtn.onClick = true; }
			else if (Hover(x, y, infoBtn.GetFiled())) { infoBtn.onClick = true; }
			else if (Hover(x, y, exitBtn.GetFiled())) { exitBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (startBtn.onClick == true) {
				startBtn.onClick = false;  globalState = 2;
				srand(time(0));
				Snake.clear();
				Snake.push_back(Point(rand() % 46, rand() % 22));
				food.x = rand() % 46; food.y = rand() % 22;
				while(food==Snake[0]){ food.x = rand() % 46; food.y = rand() % 22; }
				glutTimerFunc(1000, TimerFunction, 1);
				backPressed_inGame = false;
			}
			else if (infoBtn.onClick == true) { infoBtn.onClick = false;  globalState = 1; }
			else if (exitBtn.onClick == true) { exitBtn.onClick = false;  exit(0); }
		}
		break;
	}
	case 1: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Hover(x, y, backInfoBtn.GetFiled())) { backInfoBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (backInfoBtn.onClick == true) { backInfoBtn.onClick = false;  globalState = 0; }
		}
		break;
	}
	case 2: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Hover(x, y, backGameBtn.GetFiled())) { backGameBtn.onClick = true; }
			else if (Hover(x, y, newGameBtn.GetFiled())) { newGameBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (backGameBtn.onClick == true) { backGameBtn.onClick = false;  globalState = 0; backPressed_inGame = true; }
			else if (newGameBtn.onClick == true) { 
				newGameBtn.onClick = false; 
				Scores = 0;
				srand(time(0));
				Snake.clear();
				Snake.push_back(Point(rand() % 46, rand() % 22));
				food.x = rand() % 46; food.y = rand() % 22;
				while (food == Snake[0]) { food.x = rand() % 46; food.y = rand() % 22; }
				glutTimerFunc(1000, TimerFunction, 1);
				backPressed_inGame = false;
			}
		}
		break;
	}
	}
	Draw();
}

void onKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'W': case 'w':
		direction = 0;
		break;
	case 'A': case 'a':
		direction = 3;
		break;
	case 'S': case 's':
		direction = 2;
		break;
	case 'D': case 'd':
		direction = 1;
		break;
	}
	Draw();
}
*/
void Draw(){
	switch (gameProps::globalState)
	{
	case 0: DrawFirstScene(); break;
	case 1: DrawSecondScene(); break;
	case 2: DrawThirdScene(); break;
	}
	glutSwapBuffers();
}

void TimerFunction(int value) {
	Point tmp = Scenes::Snake[Scenes::Snake.size() - 1];
	for (int i = Scenes::Snake.size() - 1; i > 0; i--) {
		if (Scenes::Snake[i] != Scenes::Snake[i - 1]) {
			Scenes::Snake[i].x = Scenes::Snake[i - 1].x;
			Scenes::Snake[i].y = Scenes::Snake[i - 1].y;
		}
	}
	switch (Scenes::direction)
	{
	case 0: Scenes::Snake[0].y--; break;
	case 1: Scenes::Snake[0].x++; break;
	case 2: Scenes::Snake[0].y++; break;
	case 3: Scenes::Snake[0].x--; break;
	}
	if (Scenes::Snake[0] == Scenes::food) {
		Scenes::Snake.push_back(tmp);
		Scenes::Scores += 10;
		Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22;
		while (Scenes::food == Scenes::Snake[0]) { Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22; }
	}
	//Game over
	if (!HoverSnake(Scenes::Snake[0]) ||!CheckSnake()) {
		Scenes::Scores = 0;
		Scenes::Snake.clear();
		Scenes::Snake.push_back(Point(rand() % 46, rand() % 22));
		Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22;
		while (Scenes::food == Scenes::Snake[0]) { Scenes::food.x = rand() % 46; Scenes::food.y = rand() % 22; }
	}
	else if(!Scenes::backPressed_inGame)glutTimerFunc(Scenes::Speed, TimerFunction, 1);
	Draw();
}

void main(int argc, char **argv) {
	Init(argc, argv);
	return;
}