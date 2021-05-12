#include<iostream>
using namespace std;
#include "CMyString.h"

#pragma warning(disable:4996)

#define ON_MAIN
#ifdef ON_MAIN

CMyString::CMyString()//����Ʈ ������
{
	m_pszData = NULL;
	m_nLength = 0;

	/*m_nCount++;
	cout << "�� ���� �� " << m_nCount << endl;*/
}

CMyString::CMyString(CMyString& temp)//���� ������
{
	//m_pszData = temp.m_pszData;//��������

	m_nLength = temp.m_nLength;
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, temp.m_pszData);

	m_nCount++;
	cout << "�� ���� �� " << m_nCount << endl;
}
CMyString::CMyString(const char* pszParam)
{
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);

	m_nCount++;
	cout << "�� ���� �� " << m_nCount << endl;
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

// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
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