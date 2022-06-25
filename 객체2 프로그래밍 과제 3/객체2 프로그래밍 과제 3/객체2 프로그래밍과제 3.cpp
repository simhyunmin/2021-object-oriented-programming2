#include "Point.h"


//class Point {
//private:
//	int x, y;
//	void incrementx(){++x;}
//	void incrementy() {++y;}
//	void decrementx() {--x;}
//	void decrementy() {--y;}
//	friend Point operator++(Point& left, int) {
//		Point p{left};
//		left.incrementx();
//		left.incrementy();
//		return p;
//	}
//
//	friend istream& operator>>(istream& cin, Point& right) {
//		cin.ignore(10, '(');
//		cin >> right.x;
//		cin.ignore(10, ',');
//		cin >> right.y;
//		cin.ignore(10, ')');
//		return cin;
//	}
//	friend ostream& operator<<(ostream& cout, const Point right) {
//		cout <<"("<< right.x <<", " << right.y<<")";
//		return cout;
//	}
//
//	 friend bool operator!=(Point left, Point right) {
//		 return !(left == right);
//	}
//	 friend bool operator<=(const Point left, const Point right) {
//		if ((left.x+left.y< right.x+ right.y)|| ((left.x == right.x) && (left.y == right.y))) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	 friend int operator*(const Point left, const Point right) {
//		
//		return ((left.x)*(right.x)+(left.y)*(right.y));
//	}
//
//	friend Point& operator-=( Point& left,Point right) {  
//		for (int i{ 0 }; i < right.x; i++) {
//			left.decrementx();
//		}
//		for (int i{ 0 }; i < right.y; i++) {
//			left.decrementy();
//		}
//		return left;
//	}
//public:
//
//	bool operator==(const Point right) {
//		if ((x == right.x)&& (y== right.y)) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	
//	bool operator>(const Point right) {
//		if (x + y> right.x+ right.y) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	Point operator+(const Point right) {
//		Point p;
//		p.x = x + right.x;
//		p.y = y + right.y;
//		return p;
//	}
//
//	Point& operator++() {
//		incrementx();
//		incrementy();
//		return *this;
//	}
//
//	Point& operator+=(const Point right) {
//		for (int i{ 0 }; i < right.x; i++) {
//			incrementx();
//		}
//		for (int i{ 0 }; i < right.y; i++) {
//			incrementy();
//		}
//		
//		return *this;
//	}
//	
//};
//

int main() {
	Point p1, p2;
	cout << "input 2 points: ";
	cin >> p1 >> p2;

	if (p1 == p2) cout << "p1 == p2" << endl;
	if (p1 != p2)cout << "p1 != p2" << endl;
	if (p1 > p2)cout << "p1 > p2" << endl;
	if (p1 <= p2) cout << "p1 <= p2" << endl;

	cout << endl;
	cout << "p1 + p2 = " << (p1 + p2) << endl;
	cout << "p1 * p2 = " << (p1 * p2) << endl;

	cout << endl;
	p1 -= p2++;
	cout << "p1 -= p2++" << endl;
	++p1 += p2;
	cout << "++p1 += p2" << endl;
	cout << "p1 = " << p1 << endl;


	return 0;
}
