#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include "CMyString.h"
#include"CMyStringEx.h"
int main()
{

	//CMyStringEx�� ���
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
	char name[20] = "��μ�";
	string aaa = "ȫ�浿";

	aaa = aaa + "����";
	cout << aaa <<< endl;
	*/
	//CMyString strName;
	//strName.SetString("��μ�");
	//cout << strName.GetString() << endl;

	////1.�������� ==> �޸� Leak
	//strName.SetString("�ٺ��ٺ�");
	//cout << strName.GetString() << endl;

	////2.�������� ==> ��������� �߰�
	////CMyString newName = strName;
	//CMyString newName(strName);
	//cout << newName.GetString() << endl;

	////3. ��ȯ ������
	//CMyString newName2("�ռ���");
	//cout << newName2.GetString() << endl;

	//4. ���Կ�����
	
	//cout << str222.GetString() << endl;



	return 0;
}
#endif