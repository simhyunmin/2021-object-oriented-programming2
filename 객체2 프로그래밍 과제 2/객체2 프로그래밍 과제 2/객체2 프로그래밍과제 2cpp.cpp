#include "Point.h"

int main() {

	
	int size;    //�迭�� ũ�⸦ �����ϴ� ����

	cout << "The number of Point objects: ";
	Point::getcount();
	cout<< endl;

	cout << "Enter the size of Point array: ";
	cin >> size;
	cout << endl;

	Point* point = new Point[size];              //Point ��ü �迭 ���� �Ҵ� 
	                                             //�迭 ũ�� �κп� size ������ �����Ͽ� ���������� ũ�⸦ ������ �� �ֵ��� �Ͽ���


	cout << Point::output.str() << endl;         //output ��ü�� str�Լ��� �̿��� ����� ���ڿ��� ����ϴ� �κ�

	cout << "The number of Point objects: ";
	Point::getcount();
	cout << endl<<endl;


	delete[] point;         //���� �Ҵ� �޸� ����

	return 0;
}