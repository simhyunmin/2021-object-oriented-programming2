//istream: cin
//ostream: cout


//#include<iostream>
//using namespace std;
//
//int main() {
//	int a{ 0 };
//	cin >> a;
//	//cin �Է�
//    //white space ���� 1 3 �Է� ���� �� ����
//	//input stream �ȿ� ���� ������ �޾Ƶ��̴� Ư���� ���� �ִ�. 
//	//input stream
//	//[A                ]
//	//a�� int���̶� ���ڰ� ������ fail bit 0->1�� �Ǽ� �����Ѵ�.
//	
//
//	while (!cin.eof()) {                                              
//		if (cin.fail()) {                                           
//			cin.clear();          //flag bit��(fail bit) 1���� 0���� �ٲ��ش�.  
//			cin.ignore(255, '\n');   //stream���� ���� ����� �Լ�   ignore(ũ��, ������) 
//		}                            // �����ڿ� ����Ű�� �Է��ϸ� stream�� ����Ű���� �����Ѵ�.     
//		                             //input stream�� ����ְ� flag bit�� �ʱ�ȭ���ִ� ������ �ʿ��ϱ� ������ clear, ignore �Լ� �� �� ����ؾ��Ѵ�. 
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
//				cout << "���� �ڵ� ����" << endl;
//				cin.clear();
//				cin.ignore(255, '\n');
//				continue;
//			}
//			cout << "����" << endl;
//			break;
//		}
//		
//	cout << a << endl;
//
//	return 0;
//}

//EOF   cirl + z
//           + D
//flag bit�� 1���� 0���� �ٲ��ش�.  //flag bit 0 -> 1
//         fail  eof
//   0   0   0   0     (flag)
//���ÿ��� 0�̶�� ���� ������ �ִٰ� fail, eof �ϸ� 1�� �ٲ��
 //��� �ø��� ������� �����


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

//>>, << �����ε� ������
//�����Լ��� �ۿ� ����
//#include<iostream>
//using namespace std;
//
////cout << t �� ���ʿ� �� ��ü�� �ٸ� ��ü�� ���� ������ ����� ����(2+t�� ����� ����)
//
//class Tmp {
//private:
//	int _a;
//	int _b;
//	friend istream& operator>>(istream& cin, Tmp& right) {
//		cin >> right._a;
//		cin.ignore(3, '\n');       //�Է� ������ '-' ����
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
//	cout << (t1 + t2) << endl;    //t1+t2  �� return Tmp(_a + right._a) �ӽ� ��ü�� ���Ϲޱ� ������ rvalue�� �ǰ� ����
//	                              // << ������ �����ε� �κп��� const Tmp& right �� ���� rvalue�� �Է¹��� �� �ְ� �������
//                                //���� cin �κ��̶�� const ����� ������ �ȉ�
//	return 0;
//}


//= ������ �����ε�(���� ������ �����ε�)
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
//		_a = right._a; _b = right._b;       //�����Ϸ��� �Ͻ������� �������
//		return *this;                       //�ʱ�ȭ �κп��� �ؾ��� ex) Tmp t1 = t2;
//                                          //���� ������
//		                                    //���� ���� �ۿ� ������� �ʴ´�.
//                                          
//                                          
//	}
//	Tmp& operator=(Tmp&& right) noexcept {
//		_a = right._a; _b = right._b;      //�̵� ���� ������
//		return *this;                      //�̹� �ʱ�ȭ �Ǿ��ٰ� ������              ex) Tmp t1;
//                                                                                        t1 = t2;
//	}                                      //���� ���� �Ҵ����� ���� ������ ����� �� 
//	                                       //�̹� ����Ű�� �ִ� �޸𸮸� �������ְ� 
//	                                       //���� �����Ҵ� ���ش����� ��������� �Ͼ����
//};                                       // ���� t1 = t1; �� �� �޸𸮸� ����ָ� ������ �޸𸮰� ���󰡴� ���̱� ������ if���� ���� ó�� �������
//                                                                                                          //operator=(const Tmp& r)�� �� 
//                                                                                                          //if(&r != this) �̷��� �������
//int main() {                             //*this�� non const �̱� ������ ������ ��������� ���� �ּҸ� ���Ѵ�.
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
//	Tmp() = default;  //�⺻ ������
//	//Tmp(const Tmp& right) = default;  //���� ������
//	//Tmp(Tmp&& right) = default;      //�̵� ������
//	Tmp& operator=(const Tmp& right) = default;     //���� ������
//	Tmp& operator=(Tmp&& right)noexcept = default;     //�̵� ���� ������
//	~Tmp() = default;   //�Ҹ���
//
//};
//
//int main() {
//	Tmp t1;
//	t1 = Tmp{};
//	Tmp t2 = t1;     //��������� ���ǵ� ���� ������ �̵� ���� �����ڰ� ���� ��
//	                 //���� �����ڿ� �̵� �����ڴ� �Ͻ������� �������� �ʴ´�.
//
//	return 0;
//}

//++, -- �����ε� ������
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
//		return t;  //lvalue ����
//	}
//	Tmp& operator++() {
//		++_a;           //postfix
//		return *this;   //rvalue ����
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

//[] ������ �����ε� (�迭 ������)
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
//	int operator[](int index) const {    //��ü�� const�� �����Ǿ��� ��� ���Ǵ� ����Լ�
//		return _p[index];                //���۷����� �����ϰ� �Ǹ� const �Ӽ��� ���� �� �ֱ� ������ �׳� ����
//	}
//	~Tmp() { delete[] _p; }
//};
//void fun(const Tmp& t) {
//	cout << t[2] << endl;
//}
//
//int main() {
//	Tmp arr{ 5 };
//	arr[2] = 3;   //arr[2]�� lvalue �̱� ������ return �ҋ� ���۷��� Ÿ������ ����
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
//	operator int() const {              //� �⺻ Ÿ������ �ٲ� ������ Ÿ�� ����(int)
//		return _year + 365 + _day;      // ��ü->����(����ȯ)
//	}
//}; 
//
//int main() {
//	Tmp t{ 1000 };
//	t.display();
//
//	Tmp t2 = 2000;          //explicit ���� �ÿ� ������, �Ͻ��� ��ȯ
//	t2.display();
//
//	static_cast<Tmp>(2000).display();       //����� ��ȯ    ���� -> ��ü
//	cout << static_cast<int>(t) << endl;   //��ü -> ����(����ȯ)
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
//	operator int() const {              //� �⺻ Ÿ������ �ٲ� ������ Ÿ�� ����(int)
//		return _a;      // ��ü->����(����ȯ)
//	}
//};
//
//int main() {
//	Tmp t{ 1 };
//	cout << static_cast<int>(t) << endl;   //��ü -> ����(����ȯ)
//
//	return 0;
//}


