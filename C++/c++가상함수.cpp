#include<iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CAnimal //virtual class 
{
public:
	//授呪亜雌敗呪(Pure virtual function)
	// : 昔斗凪戚什 竺域研 敗 -> 切縦級戚 姥薄背醤敗
	virtual void Cry() = 0;

	//亜雌敗呪
/*	virtual void Cry()
	{
		cout << "襖戚襖戚" << endl;
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
		cout << "雇雇増左鎧操詞形操雇雇" << endl;
	}
};	

class CCat : public CAnimal
{
public:
	void Cry()
	{
		cout << "肯闘段坪覗虞凪左辛ししししししししししししし" << endl;
	}
};

int main()
{
	//virtual class(pure virtual function)
	{	//virtual class澗 梓端研 持失拝 呪 蒸陥.
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
	//仙舛税 + virtual
	{
		CAnimal* p1 = new CCat;
		p1->Cry();
		delete p1;
	
		CAnimal* p2 = new CDog;
		p2->Cry();
		delete p2;
	}
	//return 0;

	//仙舛税 
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