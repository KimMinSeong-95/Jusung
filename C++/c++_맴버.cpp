#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CTest
{
private:
	//인스턴스 맴버함수
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
		//체크
		this->m_nData = a;
		this->ResetCount();
	}
	void ResetCount()
	{
		m_nCount = 0;
	}
	//정적 맴버함수(=클래스 맴버 함수)
	static int GetCount()
	{
		//m_nData++; //error
		return m_nCount;
	}
	//정적 맴버변수(=클래스 맴버변수)
	static int m_nCount; //누적횟수 관리용
};

int CTest::m_nCount = 0;

//void CTest::PrintData()
//{
//	int a;
//	a = 10;
//	this->m_nData = 10;
//
//	//m_nData의 값을 출력한다.
//	cout << m_nData << endl;
//
//	//매서드를 호출한 인스턴스의 m_nData 맴버 값을 출력한다
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