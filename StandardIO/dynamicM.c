#include<stdio.h>
//#include<stdlib.h>

int main()
{
	//�����޸� + �ڱ����� ����ü : ��ũ�帮��Ʈ
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
			//1. ���ο� ��� 1���� ���� ���� �޸� �Ҵ�
			pNewUser = (WORKER*)malloc(sizeof(WORKER));//���� �޸� �Ҵ�

			//2. ��� 1�� ���� �Է� 
			printf("����� �̸� �Է� : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count + 1;//1_based
			pNewUser->pNext = NULL;

			//3. ��ũ ����
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count++;

			printf("��� �Է�(0:NO / 1:YES) : ");
			scanf_s("%d%*c", &answer);
		}
		system("cls");
		printf("========= ��ü ��� =========\n");
		//��� ���
		WORKER* pTmp = pHead;
		while (pTmp != NULL)
		{
			printf("(%p) %d, %s(%p)\n", pTmp, pTmp->no, pTmp->name, pTmp->pNext);
			pTmp= pTmp->pNext;
		}

		return 0;
	}

	//���� �޸� �Ҵ� ����
	//{
	//	printf("=========== ���� ���� ========");
	//	
	//	int nKinds = 0;//�������� �ޱ�. ����� ���� ����
	//	printf("������ ������ �� �� ���ΰ���?");
	//	scanf_s("%d%*c", &nKinds);


	//	int nMacLength = 0;//�����̸��� �ִ� ����
	//	printf("�����̸��� �ִ� ���̴� ���ΰ���?");
	//	scanf_s("%d%*c", &nMacLength);

	//	char** pDrink = NULL;
	//	pDrink = malloc(sizeof(char*) * nKinds);
	//	printf("pDrink�� ������ = %d, �޸� = %d\n", sizeof(pDrink), _msize(pDrink)); //4 , 40

	//	/////////////////////////////////////////
	//	//�Է¹ޱ�
	//	char temp[100];
	//	for (int i = 0; i < nKinds; i++)
	//	{
	//		printf("\t%d �����̸� : ", i + 1);
	//		scanf_s("%s", temp, 100);
	//		
	//		pDrink[i] = (char*)malloc(sizeof(char) * (nMacLength + 1));
	//		//strcpy(*(pDrink + i), temp);//���ڿ� �Լ�

	//		int len = strlen(temp);
	//		memcpy(*(pDrink + i), temp, len+1);//�޸�
	//		
	//	}
	//	//����ϱ�
	//	printf("\n�����̸� ��� : \n ");
	//	for (int i = 0; i < nKinds; i++)
	//	{
	//		printf("\t%d�� %s(%d)\n", i + 1, pDrink[i], _msize(pDrink[i]));
	//		free(pDrink[i]);
	//	}
	//	return 0;
	//}


	{
		printf("=========== ���� ���� ========");

		int nKinds = 0;//�������� �ޱ�. ����� ���� ����
		printf("������ ������ �� �� ���ΰ���?");
		scanf_s("%d%*c", &nKinds);


		int nMacLength = 0;//�����̸��� �ִ� ����
		printf("�����̸��� �ִ� ���̴� ���ΰ���?");
		scanf_s("%d%*c", &nMacLength);

		char** pDrink = NULL;
		pDrink = malloc(sizeof(char*) * nKinds);
		printf("pDrink�� ������ = %d, �޸� = %d\n", sizeof(pDrink), _msize(pDrink)); //4 , 40

		/////////////////////////////////////////
		//�Է¹ޱ�
		char temp[100];
		for (int i = 0; i < nKinds; i++)
		{
			printf("\t%d �����̸� : ", i + 1);
			scanf_s("%s", temp, 100);

			pDrink[i] = (char*)malloc(sizeof(char) * (nMacLength + 1));
			//strcpy(*(pDrink + i), temp);//���ڿ� �Լ�

			int len = strlen(temp);
			memcpy(*(pDrink + i), temp, len + 1);//�޸�

			printf("\n\t��� ����� : %d�� %s(%d)\n\n", i + 1, pDrink[i], len+1);
			free(pDrink[i]);
		}
		//����ϱ�
		//printf("\n�����̸� ��� : \n ");
		//for (int i = 0; i < nKinds; i++)
		//{
		//	printf("\t%d�� %s(%d)\n", i + 1, pDrink[i], _msize(pDrink[i]));
		//	free(pDrink[i]);
		//}
		return 0;
	}
	
	{
		char pDrink[3][12] = { 0 };
		//�Է¹ޱ�
		char temp[100];
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d �����̸� : ", i + 1);
			scanf_s("%s", temp, 100);
		}
		//����ϱ�
		printf("\n�����̸� ��� : \n ");
		for (int i = 0; i < 3; i++)
		{
			printf("\t%d�� %s\n", i + 1, pDrink[i]);
		}
		return 0;
	}

	{
		int a;
		int* p = &a;
		printf("a ������ : %d\n", sizeof(a));//4
		printf("p ������ : %d\n", sizeof(p));//8

		//�����޸�
		char* p1 = (char*)malloc(sizeof(char)*2);//2Byte ->�������� ����
		p1[0] = 'a';
		p1[1] = 'b';
		printf("%c, %c\n", p1[0], p1[1]);
		printf("������ : %d\n", sizeof(p1));//4(8)
		printf("�ǻ����� : %d\n", _msize(p1)); //2

		free(p1);

		int* p2 = (int*)malloc(sizeof(int) * 2);//8Byte ->�������� ����
		p2[0] = 10;
		p2[1] = 20;
		printf("%d, %d\n", p2[0], p2[1]);
		printf("������ : %d\n", sizeof(p2));//4
		printf("�ǻ����� : %d\n", _msize(p2)); //2

		free(p2);
	}
	return 0;
}
