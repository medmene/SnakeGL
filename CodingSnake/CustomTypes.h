#pragma once
#include "DrawFunctions.h"

class Button {
	float X, Y;
	int width, height;
	string text;
public:
	bool onClick = false;
	Button() {}
	Button(float _X, float _Y, int _wid, int _heig, string _text) {
		X = _X; Y = _Y; width = _wid; height = _heig; text = _text;
	}
	void inline Draw() {
		//non clicked
		if (!onClick) {
			Color::Gray();
			DrawRectangle(X + 4, Y + 4, width, height, 6);
			Color::Silver();
			FillRectangle(X, Y, width, height);
			Color::Black();
			glWrite(X - 4 + (width - text.size() * 22) / 2, Y - 4 + (height + 24) / 2, text);
		}
		//clicked
		else {
			Color::Gray();
			DrawRectangle(X + 4, Y + 4, width, height, 5);
			Color::Silver();
			FillRectangle(X + 4, Y + 4, width, height);
			Color::Black();
			glWrite(X + (width - text.size() * 22) / 2, Y + (height + 24) / 2, text);
		}
	}
	Rect GetFiled() { return Rect(X, Y, width, height); }
	bool inline Hover(int x, int y) {
		if (x >= X && x < (X + width))
			if (y >= Y && y < (Y + height))
				return true;
		return false;
	}
};