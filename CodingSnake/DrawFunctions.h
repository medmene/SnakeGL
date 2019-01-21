#pragma once
#include "BaceDefines.h"


//main Draw function
void Draw();

void inline glWrite(float x, float y, string text, Fonts fnt = _9_by_15) {
	glRasterPos2f(x, y);
	for (int i = 0; i < text.size(); i++)
		switch (fnt) {
		case Helvetica_10: glutBitmapCharacter((int*)GLUT_BITMAP_HELVETICA_10, (int)text[i]); break;
		case Helvetica_12: glutBitmapCharacter((int*)GLUT_BITMAP_HELVETICA_12, (int)text[i]); break;
		case Helvetica_18: glutBitmapCharacter((int*)GLUT_BITMAP_HELVETICA_18, (int)text[i]); break;
		case _8_by_13: glutBitmapCharacter((int*)GLUT_BITMAP_8_BY_13, (int)text[i]); break;
		case _9_by_15: glutBitmapCharacter((int*)GLUT_BITMAP_9_BY_15, (int)text[i]); break;
		case Times_roman_10: glutBitmapCharacter((int*)GLUT_BITMAP_TIMES_ROMAN_10, (int)text[i]); break;
		case Times_roman_24: glutBitmapCharacter((int*)GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]); break;
		default: break;
		}
	//Example: glWrite(20, 20, (int*)GLUT_BITMAP_8_BY_13, "qwerty");	
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

bool inline HoverSnake(Point p) {
	if (p.x >= 0 && p.x < 47)
		if (p.y >= 0 && p.y < 23) return true;
	return false;
}

void TimerFunction(int value);