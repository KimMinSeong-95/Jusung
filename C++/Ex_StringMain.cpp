#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include "CMyString.h"
#include"CMyStringEx.h"
int main()
{

	//CMyStringEx의 사용
	{
		CMyStringEx aaa("I love you");
		cout << aaa.GetString() << endl;

		aaa.Append(".Doyou");
		cout << aaa.GetString() << endl;

		
		int n;
		n = aaa.Find("love");
		cout << n<< endl;


	}

	return 0;

	/*
	char name[20] = "김민성";
	string aaa = "홍길동";

	aaa = aaa + "만세";
	cout << aaa <<< endl;
	*/
	//CMyString strName;
	//strName.SetString("김민성");
	//cout << strName.GetString() << endl;

	////1.수정사항 ==> 메모리 Leak
	//strName.SetString("바보바보");
	//cout << strName.GetString() << endl;

	////2.수정사항 ==> 복사생성자 추가
	////CMyString newName = strName;
	//CMyString newName(strName);
	//cout << newName.GetString() << endl;

	////3. 변환 생성자
	//CMyString newName2("손세정");
	//cout << newName2.GetString() << endl;

	//4. 대입연산자
	
	//cout << str222.GetString() << endl;



	return 0;
}
#endif