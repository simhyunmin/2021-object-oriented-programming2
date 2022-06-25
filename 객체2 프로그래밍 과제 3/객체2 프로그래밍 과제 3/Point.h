#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<sstream>
using namespace std;


class Point {
private:
	int x, y;
	
	friend Point operator++(Point& left, int);
	friend istream& operator>>(istream& cin, Point& right);
	friend ostream& operator<<(ostream& cout, const Point right);
	friend bool operator!=(Point left, Point right);
	friend bool operator<=(const Point left, const Point right);
	friend int operator*(const Point left, const Point right);
	friend Point& operator-=(Point& left, Point right);
public:
	void incrementx();
	void incrementy();
	void decrementx();
	void decrementy();

	bool operator==(const Point right);
	bool operator>(const Point right);
	Point operator+(const Point right);
	Point& operator++();
	Point& operator+=(const Point right);

};
#endif