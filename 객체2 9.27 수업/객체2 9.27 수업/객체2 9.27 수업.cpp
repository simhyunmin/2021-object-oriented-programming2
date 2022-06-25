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
//	//Tmp(const Tmp& t): _name{t._name} {}      //�Ͻ������� �����Ǵ� ���� ������, ���� ���簡 �Ͼ��.
//	void display() const {
//		cout << _name << "\t" << static_cast<void*>(_name) << endl;
//	}
//	~Tmp() { delete[] _name; }   //��ü�� �Ҹ��� �� heap �޸� ����ִ� ����
//
//};
//
//int main() {
//	Tmp* ptr{ new Tmp{"pby"} };    //��ü ���� �Ҵ�
//	Tmp t{ *ptr };               //ptr ��ü�� �����ϰ� pby��� ���� �޴´�. ���� ���簡 �Ͼ��.
//	ptr->display();
//		delete ptr;             //delete�ϸ� Tmp ��ü�� _name�� ����Ű�� heap ���� -> Tmp ��ü ���� ������ ����ȴ�. 
// 		t.display();            //���� t ��ü�� _name�� ����Ű�� ����� �������鼭 ������ ���� ������ �ǰ�
//		                        //�Ӹ� �ƴ϶� �Ҹ��� �κп��� �̹� ����ִ� �κ��� delete �Ϸ��� �������� ��Ÿ�� ���� �߻�   
//                              //�ھϽ������� ������ ���� �����ڰ� ���� ����� �����ϱ� ������
//
//
//
//
//
//
//	                                         //ptr  ->   Tmp ��ü
//	                                         //                 
//	                                         //            _name    ->    pby\0
//	return 0;                                // 
//}                                            // 
//                                             // t ��ü
//                                             //
//                                             //  _name   -> pby\0     
//											 //                 t ��ü�� _name ���� ptr ��ü�� _name�� ����Ű�� pby\0�� ����Ų��.
//                                             //                  (���� ����)
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
//	Tmp(const Tmp& t): Tmp{t._name} {                  //�����ڸ� ȣ���� _name ���� ���� �Ҵ�, �� �κп��� ���� ���簡 �Ͼ��.
//		for (int i{ 0 }; t._name[i] != '\0'; i++) {     //�Ű����� �����ڿ��� ����� ������ �Ȱ��� ����ȴ�.   
//			_name[i] = t._name[i];        
//
//		}
//		_name[strlen(t._name)] = '\0';
//
//
//	}
//
//	/*Tmp(const Tmp& t) : _name{ new char[strlen(t._name) + 1] } {   //������ ȣ�� ���ϰ� �� �ÿ��� 
//		for (int i{ 0 }; t._name[i] != '\0'; i++) {                  //���� �Ҵ��� ���� ������Ѵ�. 
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

//r-value ����

//void funA(int a)    //lvalue, rvalue �� �� ����
//void funB(int& a)   //lvalue �� ����
//void funC(int&& a)  //rvalue �� ����
//���� void fun(const int& a),  void fun(int&& a)�� �ִٸ� fun(1)�� � �Լ��� ����ɱ�?
//: void fun(int&& a)�� �� �����ϱ⿡ �� �Լ��� ����ȴ�.


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
//	Tmp(const Tmp& t) { cout << "���� ������"; }   
//	Tmp(Tmp&& r) noexcept { cout << "�̵� ������"; }    //rvalue�� ���� �� �̵� �����ڷ� �޴´�   
//	                                                    //���� �̵� �����ڰ� ������ ���� �����ڷ� rvalue�� �޴´�. 
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
//	Tmp t = fun();    //�ӽð�ü�� �Լ��� �ִ� �ڸ��� ���� �ȴ�, �ӽ� ��ü�� �ش� ������ ������ �������. (rvalue)
//
//	return 0;
//}

//�̵� ������ ��� ���� (rvalue�� �� ���� ���簡 ������ ���)

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
//	Tmp(const Tmp& t): Tmp{t._name} {                     //���� ���� 
//		
//		cout << "���� ������" << endl;
//
//	}
//	Tmp(Tmp&& r) noexcept : _name(r._name) {             //���� ����
//		cout << "�̵� ������" << endl;
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
//}                               //rvalue�� _name�� ����Ű�� pby\0�� Tmp t�� _name�� ���� ����� ����Ű���� 
//                                //�ӽ� ��ü �Ҹ��� ȣ�� ������ r._name = nullptr�� ���� heap �޸� ������ ���� 
//                                //Tmp t�� _name ���� �������� �絵�ϴ� �ڵ�
//                                //�ھ��� ���簡 ������ ���


//#include<iostream>
//using namespace std;
//
//int main() {
//
//    int* a = new int{ 10 };
//    int* b = a;
//    a = nullptr;      //a�� �ο��� ���� �Ҵ��� �����ִ� �κ� a�� nullptr�� �ȴ�. 
//
//    cout << *a;     //a�� nullptr�̱� ������ �ƹ� ���� �� ����Ų��. ���� �ּҸ� ���� ���� ���� �� ���� ����.
//    return 0;       //���� �����Ϸ��� �ƹ� ���� ������� �ʴ´�.
//}                   


//���ڿ� ����
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//void fun(const char* name) {
//
//	char* const _name{ new char[strlen(name) + 1] };       //const �ڿ� ���̸� ��� ���� �Ұ���, �� ���� ����
//	//const char* _name{ new char[strlen(name) + 1] };      //const �տ� ���̸� �� ���� �Ұ���, ��� ���� ����
//	//_name = "ptr";   
//
//
//	for (int i{ 0 }; name[i] != '\0'; i++) {
//		_name[i] = name[i];
//	}
//	_name[strlen(name) + 1] = '\0';
//	cout << &_name<<endl;                 //���ڿ� ���� �ּ�                  
//	cout << *_name<<endl;                //���ڿ� ���� �� h
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

//char*�� char array ������ 
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main() {
//    const char* str1 = "KOREA";  //���ڿ��� ����� ��ġ�� �����ּҸ� str1�̶�� ������ ������ ����Ű�� �ִ� ��
//
//    char str2[] = "KOREA";    //���ڿ��� �����ּҸ� ���� �ִ�.
//
//    str1[1] = 'A';        //���� str1�� ���� ������ �� ���⿡ ���� �߻�
//    str2[1] = 'A';        //�ݸ鿡 str2�� ���� ������ �� �ִ�.
//   
//
//    return 0;
//}