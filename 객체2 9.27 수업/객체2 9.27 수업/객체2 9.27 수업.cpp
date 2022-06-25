//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Tmp {
//private:
//	char* _name;
//public:
//	Tmp(const char* name) :_name{ new char[strlen(name) + 1] } {
//		for (int i{ 0 }; name[i] != '\0'; i++) {                   
//			_name[i] = name[i];
//			
//		}
//		_name[strlen(name)] = '\0';
//		
//	}
//	//Tmp(const Tmp& t): _name{t._name} {}      //암시적으로 생성되는 복사 생성자, 얕은 복사가 일어난다.
//	void display() const {
//		cout << _name << "\t" << static_cast<void*>(_name) << endl;
//	}
//	~Tmp() { delete[] _name; }   //객체가 소멸할 때 heap 메모리 비워주는 과정
//
//};
//
//int main() {
//	Tmp* ptr{ new Tmp{"pby"} };    //객체 동적 할당
//	Tmp t{ *ptr };               //ptr 객체를 복사하고 pby라는 값을 받는다. 얕은 복사가 일어난다.
//	ptr->display();
//		delete ptr;             //delete하면 Tmp 객체의 _name이 가리키는 heap 삭제 -> Tmp 객체 삭제 순서로 진행된다. 
// 		t.display();            //따라서 t 객체의 _name이 가리키는 대상이 없어지면서 쓰레기 값을 가지게 되고
//		                        //뿐만 아니라 소멸자 부분에서 이미 비어있는 부분을 delete 하려는 과정에서 런타임 에러 발생   
//                              //★암시적으로 생성된 복사 생성자가 얕은 복사로 복사하기 때문에
//
//
//
//
//
//
//	                                         //ptr  ->   Tmp 객체
//	                                         //                 
//	                                         //            _name    ->    pby\0
//	return 0;                                // 
//}                                            // 
//                                             // t 객체
//                                             //
//                                             //  _name   -> pby\0     
//											 //                 t 객체의 _name 또한 ptr 객체의 _name이 가리키는 pby\0을 가리킨다.
//                                             //                  (얕은 복사)
//


//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Tmp {
//private:
//	char* _name;
//public:
//	Tmp(const char* name) :_name{ new char[strlen(name) + 1] } {      
//		for (int i{ 0 }; name[i] != '\0'; i++) {                   
//			_name[i] = name[i];
//			
//		}
//		_name[strlen(name)] = '\0';
//		
//	}
//	Tmp(const Tmp& t): Tmp{t._name} {                  //생성자를 호출해 _name 새로 동적 할당, 이 부분에서 깊은 복사가 일어난다.
//		for (int i{ 0 }; t._name[i] != '\0'; i++) {     //매개변수 생성자에서 실행된 과정이 똑같이 적용된다.   
//			_name[i] = t._name[i];        
//
//		}
//		_name[strlen(t._name)] = '\0';
//
//
//	}
//
//	/*Tmp(const Tmp& t) : _name{ new char[strlen(t._name) + 1] } {   //생성자 호출 안하고 할 시에는 
//		for (int i{ 0 }; t._name[i] != '\0'; i++) {                  //동적 할당을 새로 해줘야한다. 
//			_name[i] = t._name[i];
//
//		}
//		_name[strlen(t._name)] = '\0';
//
//
//	}*/
//	
//	void display() const {
//		cout << _name << "\t" << static_cast<void*>(_name) << endl;
//	}
//	~Tmp() { delete[] _name; }  
//
//};
//
//int main() {
//	Tmp* ptr{ new Tmp{"pby"} };    
//	Tmp t{ *ptr };        
//	ptr->display();
//	delete ptr;
//	t.display();
//	
//						
//
//	return 0;
//}

//r-value 참조

//void funA(int a)    //lvalue, rvalue 둘 다 가능
//void funB(int& a)   //lvalue 만 가능
//void funC(int&& a)  //rvalue 만 가능
//만약 void fun(const int& a),  void fun(int&& a)가 있다면 fun(1)은 어떤 함수로 연결될까?
//: void fun(int&& a)가 더 적합하기에 이 함수로 연결된다.


