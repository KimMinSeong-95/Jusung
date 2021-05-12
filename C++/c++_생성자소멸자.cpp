#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;
class CTest
{
public:
	int m_nA;
	const int m_nMax=50;

	CTest()
		:m_nMax(100),m_nA(0) //초기화 목록
	{
		cout << "CTest의 생성자\n" << endl;
	}
	CTest(int a)
		:m_nA(a) // 초기화 목록
	{
		cout << "CTest(int)의 생성자\n" << endl;
		//m_nA = a;
	}
	CTest(int a, int b)
		:m_nA(a) // 초기화 목록
	{
		cout << "CTest의 생성자 int, int\n" << endl;
		m_nA = a + b;
	}
	CTest(double a) = delete;
	//	:m_nA(a)
	//{
	//	cout << "CTest의 생성자 double\n" << endl;
	//	m_nA = -1;
	//}
	~CTest()
	{
		cout << "CTest의 소멸자\n" << endl;
	}
};

int main()
{
	//생성자의 초기화 목록
	{
		CTest a(100);
		cout << a.m_nA << endl;

		CTest b(50);
		cout << b.m_nA << endl;

		CTest c(22, 99);
		cout << c.m_nA << endl;

		/*CTest d(3.14);
		cout << d.m_nA << endl;*/
	}
	return 0;
	//객체의 동적생성
	{
		cout << "main의 시작\n";

		CTest* pData = new CTest;
		cout << "Test" << endl;
		delete pData;

		cout << "main의 종료\n";
	}
	return 0;
	//생성자/소멸자
	{
		cout << "main의 시작\n";
		CTest a(100);
		cout << "main의 종료\n";
	}

	return 0;

}

#endif