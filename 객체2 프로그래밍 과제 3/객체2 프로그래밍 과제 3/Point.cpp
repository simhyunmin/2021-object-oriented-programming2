#include"Point.h"

void Point::incrementx() { ++x; }
void Point::incrementy() { ++y; }
void Point::decrementx() { --x; }
void Point::decrementy() { --y; }

Point operator++(Point& left, int a) {
	Point p{ left };
	left.incrementx();
	left.incrementy();
	return p;
}

istream& operator>>(istream& cin, Point& right) {
	cin.ignore(10, '(');
	cin >> right.x;
	cin.ignore(10, ',');
	cin >> right.y;
	cin.ignore(10, ')');
	return cin;
}
ostream& operator<<(ostream& cout, const Point right) {
	cout << "(" << right.x << ", " << right.y << ")";
	return cout;
}

bool operator!=(Point left, Point right) {
	return !(left == right);
}
bool operator<=(const Point left, const Point right) {
	if ((left.x + left.y < right.x + right.y) || ((left.x == right.x) && (left.y == right.y))) {
		return true;
	}
	else {
		return false;
	}
}
int operator*(const Point left, const Point right) {

	return ((left.x) * (right.x) + (left.y) * (right.y));
}

Point& operator-=(Point& left, Point right) {
	for (int i{ 0 }; i < right.x; i++) {
		left.decrementx();
	}
	for (int i{ 0 }; i < right.y; i++) {
		left.decrementy();
	}
	return left;
}


	bool Point::operator==(const Point right) {
		if ((x == right.x) && (y == right.y)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Point::operator>(const Point right) {
		if (x + y > right.x + right.y) {
			return true;
		}
		else {
			return false;
		}
	}
	Point Point::operator+(const Point right) {
		Point p;
		p.x = x + right.x;
		p.y = y + right.y;
		return p;
	}

	Point& Point::Point::operator++() {
		incrementx();
		incrementy();
		return *this;
	}

	Point& Point::operator+=(const Point right) {
		for (int i{ 0 }; i < right.x; i++) {
			incrementx();
		}
		for (int i{ 0 }; i < right.y; i++) {
			incrementy();
		}

		return *this;
	}
