#pragma once
#include <vector>
#include <string>
#include <glut.h>
#include <time.h>

using std::string;
using std::vector;
#define graphics


void inline glWrite(float x, float y, string text) {
	int i;
	glRasterPos2f(x, y);
	for (i = 0; i < text.size(); i++)
		glutBitmapCharacter((int*)GLUT_BITMAP_9_BY_15,  (int)text[i]);
	//glWrite(20, 20, (int*)GLUT_BITMAP_8_BY_13, "qwerty");
}


void inline DrawRectangle(float X, float Y, int width, int heigth, int LineWid=1) {
	glLineWidth(LineWid);
	glBegin(GL_LINES);
	glVertex2f(X, Y);
	glVertex2f(X + width, Y);
	glVertex2f(X + width, Y);
	glVertex2f(X + width, Y + heigth);
	glVertex2f(X + width, Y + heigth);
	glVertex2f(X, Y + heigth);
	glVertex2f(X, Y + heigth);
	glVertex2f(X, Y);
	glEnd();
}
void inline FillRectangle(float X, float Y, int width, int heigth) {
	glBegin(GL_POLYGON);
	glVertex2f(X, Y);
	glVertex2f(X + width, Y);
	glVertex2f(X + width, Y + heigth);
	glVertex2f(X, Y + heigth);
	glEnd();
}
void TimerFunction(int value);