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
		:m_nMax(100),m_nA(0) //�ʱ�ȭ ���
	{
		cout << "CTest�� ������\n" << endl;
	}
	CTest(int a)
		:m_nA(a) // �ʱ�ȭ ���
	{
		cout << "CTest(int)�� ������\n" << endl;
		//m_nA = a;
	}
	CTest(int a, int b)
		:m_nA(a) // �ʱ�ȭ ���
	{
		cout << "CTest�� ������ int, int\n" << endl;
		m_nA = a + b;
	}
	CTest(double a) = delete;
	//	:m_nA(a)
	//{
	//	cout << "CTest�� ������ double\n" << endl;
	//	m_nA = -1;
	//}
	~CTest()
	{
		cout << "CTest�� �Ҹ���\n" << endl;
	}
};

int main()
{
	//�������� �ʱ�ȭ ���
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
	//��ü�� ��������
	{
		cout << "main�� ����\n";

		CTest* pData = new CTest;
		cout << "Test" << endl;
		delete pData;

		cout << "main�� ����\n";
	}
	return 0;
	//������/�Ҹ���
	{
		cout << "main�� ����\n";
		CTest a(100);
		cout << "main�� ����\n";
	}

	return 0;

}

#endif