#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class USERDATA2
{
	public://�⺻���� Private
	int nAge;
	char szName[32];

	void PrintData();
};
void USERDATA2::PrintData()
{
	printf("Ŭ���� : %d, %s\n", nAge, szName);
}

struct USERDATA
{
	int nAge;
	char szName[32];
	 
	void (*Print)(USERDATA*); // �Լ������� �߰�
};
typedef struct USERDATA USERDATA;

void PrintData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser->nAge, pUser->szName);
}
int main()
{
	//����ü
	{
		//������� �ڵ�
		USERDATA user = { 20, "�μ�" };
		//printf("%d, %s\n", user.nAge, user.szName);//1�ܰ�
		//PrintData(&user);//2�ܰ�
		user.nAge = 30;
		user.Print = PrintData;
		user.Print(&user);//3�ܰ�
	}
	//��ü
	{
		USERDATA2 his = { 33, "��⵿" };
		his.PrintData();	
	}
	//Gether/Setter �Լ�
	{
		class CMyData
		{
		public:
			int m_nID;
			void PrintMoney() const
			{
				cout << "�� ���� " << m_nMoney << endl;
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
				if(m_nMoney > 0) //üũ
					m_nMoney = nParam; 
			}
		};

		CMyData a;
		a.SetMoney(100);
		a.PrintMoney();
		cout << a.GetMoney() << "�� �Դϴ�." << endl;
	}
	return 0;
}

#endif