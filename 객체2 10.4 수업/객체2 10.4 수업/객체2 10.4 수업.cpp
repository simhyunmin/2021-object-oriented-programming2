//istream: cin
//ostream: cout


//#include<iostream>
//using namespace std;
//
//int main() {
//	int a{ 0 };
//	cin >> a;
//	//cin 입력
//    //white space 무시 1 3 입력 받을 수 있음
//	//input stream 안에 값이 있으면 받아들이는 특성을 갖고 있다. 
//	//input stream
//	//[A                ]
//	//a는 int형이라 문자가 들어오면 fail bit 0->1이 되서 실패한다.
//	
//
//	while (!cin.eof()) {                                              
//		if (cin.fail()) {                                           
//			cin.clear();          //flag bit를(fail bit) 1에서 0으로 바꿔준다.  
//			cin.ignore(255, '\n');   //stream에서 값을 지우는 함수   ignore(크기, 구분자) 
//		}                            // 구분자에 엔터키를 입력하면 stream의 엔터키까지 무시한다.     
//		                             //input stream을 비워주고 flag bit를 초기화해주는 과정이 필요하기 때문에 clear, ignore 함수 둘 다 사용해야한다. 
//		cout << a << endl;                             
//		cin >> a;                                       
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//	int a{ 0 };
//
//	
//		while (!cin.eof()) {
//			cin >> a;
//			if (cin.fail()) {
//				cout << "실패 코드 실행" << endl;
//				cin.clear();
//				cin.ignore(255, '\n');
//				continue;
//			}
//			cout << "성공" << endl;
//			break;
//		}
//		
//	cout << a << endl;
//
//	return 0;
//}

//EOF   cirl + z
//           + D
//flag bit를 1에서 0으로 바꿔준다.  //flag bit 0 -> 1
//         fail  eof
//   0   0   0   0     (flag)
//평상시에는 0이라는 값을 가지고 있다가 fail, eof 하면 1로 바뀐다
 //깃발 올리고 내리고랑 비슷함


//#include<iostream>
//using namespace std;
//
//int main() {
//	int a;
//	int b;
//	cin.ignore(3, '(');
//	cin >> a;
//	cin.ignore(3, ')');
//	cin.ignore(3, '(');
//	cin >> b;
//	cin.ignore(3, ')');
//	
//	cout << a<<" "<<b ;
//
//
//	return 0;
//}

//>>, << 오버로딩 연산자
//전역함수로 밖에 못함
//#include<iostream>
//using namespace std;
//
////cout << t 는 왼쪽에 내 객체와 다른 객체가 오기 때문에 멤버로 못함(2+t와 비슷한 형식)
//
//class Tmp {
//private:
//	int _a;
//	int _b;
//	friend istream& operator>>(istream& cin, Tmp& right) {
//		cin >> right._a;
//		cin.ignore(3, '\n');       //입력 받을때 '-' 무시
//		cin >> right._b;
//		return cin;
//	}
//	friend ostream& operator<<(ostream& cout, const Tmp& right) {
//		cout << right._a<< right._b << endl;
//		return cout;
//	}
//
//public:
//	explicit Tmp(int a = 0, int b = 0): _a{a}, _b{b} {}
//
//};
//
//int main() {
//	Tmp t;
//	cin >> t;
//	cout << t;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//
//
//
//	friend ostream& operator<<(ostream& cout, const Tmp& right) {
//		cout << right._a << endl;
//		return cout;
//	}
//
//public:
//	explicit Tmp(int a = 0) : _a{a} {}
//	Tmp operator+(const Tmp& right) {
//		return Tmp(_a + right._a);
//	}
//};
//
//int main() {
//	Tmp t1{ 4 };
//	Tmp t2{ 3 };
//	cout << (t1 + t2) << endl;    //t1+t2  는 return Tmp(_a + right._a) 임시 객체를 리턴받기 때문에 rvalue가 되고 따라서
//	                              // << 연산자 오버로딩 부분에서 const Tmp& right 를 통해 rvalue도 입력받을 수 있게 해줘야함
//                                //만약 cin 부분이라면 const 절대로 넣으면 안됌
//	return 0;
//}


