#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<sstream>
using namespace std;

class Point {
private:
	int x, y;
	static int count; //��ü�� ���� ���� ����
public:    
	static ostringstream output;               //�����ڿ��� toString �Լ��� �̿��� output ��ü�� ��ǥ�� ������ �� �ֵ��� �ϰ�, 
	                                           //toString �Լ��� ����ǵ� ���ڿ��� output ��ü�� �����ֵ��� �ϱ� ���� �������� output ��ü ����
	int copyCount{ 0 };
	Point();
	~Point();

	static void getcount();

};


#endif