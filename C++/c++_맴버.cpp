#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CTest
{
private:
	//�ν��Ͻ� �ɹ��Լ�
	int m_nData;

public:
	CTest(int a)
		:m_nData(a)
	{
		m_nCount++;
	}
	int GetData()
	{
		return m_nData;
	}
	void SetData(int a)
	{
		//üũ
		this->m_nData = a;
		this->ResetCount();
	}
	void ResetCount()
	{
		m_nCount = 0;
	}
	//���� �ɹ��Լ�(=Ŭ���� �ɹ� �Լ�)
	static int GetCount()
	{
		//m_nData++; //error
		return m_nCount;
	}
	//���� �ɹ�����(=Ŭ���� �ɹ�����)
	static int m_nCount; //����Ƚ�� ������
};

int CTest::m_nCount = 0;

//void CTest::PrintData()
//{
//	int a;
//	a = 10;
//	this->m_nData = 10;
//
//	//m_nData�� ���� ����Ѵ�.
//	cout << m_nData << endl;
//
//	//�ż��带 ȣ���� �ν��Ͻ��� m_nData �ɹ� ���� ����Ѵ�
//	cout << this->m_nData << endl;
//}

int main()
{
	cout << CTest::GetCount() << endl;

	CTest a(100);
	//a.ResetCount();
	
	CTest::m_nCount = 100;

	cout << a.GetData() << endl;
	cout << a.GetCount() << endl;
	
	CTest b(50);
	//b.ResetCount();

	cout << b.GetData() << endl;
	cout << b.GetCount() << endl;

	CTest c(33);
	//b.ResetCount();

	cout << c.GetData() << endl;
	cout << c.GetCount() << endl;

	return 0;
}
#endif