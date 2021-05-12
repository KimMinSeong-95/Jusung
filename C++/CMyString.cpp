#include<iostream>
using namespace std;
#include "CMyString.h"

#pragma warning(disable:4996)

#define ON_MAIN
#ifdef ON_MAIN

CMyString::CMyString()//디폴트 생성자
{
	m_pszData = NULL;
	m_nLength = 0;

	/*m_nCount++;
	cout << "상세 누적 수 " << m_nCount << endl;*/
}

CMyString::CMyString(CMyString& temp)//복사 생성자
{
	//m_pszData = temp.m_pszData;//얕은복사

	m_nLength = temp.m_nLength;
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, temp.m_pszData);

	m_nCount++;
	cout << "상세 누적 수 " << m_nCount << endl;
}
CMyString::CMyString(const char* pszParam)
{
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);

	m_nCount++;
	cout << "상세 누적 수 " << m_nCount << endl;
}


CMyString::~CMyString()
{
	Release();
}

int CMyString::SetString(const char* pszParam)
{
	Release();

	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);

	return m_nLength;
}

// 멤버 읽기만 수행하므로 메서드를 상수화한다.
const char* CMyString::GetString() const
{
	return m_pszData;
}

void CMyString::Release()
{
	delete[] m_pszData;
	m_pszData = NULL;
	m_nLength = 0;
}

//CMyString& CMyString::operator=(const CMyString& rhs)
//{
//	this->SetString(rhs.GetString());
//	return *this;
//}

//static void CMyString::ResetCount()
//{
//	m_nCount = 0;
//}
#endif