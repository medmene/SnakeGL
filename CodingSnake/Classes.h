#pragma once
#include "DrawFucntions.h"

class Color {
public:
	static void Orange() { glColor3ub(255, 165, 0); }
	static void Red() { glColor3ub(255, 0, 0); }
	static void Crimson() { glColor3ub(220, 20, 60); }
	static void Khaki() { glColor3ub(248, 230, 140); }
	static void White() { glColor3ub(255, 255, 255); }
	static void Black() { glColor3ub(0, 0, 0); }
	static void Silver() { glColor3ub(192, 192, 192); }
	static void Gray() { glColor3ub(128, 128, 128); }
	static void Aqua() { glColor3ub(0, 255, 255); }
};

struct Point {
	int x; //х координата
	int y; //у координата
		   //конструкторы
	Point() { x = 0; y = 0; }
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
	//сравнение точек
	const bool operator == (const Point &v2)
	{
		if ((x == v2.x) && (y == v2.y))
			return true;
		else return false;
	}
	const bool operator != (const Point &v2)
	{
		if ((x != v2.x) || (y != v2.y))
			return true;
		else return false;
	}
	//присваивание
	Point operator = (Point v1)
	{
		this->x = v1.x, this->y = v1.y;
		return *this;
	}
	//хз особо не надо
	friend Point operator - (Point p1, Point p2) {
		return Point(p1.x - p2.x, p1.y - p2.y);
	}
	friend Point operator + (Point p1, Point p2) {
		return Point(p1.x + p2.x, p1.y + p2.y);
	}
};

struct Rect {
	float X, Y;
	int width, height;
	Rect(float _X, float _Y, int _wid, int _heig) {
		X = _X; Y = _Y; width = _wid; height = _heig;
	}
};

class Button {
	float X, Y;
	int width, height;
	string text;
public:
	bool onClick = false;
	Button(){}
	Button(float _X, float _Y, int _wid, int _heig, string _text) {
		X = _X; Y = _Y; width = _wid; height = _heig; text = _text;
	}
	void Draw() {
		if (!onClick) {
			Color::Gray();
			FillRectangle(X + 6, Y + 6, width, height);
			Color::Silver();
			FillRectangle(X, Y, width, height);
			Color::Black();
			glWrite(X + 20 + (width - text.size() * 30) / 2, Y + height / 1.5, text);
		}
		else {
			Color::Gray();
			FillRectangle(X + 6, Y + 6, width, height);
			Color::Silver();
			FillRectangle(X + 4, Y + 4, width, height);
			Color::Black();
			glWrite(X + 4 + 20 +  (width - text.size()*30) / 2, Y + 4 + height / 1.5, text);
		}
	}
	Rect GetFiled() { return Rect(X, Y, width, height); }
};

bool inline Hover(int x, int y, Rect r) {
	if (x >= r.X)
		if (x < (r.X + r.width))
			if (y >= r.Y)
				if (y < (r.Y + r.height))
					return true;
	return false;
}
bool inline HoverSnake(Point p) {
	if (p.x >= 0 && p.x < 47)
		if (p.y >= 0 && p.y < 23) return true;
	return false;
}
