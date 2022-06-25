#include "Point.h"

void toString(int x, int y);    //toString 함수의 프로토타입

int Point::count{ 0 };   //정적 멤버 변수 count 초기화

ostringstream Point::output;  //정적 객체 초기화

Point::Point() :x{ 0 }, y{ 0 } {
	

	count++;
	copyCount = count;    //객체의 수를 세는 변수의 복사를 통해 객체가 배열의 몇 번째 자리에 위치하고 있는지 알아낸다. (객체 소멸때 몇 번째 객체가 소멸하는지 알기 위해서)

	cout << "Point " << count << " constructor." << endl;

	do {
		cout << "Input x and y for Point: ";
		cin >> x;
		cin >> y;

		if (((0 >= x) || (x >= 100)) || ((0 >= y) || (y >= 100))) {         //x가 0이하 또는 100이상 아니면 y가 0이하 또는 100이상이면 do while문 다시 실행(조건 만족할때까지)
			cout << "Out of range. Input again" << endl;

		}

	} while (((0 >= x) || (x >= 100)) || ((0 >= y) || (y >= 100)));
	cout << endl;
	toString( x, y);            //생성된 좌표를 받고 스트림에 저장하는 부분

}


Point::~Point() {
	cout << "Point " << copyCount << " destructor." << endl;
}

void Point::getcount() {       //count 값을 출력해주는 정적 멤버 함수 
	cout << count;
}

void toString(int x, int y) {

	if (x / 10 != 0) {
		Point::output << "x = " << x << ", ";
	}                                                  //x를 10으로 나누었을 때 몫이 0이 아니면 10 이상의 숫자이므로 조건에 맞게 문장 설계
	else {
		Point::output << "x = 0" << x << ", ";
	}

	if (y / 10 != 0) {
		Point::output << "y = " << y;
	}
	else {
		Point::output << "y = 0" << y;
	}

	Point::output << endl;
}

