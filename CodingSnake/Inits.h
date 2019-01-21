#pragma once
#include "MouseEvents.h"

void Initialize()
{
	Scenes::startBtn = Button(800, 300, 400, 100, "Start");
	Scenes::infoBtn = Button(800, 500, 400, 100, "Info");
	Scenes::exitBtn = Button(800, 700, 400, 100, "Exit");
	Scenes::backInfoBtn = Button(100, 80, 400, 100, "Back");
	Scenes::backGameBtn = Button(1550, 970, 300, 80, "Back");
	Scenes::newGameBtn = Button(1200, 970, 300, 80, "New Game");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 1080, 0);
}

void Init(int argc, char **argv) {
	gameProps::windwScale = 2.666666f;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(gameProps::windowWidth, gameProps::windowHeight);		//Window size
	glutInitWindowPosition(800, 400);											//Window position
	glutCreateWindow(gameProps::nameOfWindow.c_str());							//Window name
	Initialize();
	glutDisplayFunc(Draw);				//Draw
	glutMouseFunc(onMouse);				//Mouse
	glutKeyboardFunc(onKeyboard);		//Keyboard
	glutMainLoop();
}