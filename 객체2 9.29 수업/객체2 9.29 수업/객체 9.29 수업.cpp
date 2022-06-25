//operator overloading(연산자(함수) 오버로딩)
//연산자를 재정의하여 사용자 정의 클래스로 사용하는 것
//객체의 더하기 연산을 가능하게 해준다.
// 2가지 방법이 있다.

//1. class 멤버 함수
// 클래스 멤버 함수에 operator 멤버 함수를 만들고 
// 다른 클래스를 인자로 받아 연산하는 것

//2. 전역함수
// Frined 문법을 통해 클래스의 데이터 멤버를 사용해 연산

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	string s1{ "hello" };
//	string s2{ "hi" };
//
//	cout << (s1 + s2)<<boolalpha<<endl;
//	cout << (s1 == s2)<<endl;
//	cout << (s1 >= s2)<<endl;
//	cout << s1.substr(1, 3) << endl;    //substr()
//	                                    //substr(0, 14) 0부터 14까지의 문자열을 짤라서 출력해주는 함수
//	                                    //substr(14) 14부터 끝까지 출력해주는 함수
//	return 0;
//}


//오버로딩에 사용할 수 없는 연산자
//.     
//.*(pointer to member)
//::

//오버로딩 주의점
//바꿀 수 없는 부분
//1. 연산자의 우선 순위
//2. 연산자의 결합성(왼쪽에서 오른쪽, 오른쪽에서 왼쪽)(계산하는 방향)
//3. 피연산자의 숫자     (a + b 할때의 a, b 요소들의 개수)
//4. 기본 데이터 타입의 작동 방식
// 
// 명시적으로 오버로딩해야한다. (오버로딩 +, = 은 += 을 오버로드 할 수 없다)



//멤버함수로 오버로딩하기
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//public:
//	explicit Tmp(int a = 1) : _a{ a } { cout << a << "기본 생성자 호출"<<endl; }
//	Tmp operator+(const Tmp& right) {
//		Tmp t;
//		t._a = _a + right._a;
//
//		return t;
//	}
//
//	Tmp(const Tmp& t) :_a{ t._a } {
//		cout << _a << "복사 생성자 호출"<<endl;
//	}
//
//	Tmp operator-(const Tmp& right) {
//		
//
//		return Tmp{ _a - right._a };          //Tmp{ _a - right._a } 는 위에 return t 과정과 의미상 동일
//	}
//
//
//	void display() const {
//		cout << _a << endl;
//
//	}
//};
//
//Tmp test() {
//	Tmp t7;
//
//	return t7;
//}
//
//int main() {
//	Tmp t1{ 3 };
//	Tmp t2{ 5 };
//	Tmp t3{ t1 + t2 };   //복사 생성자 작동
//	//Tmp t3 = t1.operator+(t2)   //왼쪽에 있는 인스턴스의 멤버함수가 작동한다.
//	Tmp t4;
//	t4 = t1 - t2;   //컴파일러가 Tmp{ _a - right._a } 부분을 t4로 처리하기 때문에 복사생성자가 작동하지 않는다.
//	t3.display();
//	t4.display();
//	Tmp t5;
//	t5 = test();
//
//
//	return 0;
//}

//전역 함수로 오버로딩 받기
//남용하면 안되기 때문에 되도록 멤버함수 오버로딩 사용하기

//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//	friend Tmp operator+(const Tmp& left, const Tmp& rihgt);
//	friend Tmp operator-(const Tmp& left, const Tmp& rihgt);
//
//
//public:
//	explicit Tmp(int a = 1) : _a{ a } {
//
//	}
//	void display() const {
//		cout << _a << endl;
//	}
//
//
//};
//
//Tmp operator+(const Tmp& left, const Tmp& right) {
//
//	Tmp t;
//	t._a = left._a + right._a;
//
//	return t;
//}
//Tmp operator-(const Tmp& left, const Tmp& right) {
//	return Tmp{ left._a - right._a };
//}
//
//
//int main() {
//	Tmp t1{ 3 };
//	Tmp t2{ 2 };
//	Tmp t3;
//	t3 = t1 + t2;
//	t3.display();
//
//	return 0;
//}

//객체+4가 아닌 4+객체일때 처리 방법
//전역과 멤버 두 가지 방법 다 사용

//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//
//	friend Tmp operator+(int num, Tmp& right) {
//		
//		return right + num;   //객체 + int            전역의 결과 부분에 멤버 함수 호출
//		                      //right.operator(num)
//	}
//public:
//	explicit Tmp(int a = 1):_a{a} {}
//
//	Tmp operator+(int num) {
//		return Tmp{ _a + num };
//	}
//	void display() const {
//		cout << _a << endl;
//	}
//};
//
//int main() {
//	Tmp t1{ 3 };
//	Tmp t2 = t1 + 4;
//	t2 = 2 + t2;
//	t2.display();
//  
//}


//!= , == 연산자의 오버로딩
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _x;
//	int _y;
//
//public:
//	explicit Tmp(int x = 0, int y = 0): _x{x}, _y{y}{}
//	bool operator == (const Tmp& right) {
//		if (_x == right._x && _y == right._y) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	bool operator!=(const Tmp& right) {
//		return !(*this == right);
//	}
//
//};
//
//int main() {
//	Tmp t1{ 1, 2 };
//	Tmp t2{ 1, 2 };
//	if (t1 != t2) {
//		cout << "t1 != t2" << endl;
//	}
//	else {
//		cout << "t1 == t2" << endl;
//	}
//
//	return 0;
//}


//+= 연산자 오버로딩
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//	void increment() { ++_a; }
//
//public:
//	explicit Tmp(int a = 0) : _a{ a } {}
//	
//	Tmp& operator+=(int num) {
//		for (int i{ 0 }; i < num; i++) {
//			increment();
//		}
//		return *this;
//	}
//	void display() const {
//		cout << _a << endl;
//	}
//
//};
//
//int main() {
//	Tmp t{ 4 };
//	(t += 3) += 5;     //괄호 필수★    
//	                   //괄호 안하면 오류 발생  3+= 5 
//	t.display();
//
//	return 0;
//}



/*prefix increment, postfix increment

prefix increment*/ 
//
//#include<iostream>
//using namespace std;
//
//class test {
//private:
//	int _a;
//	void increment() { ++_a; }
//public:                   
//
//	test(int a = 1) :_a{ a } {}
//	
//
//	test& operator++() {        //prefix increment
//		                        /*단항연산자*/
//		increment();            //++a 연산 후 결과가 lvalue이다.
//		return *this;           //lvalue 리턴
//	}
//	test operator++(int a) {    //postfix increment
//		test temp{ *this };     //a++ 연산 후 결과가 rvalue 이다. 따라서 참조로 리턴 안하고 그냥 리턴
//		++temp;                 //현재 값을 저장해주고 값을 키운 다음에 저장해준 객체를 리턴
//		temp.display();         //rvalue 리턴
//		return temp;            
//	}
//	void display() {
//		cout << _a << endl;
//	}
//
//
//};
//
//int main() {
//
//	/*test t1{ 3 };
//	test t2{ 4 };
//	test t3 = t1++;
//	t3.display();*/
//
//	test t1{ 3 };
//	++t1;
//	t1.display();
//
//	return 0;
//}