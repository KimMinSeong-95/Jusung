#include <stdio.h>

#define DATA_FILE_NAME "c:\\temp\\addr.dat"
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	  // �̸�
	int nAge;			  // ����
	int nGender;		  // ����
} USERDATA;

//�迭�� ó��
#define		MAX_BOOKCOUNT	5
int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];

int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("��ȭ��ȣ��(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ���� \t [0] ����\n");
	printf("===================================================\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d", &nInput);
	getchar();//���ۿ� ���� ���� ���ſ�
	return nInput;
}
void Add()
{
	if (g_nCount > MAX_BOOKCOUNT)
	{
		printf("���� ���� ����");
		return;
	}

	USERDATA user;

	printf("�̸��� �Է��ϼ���:");
	gets(&user.strName);

	printf("������ �Է��ϼ���:");
	scanf_s("%d", &user.nAge);

	printf("������ �Է��ϼ���<����:0,����:1:>");
	scanf_s("%d", &user.nGender);

	//strcpy(g_AddrBook[g_nCount].strName, user.strName);
	//g_AddrBook[g_nCount].nAge = user.nAge;
	//g_AddrBook[g_nCount].nGender = user.nGender;
	g_AddrBook[g_nCount] = user;
	g_nCount++;
};
void Search()
{
	char strName[10];
	int i;
	int temp;

	printf("������� �̸��� �Է����ּ���: ");
	gets(&strName);

	for (i = 0; i < g_nCount; i++)
	{
		temp = strcmp(strName, g_AddrBook[i].strName);//0, -1, 1
		if (temp == 0)//hit
		{
			printf("������� ������ Ȯ���Ͽ����ϴ�. \n �̸� : %s\t���� : %d\t���� : %s\n ",
				g_AddrBook[i].strName,
				g_AddrBook[i].nAge,
				g_AddrBook[i].nGender == 0 ? "����" : "����");
			break;
		}
	}
	if (temp != 0) 
		printf("�˻��Ͻ� �����ʹ� �����ϴ�");
	getch();

}
void PrintAll()
{
	if (g_nCount == 0)
	{
		printf("����� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < g_nCount; i++)
	{
		//printf(" %s\t %d  %d\n",g_AddrBook[i].strName, g_AddrBook[i].nAge, g_AddrBook[i].nGender);
		printf(" %s\t %d  %s\n",
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "����" : "����");
	}
	getch();
}
//void Delete()
//{
//	USERDATA temp[MAX_BOOKCOUNT] = { NULL, NULL, NULL };
//	char strName[10];
//	int i, j = 0 , t;
//
//	printf("������ ������� �̸��� �Է����ּ���: ");
//	gets(&strName);
//
//	for (i = 0; i < g_nCount; i++)
//	{
//		t = strcmp(strName, g_AddrBook[i].strName);
//		if (t == 1)
//		{
//			strcpy(temp[j].strName, g_AddrBook[i].strName);
//			temp[j].nAge = g_AddrBook[i].nAge;
//			temp[j].nGender = g_AddrBook[i].nGender;
//			j++;
//		}
//	}
//
//	for (i = 0; i < MAX_BOOKCOUNT; i++)
//	{
//		*(g_AddrBook+i)->strName = NULL;
//		g_AddrBook[i].nAge = NULL;
//		g_AddrBook[i].nGender = NULL;
//	}
//
//	for (i = 0; i < j; i++)
//	{
//		strcpy(g_AddrBook[i].strName, temp[i].strName);
//		g_AddrBook[i].nAge = temp[i].nAge;
//		g_AddrBook[i].nGender = temp[j].nGender;
//	}
//	g_nCount--;
//
//	getch();
//
//}
/*void Delete()
{
	char strName[10];
	int i, t;
	
	printf("������ ������� �̸��� �Է����ּ���: ");
	gets(&strName);

	for (i = 0; i < g_nCount; i++)
	{
		t = strcmp(strName, g_AddrBook[i].strName);
		if (t == 0)
		{
			*(g_AddrBook + i)->strName = NULL;
			g_AddrBook[i].nAge = NULL;
			g_AddrBook[i].nGender = NULL;
			break;
		}
	}
	g_nCount--;
}*/
void Delete()
{
	char name[15];
	int temp = 0;
	int index = 0;

	if (g_nCount == 0)
	{
		printf("����� �����ϴ�.\n");
		return;
	}

	printf("������ �̸��� �Է��ϼ���:");
	gets(&name);

	for (int i = 0; i < g_nCount; i++)
	{
		temp = strcmp(g_AddrBook[i].strName, name);
		if (temp == 0)
		{
			index = i;
			break;
		}
	}

	for (int j = index; j < MAX_BOOKCOUNT; j++)
		g_AddrBook[j] = g_AddrBook[j + 1];
	if (temp == -1)
		printf("����� �̸��� �����ϴ�\n");
	g_nCount--;
	printf("�����Ǿ����ϴ�.\n");
	for (int i = 0; i < g_nCount; i++)
	{
		printf("�̸�: %s\t ����:%d  ����:%s\n",
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "����" : "����");
	}
	getch();

}
int LoadData(char* szFileName)
{
	//-----------------------------------
	//g_AddrBook --> szFileName
	//-----------------------------------
	//1. ��Ʈ��(����) ����(wb���)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "rb");

	//2. ��Ʈ��(����)���� �б�
    fread(&g_nCount, sizeof(int), 1, stream);//�����б�
	for (int i = 0; i < g_nCount; i++)
	//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fread(g_AddrBook + i, sizeof(USERDATA), 1, stream);//���۽����ּ�, ������, ����, ��Ʈ��
	}
	//3. ��Ʈ��(����) ����
	fclose(stream);

	return 0;
}
int SaveData(char* szFileName)
{
	//-----------------------------------
	//g_AddrBook --> szFileName
	//-----------------------------------
	//1. ��Ʈ��(����) ����(wb���)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "wb");

	//2. ��Ʈ��(����)���� ����
	fwrite(&g_nCount, sizeof(int), 1, stream);//��������
	for (int i=0; i< g_nCount; i++)
	//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fwrite(g_AddrBook + i, sizeof(USERDATA), 1, stream);//���۽����ּ�, ������, ����, ��Ʈ��
	}
	//3. ��Ʈ��(����) ����
	fclose(stream);

	return 0;
}

void main()
{
	int nMenu = 0;
	//LoadData(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add : �̸�, ����, ������ �Է¹޾� ģ���� �߰��ϴ� �Լ�
			Add();
			break;

		case 2:		  // Search : �̸��� �Է¹޾� �˻��ϰ�, �˻��� ����� �����ִ� �Լ�
			Search();
			break;

		case 3:		 // Print all : ��ȭ�ο� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
			PrintAll();
			break;

		case 4:
			Delete();
			break;
		}
	}
	SaveData(DATA_FILE_NAME); // ���Ͽ� �����ϱ�
}