//move constructor

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Tmp {
//private:
//	int _num{ 0 };
//public:
//	Tmp() {}
//	Tmp(const Tmp& t) { cout << "복사 생성자"; }   
//	Tmp(Tmp&& r) noexcept { cout << "이동 생성자"; }    //rvalue를 받을 떄 이동 생성자로 받는다   
//	                                                    //만약 이동 생성자가 없으면 복사 생성자로 rvalue를 받는다. 
//
//};
//
//Tmp fun() {
//
//	cout << "function" << endl;
//	Tmp tmp;
//	return tmp;     
//}
//
//int main() {
//
//	Tmp t = fun();    //임시객체가 함수가 있던 자리에 오게 된다, 임시 객체는 해당 라인이 끝나면 사라진다. (rvalue)
//
//	return 0;
//}

//이동 생성자 사용 예시 (rvalue일 때 얕은 복사가 유리한 경우)

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Tmp {
//private:
//	char* _name;
//public:
//	Tmp(const char* name) :_name{ new char[strlen(name) + 1] } {      
//		for (int i{ 0 }; name[i] != '\0'; i++) {                   
//			_name[i] = name[i];
//			
//		}
//		_name[strlen(name)] = '\0';
//		
//	}
//	Tmp(const Tmp& t): Tmp{t._name} {                     //깊은 복사 
//		
//		cout << "복사 생성자" << endl;
//
//	}
//	Tmp(Tmp&& r) noexcept : _name(r._name) {             //얕은 복사
//		cout << "이동 생성자" << endl;
//		r._name = nullptr;
//	}
//	
//	~Tmp() { delete[] _name; }
//
//};
//
//Tmp fun() {
//	Tmp tmp{ "pby" };
//	return tmp;
//}
//
//int main() {
//	Tmp t = fun();                //Tmp t   =    rvalue*/
//                                                 //_name ---->  pby\0*/      
//	
//						
// 
//                                 // _name  ------------------>   pby\0*/
//	return 0;                                        
//}                               //rvalue에 _name이 가리키던 pby\0을 Tmp t에 _name이 얕은 복사로 가리키지만 
//                                //임시 객체 소멸자 호출 직전에 r._name = nullptr을 통해 heap 메모리 연결을 끊어 
//                                //Tmp t에 _name 한테 소유권을 양도하는 코드
//                                //★얕은 복사가 유용한 경우


//#include<iostream>
//using namespace std;
//
//int main() {
//
//    int* a = new int{ 10 };
//    int* b = a;
//    a = nullptr;      //a에 부여된 동적 할당을 없애주는 부분 a는 nullptr이 된다. 
//
//    cout << *a;     //a가 nullptr이기 때문에 아무 값도 안 가리킨다. 따라서 주소를 통해 값에 접근 할 수는 없다.
//    return 0;       //따라서 컴파일러는 아무 값도 출력하지 않는다.
//}                   


//문자열 연습
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//void fun(const char* name) {
//
//	char* const _name{ new char[strlen(name) + 1] };       //const 뒤에 붙이면 대상 변경 불가능, 값 변경 가능
//	//const char* _name{ new char[strlen(name) + 1] };      //const 앞에 붙이면 값 변경 불가능, 대상 변경 가능
//	//_name = "ptr";   
//
//
//	for (int i{ 0 }; name[i] != '\0'; i++) {
//		_name[i] = name[i];
//	}
//	_name[strlen(name) + 1] = '\0';
//	cout << &_name<<endl;                 //문자열 시작 주소                  
//	cout << *_name<<endl;                //문자열 시작 값 h
// delete _name;
//}
//int main() {
//
//	fun("hello");
//	
//	
//	
//	return 0;
//}

//char*와 char array 차이점 
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main() {
//    const char* str1 = "KOREA";  //문자열이 저장된 위치의 시작주소를 str1이라는 포인터 변수가 가리키고 있는 것
//
//    char str2[] = "KOREA";    //문자열의 시작주소를 갖고 있다.
//
//    str1[1] = 'A';        //따라서 str1의 값을 변경할 수 없기에 에러 발생
//    str2[1] = 'A';        //반면에 str2의 값은 변경할 수 있다.
//   
//
//    return 0;
//}