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
		{ "�ݶ�", 1000 },
		{"ȯŸ",1500},
		{"��ī��",700},
		{"���̴�",1100},
		{"Ŀ��", 2000}
	};



	int nMenu = -1; //�ʱⰪ
	//char szLabel[MAX][12] = { "�ݶ�","ȯŸ","��ī��","���̴�","Ŀ��" };
	//const char* szLabel[MAX] = { "�ݶ�","ȯŸ","��ī��","���̴�","Ŀ��" };
	//const int nPrice[MAX] = { 1000, 1500, 700, 1100, 2000 }; //����ǥ
	

	int nNone; //�Էµ� �ݾ�
	int nClange; // �Ž�����



	//printf("szLabel�� ������ : %d\n\n", sizeof(szLabel));
	//while (nMenu != 0)
	//{
		// 1. �޴� ����
	for(;;)
	{
		printf("== ����� ���Ǳ� ==\n");
		for (int i = 0; i < MAX; i++)
			//printf("%d. %s\t\t%d��\n", i, szLabel[i], nPrice[i]);
			printf("%d. %s\t\t%d��\n", i+1, Mymenu.strLabel[i], Mymenu.nPrice[i]);
		//printf("1. �ݶ�\n");
		//printf("2. ȯŸ\n");
		//printf("3. ��ī��\n");
		//printf("4. ���̴�\n");
		//printf("5. �ֽ�\n");
		printf("0. ����\n");
		printf("===================\n");
		printf("���ϴ� �����ư�� �����ϼ��� : ");

		scanf_s("%d", &nMenu);
		if (nMenu == 0)
		{
			printf("����\n");
		//	break;
		}
		// 2. �ݾ� ó��
		printf("====================\n");
		printf("������ �ݾ� : ");
		scanf_s("%d", &nNone);
		printf("\n");
		if (nNone >= nPrice[nMenu - 1])
			printf("�ܵ� : %d\n\n", nClange = nNone - nPrice[nMenu - 1]);
		else
		{
			printf("�ݾ��� %d�� �����մϴ�.\n", nPrice[nMenu - 1] - nNone);
			printf("�ݾ��� %d�� ��ȯ.\n", nNone);
		//	continue;

		}

		// 3. ����� ���
		/*if (nMenu == 1)
			printf("�ݶ� ����\n\n");
		else if (nMenu == 2)
			printf("ȯŸ ����\n\n");
		else if (nMenu == 3)
			printf("��ī�� ����\n\n");
		else if (nMenu == 4)
			printf("���̴� ����\n\n");
		else if (nMenu == 5)
			printf("�ֽ� ����\n\n");
		if (nMenu >= 1 && nMenu <= MAX)
			printf("%s �������� \n\n", szLabel[nMenu - 1]);
		else
			printf("�߸� �����ϼ̾��\n\n");


		Sleep(2000);
		system("cls");
		Sleep(100);
		//}*/
	
	return 0;
}