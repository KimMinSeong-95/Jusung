#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CAnimal //virtual class 
{
public:
	//순수가상함수(Pure virtual function)
	// : 인터페이스 설계를 함 -> 자식들이 구현해야함
	virtual void Cry() = 0;

	//가상함수
/*	virtual void Cry()
	{
		cout << "꺼이꺼이" << endl;
	}
	*/
	void TestFunc()
	{
		cout << "***TestFunc***" << endl;
		Cry();
		cout << "**************" << endl;
	}
};

class CDog : public CAnimal
{
public:
	void Cry()
	{
		cout << "멍멍집보내줘살려줘멍멍" << endl;
	}
};	

class CCat : public CAnimal
{
public:
	void Cry()
	{
		cout << "민트초코프라페보옵ㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇ" << endl;
	}
};

int main()
{
	//virtual class(pure virtual function)
	{	//virtual class는 객체를 생성할 수 없다.
		//CAnimal zzm;//error
	}

	//Reference + virtual
	{
		CCat a;
		a.Cry();

		CAnimal& ref = a;
		ref.Cry();
	}
	return 0;
	//재정의 + virtual
	{
		CAnimal* p1 = new CCat;
		p1->Cry();
		delete p1;
	
		CAnimal* p2 = new CDog;
		p2->Cry();
		delete p2;
	}
	//return 0;

	//재정의 
	{
		CCat* a = new CCat;
		a->Cry();
		a->TestFunc();
		delete a;


		CDog* b = new CDog;
		b->Cry();
		b->TestFunc();
		delete b;
	}

	return 0;
}

#endif