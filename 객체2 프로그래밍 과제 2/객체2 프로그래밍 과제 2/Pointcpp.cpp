#include "Point.h"

void toString(int x, int y);    //toString �Լ��� ������Ÿ��

int Point::count{ 0 };   //���� ��� ���� count �ʱ�ȭ

ostringstream Point::output;  //���� ��ü �ʱ�ȭ

Point::Point() :x{ 0 }, y{ 0 } {
	

	count++;
	copyCount = count;    //��ü�� ���� ���� ������ ���縦 ���� ��ü�� �迭�� �� ��° �ڸ��� ��ġ�ϰ� �ִ��� �˾Ƴ���. (��ü �Ҹ궧 �� ��° ��ü�� �Ҹ��ϴ��� �˱� ���ؼ�)

	cout << "Point " << count << " constructor." << endl;

	do {
		cout << "Input x and y for Point: ";
		cin >> x;
		cin >> y;

		if (((0 >= x) || (x >= 100)) || ((0 >= y) || (y >= 100))) {         //x�� 0���� �Ǵ� 100�̻� �ƴϸ� y�� 0���� �Ǵ� 100�̻��̸� do while�� �ٽ� ����(���� �����Ҷ�����)
			cout << "Out of range. Input again" << endl;

		}

	} while (((0 >= x) || (x >= 100)) || ((0 >= y) || (y >= 100)));
	cout << endl;
	toString( x, y);            //������ ��ǥ�� �ް� ��Ʈ���� �����ϴ� �κ�

}


Point::~Point() {
	cout << "Point " << copyCount << " destructor." << endl;
}

void Point::getcount() {       //count ���� ������ִ� ���� ��� �Լ� 
	cout << count;
}

void toString(int x, int y) {

	if (x / 10 != 0) {
		Point::output << "x = " << x << ", ";
	}                                                  //x�� 10���� �������� �� ���� 0�� �ƴϸ� 10 �̻��� �����̹Ƿ� ���ǿ� �°� ���� ����
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

