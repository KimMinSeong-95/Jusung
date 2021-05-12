#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class USERDATA2
{
	public://기본값은 Private
	int nAge;
	char szName[32];

	void PrintData();
};
void USERDATA2::PrintData()
{
	printf("클래스 : %d, %s\n", nAge, szName);
}

struct USERDATA
{
	int nAge;
	char szName[32];
	 
	void (*Print)(USERDATA*); // 함수포인터 추가
};
typedef struct USERDATA USERDATA;

void PrintData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser->nAge, pUser->szName);
}
int main()
{
	//구조체
	{
		//사용자의 코드
		USERDATA user = { 20, "민수" };
		//printf("%d, %s\n", user.nAge, user.szName);//1단계
		//PrintData(&user);//2단계
		user.nAge = 30;
		user.Print = PrintData;
		user.Print(&user);//3단계
	}
	//객체
	{
		USERDATA2 his = { 33, "김기동" };
		his.PrintData();	
	}
	//Gether/Setter 함수
	{
		class CMyData
		{
		public:
			int m_nID;
			void PrintMoney() const
			{
				cout << "내 돈은 " << m_nMoney << endl;
			}
		private :
			int m_nMoney;
		public : 
			int GetMoney(void) const
			{
				//m_nMoney++; //error
				return m_nMoney;
			}
			void SetMoney(int nParam) 
			{ 
				if(m_nMoney > 0) //체크
					m_nMoney = nParam; 
			}
		};

		CMyData a;
		a.SetMoney(100);
		a.PrintMoney();
		cout << a.GetMoney() << "원 입니다." << endl;
	}
	return 0;
}

#endif