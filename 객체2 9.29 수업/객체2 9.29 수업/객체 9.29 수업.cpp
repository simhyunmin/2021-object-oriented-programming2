//operator overloading(������(�Լ�) �����ε�)
//�����ڸ� �������Ͽ� ����� ���� Ŭ������ ����ϴ� ��
//��ü�� ���ϱ� ������ �����ϰ� ���ش�.
// 2���� ����� �ִ�.

//1. class ��� �Լ�
// Ŭ���� ��� �Լ��� operator ��� �Լ��� ����� 
// �ٸ� Ŭ������ ���ڷ� �޾� �����ϴ� ��

//2. �����Լ�
// Frined ������ ���� Ŭ������ ������ ����� ����� ����

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
//	                                    //substr(0, 14) 0���� 14������ ���ڿ��� ©�� ������ִ� �Լ�
//	                                    //substr(14) 14���� ������ ������ִ� �Լ�
//	return 0;
//}


//�����ε��� ����� �� ���� ������
//.     
//.*(pointer to member)
//::

//�����ε� ������
//�ٲ� �� ���� �κ�
//1. �������� �켱 ����
//2. �������� ���ռ�(���ʿ��� ������, �����ʿ��� ����)(����ϴ� ����)
//3. �ǿ������� ����     (a + b �Ҷ��� a, b ��ҵ��� ����)
//4. �⺻ ������ Ÿ���� �۵� ���
// 
// ��������� �����ε��ؾ��Ѵ�. (�����ε� +, = �� += �� �����ε� �� �� ����)



//����Լ��� �����ε��ϱ�
//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//public:
//	explicit Tmp(int a = 1) : _a{ a } { cout << a << "�⺻ ������ ȣ��"<<endl; }
//	Tmp operator+(const Tmp& right) {
//		Tmp t;
//		t._a = _a + right._a;
//
//		return t;
//	}
//
//	Tmp(const Tmp& t) :_a{ t._a } {
//		cout << _a << "���� ������ ȣ��"<<endl;
//	}
//
//	Tmp operator-(const Tmp& right) {
//		
//
//		return Tmp{ _a - right._a };          //Tmp{ _a - right._a } �� ���� return t ������ �ǹ̻� ����
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
//	Tmp t3{ t1 + t2 };   //���� ������ �۵�
//	//Tmp t3 = t1.operator+(t2)   //���ʿ� �ִ� �ν��Ͻ��� ����Լ��� �۵��Ѵ�.
//	Tmp t4;
//	t4 = t1 - t2;   //�����Ϸ��� Tmp{ _a - right._a } �κ��� t4�� ó���ϱ� ������ ��������ڰ� �۵����� �ʴ´�.
//	t3.display();
//	t4.display();
//	Tmp t5;
//	t5 = test();
//
//
//	return 0;
//}

//���� �Լ��� �����ε� �ޱ�
//�����ϸ� �ȵǱ� ������ �ǵ��� ����Լ� �����ε� ����ϱ�

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

//��ü+4�� �ƴ� 4+��ü�϶� ó�� ���
//������ ��� �� ���� ��� �� ���

//#include<iostream>
//using namespace std;
//
//class Tmp {
//private:
//	int _a;
//
//	friend Tmp operator+(int num, Tmp& right) {
//		
//		return right + num;   //��ü + int            ������ ��� �κп� ��� �Լ� ȣ��
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


//!= , == �������� �����ε�
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


//+= ������ �����ε�
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
//	(t += 3) += 5;     //��ȣ �ʼ���    
//	                   //��ȣ ���ϸ� ���� �߻�  3+= 5 
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
//		                        /*���׿�����*/
//		increment();            //++a ���� �� ����� lvalue�̴�.
//		return *this;           //lvalue ����
//	}
//	test operator++(int a) {    //postfix increment
//		test temp{ *this };     //a++ ���� �� ����� rvalue �̴�. ���� ������ ���� ���ϰ� �׳� ����
//		++temp;                 //���� ���� �������ְ� ���� Ű�� ������ �������� ��ü�� ����
//		temp.display();         //rvalue ����
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