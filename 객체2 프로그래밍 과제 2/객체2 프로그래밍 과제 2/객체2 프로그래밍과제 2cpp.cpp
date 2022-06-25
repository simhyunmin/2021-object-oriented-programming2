#include "Point.h"

int main() {

	
	int size;    //배열의 크기를 설정하는 변수

	cout << "The number of Point objects: ";
	Point::getcount();
	cout<< endl;

	cout << "Enter the size of Point array: ";
	cin >> size;
	cout << endl;

	Point* point = new Point[size];              //Point 객체 배열 동적 할당 
	                                             //배열 크기 부분에 size 변수를 대입하여 가변적으로 크기를 조정할 수 있도록 하였음


	cout << Point::output.str() << endl;         //output 객체의 str함수를 이용해 저장된 문자열을 출력하는 부분

	cout << "The number of Point objects: ";
	Point::getcount();
	cout << endl<<endl;


	delete[] point;         //동적 할당 메모리 해제

	return 0;
}