//= 연산자 오버로딩(대입 연산자 오버로딩)
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//	int _b;
//public:
//	explicit Tmp(int a = 0, int b = 0):_a{a} , _b{b}{}
//	Tmp& operator=(const Tmp& right) {
//		_a = right._a; _b = right._b;       //컴파일러가 암시적으로 만들어줌
//		return *this;                       //초기화 부분에서 해야함 ex) Tmp t1 = t2;
//                                          //대입 연산자
//		                                    //얕은 복사 밖에 수행되지 않는다.
//                                          
//                                          
//	}
//	Tmp& operator=(Tmp&& right) noexcept {
//		_a = right._a; _b = right._b;      //이동 대입 연산자
//		return *this;                      //이미 초기화 되었다고 생각함              ex) Tmp t1;
//                                                                                        t1 = t2;
//	}                                      //따라서 동적 할당으로 대입 연산자 사용할 때 
//	                                       //이미 가리키고 있는 메모리를 삭제해주고 
//	                                       //새로 동적할당 해준다음에 복사과정이 일어나야함
//};                                       // 만약 t1 = t1; 일 때 메모리를 비워주면 원본의 메모리가 날라가는 것이기 때문에 if문을 통해 처리 해줘야함
//                                                                                                          //operator=(const Tmp& r)일 때 
//                                                                                                          //if(&r != this) 이렇게 해줘야함
//int main() {                             //*this는 non const 이기 때문에 형식을 맞춰줘야함 따라서 주소를 비교한다.
//	Tmp t1;
//	t1 = Tmp{ 3 };
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//	int _b;
//public:
//	Tmp() = default;  //기본 생성자
//	//Tmp(const Tmp& right) = default;  //복사 생성자
//	//Tmp(Tmp&& right) = default;      //이동 생성자
//	Tmp& operator=(const Tmp& right) = default;     //대입 연산자
//	Tmp& operator=(Tmp&& right)noexcept = default;     //이동 대입 연산자
//	~Tmp() = default;   //소멸자
//
//};
//
//int main() {
//	Tmp t1;
//	t1 = Tmp{};
//	Tmp t2 = t1;     //명시적으로 정의된 대입 연산자 이동 대입 연산자가 있을 때
//	                 //복사 생성자와 이동 생성자는 암시적으로 생성되지 않는다.
//
//	return 0;
//}

//++, -- 오버로딩 연산자
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//
//	friend ostream& operator<<(ostream& out, const Tmp& right) {
//		cout << right._a;
//		return out;
//	}
//public:
//	Tmp(int a =1) : _a{a} {}
//	Tmp operator++(int) {
//		Tmp t(*this);     //prefix 
//		++_a;
//		return t;  //lvalue 리턴
//	}
//	Tmp& operator++() {
//		++_a;           //postfix
//		return *this;   //rvalue 리턴
//	}
//
//	//prototype(global function)
//	/*Date operator++(Date&, int);
//	d1++becomes operator++(d1, 0)*/
//};
//
//int main() {
//	Tmp t{ 3 };
//	cout << t++ << endl;
//	cout << ++t << endl;
//
//	return 0;
//}

//[] 연산자 오버로딩 (배열 연산자)
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _size;
//	int* _p;
//public:
//	Tmp(int size) :_size{ size }, _p{ new int[_size] {} }{}
//	int& operator[](int index) {
//		return _p[index];
//	}
//	int operator[](int index) const {    //객체가 const로 생성되었을 경우 사용되는 멤버함수
//		return _p[index];                //레퍼런스로 리턴하게 되면 const 속성이 깨질 수 있기 때문에 그냥 리턴
//	}
//	~Tmp() { delete[] _p; }
//};
//void fun(const Tmp& t) {
//	cout << t[2] << endl;
//}
//
//int main() {
//	Tmp arr{ 5 };
//	arr[2] = 3;   //arr[2]가 lvalue 이기 때문에 return 할떄 레퍼런스 타입으로 리턴
//	fun(arr);
//
//	return 0;
//}

//casting operator overloading
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _year;
//	int _day;
//public:
//	/*explicit*/ Tmp(int day) :_year{ day / 365 }, _day{ day % 365 } {
//
//	}
//
//	void display() {
//		cout << "year: " << _year << ", day: " << _day << endl;
//	}
//	operator int() const {              //어떤 기본 타입으로 바꿀 것인지 타입 선택(int)
//		return _year + 365 + _day;      // 객체->정수(역변환)
//	}
//}; 
//
//int main() {
//	Tmp t{ 1000 };
//	t.display();
//
//	Tmp t2 = 2000;          //explicit 없을 시에 가능함, 암시적 변환
//	t2.display();
//
//	static_cast<Tmp>(2000).display();       //명시적 변환    정수 -> 객체
//	cout << static_cast<int>(t) << endl;   //객체 -> 정수(역변환)
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//	
//public:
//	/*explicit*/ Tmp(int a) : _a{a} {
//
//	}
//
//	void display() {
//		cout << _a << endl;
//	}
//	operator int() const {              //어떤 기본 타입으로 바꿀 것인지 타입 선택(int)
//		return _a;      // 객체->정수(역변환)
//	}
//};
//
//int main() {
//	Tmp t{ 1 };
//	cout << static_cast<int>(t) << endl;   //객체 -> 정수(역변환)
//
//	return 0;
//}


