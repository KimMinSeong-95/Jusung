#include<stdio.h>
#include<Windows.h>

#define MAX 5

struct Product {
	const char* strLabel;
	const int nPrice;
};

struct Product2 {
	const char strLabel[12];
	const int nPrice;
}

#define MAX 7
int main()
{
	DRINK MyMenu[MAX] =
	{
		{ "콜라", 1000 },
		{"환타",1500},
		{"포카리",700},
		{"사이다",1100},
		{"커피", 2000}
	};



	int nMenu = -1; //초기값
	//char szLabel[MAX][12] = { "콜라","환타","포카리","사이다","커피" };
	//const char* szLabel[MAX] = { "콜라","환타","포카리","사이다","커피" };
	//const int nPrice[MAX] = { 1000, 1500, 700, 1100, 2000 }; //가격표
	

	int nNone; //입력된 금액
	int nClange; // 거스름돈



	//printf("szLabel의 사이즈 : %d\n\n", sizeof(szLabel));
	//while (nMenu != 0)
	//{
		// 1. 메뉴 선택
	for(;;)
	{
		printf("== 음료수 자판기 ==\n");
		for (int i = 0; i < MAX; i++)
			//printf("%d. %s\t\t%d원\n", i, szLabel[i], nPrice[i]);
			printf("%d. %s\t\t%d원\n", i+1, Mymenu.strLabel[i], Mymenu.nPrice[i]);
		//printf("1. 콜라\n");
		//printf("2. 환타\n");
		//printf("3. 포카리\n");
		//printf("4. 사이다\n");
		//printf("5. 주스\n");
		printf("0. 종료\n");
		printf("===================\n");
		printf("원하는 음료버튼을 선택하세요 : ");

		scanf_s("%d", &nMenu);
		if (nMenu == 0)
		{
			printf("정지\n");
		//	break;
		}
		// 2. 금액 처리
		printf("====================\n");
		printf("넣으신 금액 : ");
		scanf_s("%d", &nNone);
		printf("\n");
		if (nNone >= nPrice[nMenu - 1])
			printf("잔돈 : %d\n\n", nClange = nNone - nPrice[nMenu - 1]);
		else
		{
			printf("금액이 %d원 부족합니다.\n", nPrice[nMenu - 1] - nNone);
			printf("금액이 %d원 반환.\n", nNone);
		//	continue;

		}

		// 3. 음료수 출력
		/*if (nMenu == 1)
			printf("콜라 여기\n\n");
		else if (nMenu == 2)
			printf("환타 여기\n\n");
		else if (nMenu == 3)
			printf("포카리 여기\n\n");
		else if (nMenu == 4)
			printf("사이다 여기\n\n");
		else if (nMenu == 5)
			printf("주스 여기\n\n");
		if (nMenu >= 1 && nMenu <= MAX)
			printf("%s 받으세요 \n\n", szLabel[nMenu - 1]);
		else
			printf("잘못 선택하셨어요\n\n");


		Sleep(2000);
		system("cls");
		Sleep(100);
		//}*/
	
	return 0;
}