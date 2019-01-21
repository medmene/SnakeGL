#pragma once
#include <vector>
#include <string>
#include <glut.h>
#include <time.h>

using std::string;
using std::vector;

namespace gameProps {
	float windwScale = 2.666666f;
	string nameOfWindow = "Snake";
	int windowWidth = 720;
	int windowHeight = 405;
	int mouseX = 0;
	int mouseY = 0;
	int globalState = 0;
};

enum Fonts {
	Helvetica_10,
	Helvetica_12,
	Helvetica_18,
	_8_by_13,
	_9_by_15,
	Times_roman_10,
	Times_roman_24
};

enum _Clr {
	_Orange,
	_Red,
	_Crimson,
	_Khaki,
	_White,
	_Black,
	_Silver,
	_Gray,
	_Aqua
};
class Color {
	_Clr curColor;
public:
	Color() {}
	Color(_Clr clr) { curColor = clr; }
	void GetColor() {
		switch (curColor) {
		case _Orange: Orange(); break;
		case _Red: Red(); break;
		case _Crimson: Crimson(); break;
		case _Khaki: Khaki(); break;
		case _White: White(); break;
		case _Black: Black(); break;
		case _Silver: Silver(); break;
		case _Gray: Gray(); break;
		case _Aqua: Aqua(); break;
		default: break;
		}
	}
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
	int x, y;
	Point() { x = 0; y = 0; }
	Point(int _x, int _y) { x = _x, y = _y; }
	Point(const Point & ovr) { x = ovr.x; y = ovr.y; }
	const bool operator == (const Point &v2) {
		if ((x == v2.x) && (y == v2.y)) return true;
		else return false;
	}
	const bool operator != (const Point &v2) {
		if ((x != v2.x) || (y != v2.y)) return true;
		else return false;
	}
	Point operator = (Point v1) {
		this->x = v1.x, this->y = v1.y;
		return *this;
	}
};

struct Rect {
	float X, Y;
	int width, height;
	Rect(float _X, float _Y, int _wid, int _heig) {
		X = _X; Y = _Y; width = _wid; height = _heig;
	}
};