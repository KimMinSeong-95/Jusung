#include<iostream>
#include "CMyString.h"
#include "CMyStringEx.h"
#pragma warning(disable:4996)

using namespace std;


//#define ON_MAIN
#ifdef ON_MAIN

CMyStringEx::CMyStringEx()
{
	m_pszData = NULL;
	m_nLength = 0;
}
CMyStringEx::CMyStringEx(const char* pszParam)
{
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);
}
CMyStringEx::~CMyStringEx()
{
	Release();
}

int CMyStringEx::GetLength() const
{
	return m_nLength;
}
int CMyStringEx::Append(const char* pszParam)
{
	int temp = strlen(m_pszData) + strlen(pszParam) + 2;
	m_nLength = temp;

	char* ApData = new char[GetLength()];
	strcpy(ApData, m_pszData);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, ApData);

	strcat(m_pszData, pszParam);
	return 0;
}
int CMyStringEx::Find(const char* pszParam)
{
	
	char* p = strstr(m_pszData, pszParam);
	int temp = strlen(pszParam);
	if (p != NULL)
	{
		cout << "기준 문자열:" << m_pszData << endl;
		cout << "찾을 문자열:" << pszParam << endl;
		cout << "찾을 위치:" << *p << endl;
		
	}
	else
		cout << "못찾음" << endl;
	int start = p - GetString();
	int end = start + temp;
	int last = strlen(m_pszData) + 1;

	//this->m_pszData[start] ~this->m_pszData[end]
	for(int i= 0; i<start; i++)
		cout << this->m_pszData[i];
	for(int i = end; i < last; i++)
		cout << this->m_pszData[i];

	cout << "\n";
	return start;
}
#endif