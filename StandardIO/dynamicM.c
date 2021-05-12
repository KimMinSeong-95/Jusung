#include<stdio.h>
//#include<stdlib.h>

int main()
{
	//동적메모리 + 자기참조 구조체 : 링크드리스트
	{
		struct worker
		{
			int no;
			char name[20];

			struct student* pNext;
		};
		typedef struct worker WORKER;

		WORKER* pHead = NULL;
		WORKER* pNewUser = NULL;

		int count = 0;
		int answer = 1;
		while (answer == 1)
		{
			//1. 새로운 사원 1명을 위한 동적 메모리 할당
			pNewUser = (WORKER*)malloc(sizeof(WORKER));//동적 메모리 할당

			//2. 사원 1명 정보 입력 
			printf("사원의 이름 입력 : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count + 1;//1_based
			pNewUser->pNext = NULL;

			//3. 링크 조정
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count++;

			printf("계속 입력(0:NO / 1:YES) : ");
			scanf_s("%d%*c", &answer);
		}
		system("cls");
		printf("========= 전체 출력 =========\n");
		//결과 출력
		WORKER* pTmp = pHead;
		while (pTmp != NULL)
		{
			printf("(%p) %d, %s(%p)\n", pTmp, pTmp->no, pTmp->name, pTmp->pNext);
			pTmp= pTmp->pNext;
		}

		return 0;
	}

	//동적 메모리 할당 예제
	//{
	//	printf("=========== 음료 관리 ========");
	//	
	//	int nKinds = 0;//유저에게 받기. 음료수 종류 갯수
	//	printf("음료의 종류는 총 몇 개인가요?");
	//	scanf_s("%d%*c", &nKinds);


	//	int nMacLength = 0;//음료이름의 최대 길이
	//	printf("음료이름의 최대 길이는 얼마인가요?");
	//	scanf_s("%d%*c", &nMacLength);

	//	char** pDrink = NULL;
	//	pDrink = malloc(sizeof(char*) * nKinds);
	//	printf("pDrink의 사이즈 = %d, 메모리 = %d\n", sizeof(pDrink), _msize(pDrink)); //4 , 40

	//	/////////////////////////////////////////
	//	//입력받기
	//	char temp[100];
	//	for (int i = 0; i < nKinds; i++)
	//	{
	//		printf("\t%d 음료이름 : ", i + 1);
	//		scanf_s("%s", temp, 100);
	//		
	//		pDrink[i] = (char*)malloc(sizeof(char) * (nMacLength + 1));
	//		//strcpy(*(pDrink + i), temp);//문자열 함수

	//		int len = strlen(temp);
	//		memcpy(*(pDrink + i), temp, len+1);//메모리
	//		
	//	}
	//	//출력하기
	//	printf("\n음료이름 출력 : \n ");
	//	for (int i = 0; i < nKinds; i++)
	//	{
	//		printf("\t%d번 %s(%d)\n", i + 1, pDrink[i], _msize(pDrink[i]));
	//		free(pDrink[i]);
	//	}
	//	return 0;
	//}


	{
		printf("=========== 음료 관리 ========");

		int nKinds = 0;//유저에게 받기. 음료수 종류 갯수
		printf("음료의 종류는 총 몇 개인가요?");
		scanf_s("%d%*c", &nKinds);


		int nMacLength = 0;//음료이름의 최대 길이
		printf("음료이름의 최대 길이는 얼마인가요?");
		scanf_s("%d%*c", &nMacLength);

		char** pDrink = NULL;
		pDrink = malloc(sizeof(char*) * nKinds);
		printf("pDrink의 사이즈 = %d, 메모리 = %d\n", sizeof(pDrink), _msize(pDrink)); //4 , 40

		/////////////////////////////////////////
		//입력받기
		char temp[100];
		for (int i = 0; i < nKinds; i++)
		{
			printf("\t%d 음료이름 : ", i + 1);
			scanf_s("%s", temp, 100);

			pDrink[i] = (char*)malloc(sizeof(char) * (nMacLength + 1));
			//strcpy(*(pDrink + i), temp);//문자열 함수

			int len = strlen(temp);
			memcpy(*(pDrink + i), temp, len + 1);//메모리

			printf("\n\t출력 음료수 : %d번 %s(%d)\n\n", i + 1, pDrink[i], len+1);
			free(pDrink[i]);
		}
		//출력하기
		//printf("\n음료이름 출력 : \n ");
		//for (int i = 0; i < nKinds; i++)
		//{
		//	printf("\t%d번 %s(%d)\n", i + 1, pDrink[i], _msize(pDrink[i]));
		//	free(pDrink[i]);
		//}
		return 0;
	}
	
	{
		char pDrink[3][12] = { 0 };
		//입력받기
		char temp[100];
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d 음료이름 : ", i + 1);
			scanf_s("%s", temp, 100);
		}
		//출력하기
		printf("\n음료이름 출력 : \n ");
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d번 %s\n", i + 1, pDrink[i]);
		}
		return 0;
	}

	{
		int a;
		int* p = &a;
		printf("a 사이즈 : %d\n", sizeof(a));//4
		printf("p 사이즈 : %d\n", sizeof(p));//8

		//동적메모리
		char* p1 = (char*)malloc(sizeof(char)*2);//2Byte ->힙영역에 잡힘
		p1[0] = 'a';
		p1[1] = 'b';
		printf("%c, %c\n", p1[0], p1[1]);
		printf("사이즈 : %d\n", sizeof(p1));//4(8)
		printf("탭사이즈 : %d\n", _msize(p1)); //2

		free(p1);

		int* p2 = (int*)malloc(sizeof(int) * 2);//8Byte ->힙영역에 잡힘
		p2[0] = 10;
		p2[1] = 20;
		printf("%d, %d\n", p2[0], p2[1]);
		printf("사이즈 : %d\n", sizeof(p2));//4
		printf("탭사이즈 : %d\n", _msize(p2)); //2

		free(p2);
	}
	return 0;
}
