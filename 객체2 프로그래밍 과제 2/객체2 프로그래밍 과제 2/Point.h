#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<sstream>
using namespace std;

class Point {
private:
	int x, y;
	static int count; //객체의 수를 세는 변수
public:    
	static ostringstream output;               //생성자에서 toString 함수를 이용해 output 객체에 좌표를 저장할 수 있도록 하고, 
	                                           //toString 함수가 종료되도 문자열이 output 객체에 남아있도록 하기 위해 정적으로 output 객체 생성
	int copyCount{ 0 };
	Point();
	~Point();

	static void getcount();

};


#endif