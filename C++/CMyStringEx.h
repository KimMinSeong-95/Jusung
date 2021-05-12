#pragma once
#include "CMyString.h"
#include <iostream>
class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char* pszParam);
	~CMyStringEx();

	int GetLength() const;
	int Append(const char* pszParam);
	int Find(const char* pszParam);

};