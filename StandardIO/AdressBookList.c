#include <stdio.h>

#define DATA_FILE_NAME "c:\\temp\\addr.dat"
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	  // �̸�
	int nAge;			  // ����
	int nGender;		  // ����

	struct _USERDATA* pNext;
} USERDATA;

//�迭�� ó��
#define	MAX_BOOKCOUNT	5
int	g_nCount = 0;
USERDATA g_AddrBook[MAX_BOOKCOUNT];
USERDATA* g_Head = NULL;

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
	USERDATA* user = NULL;
	user = (USERDATA*)malloc(sizeof(USERDATA));

	printf("�̸��� �Է��ϼ���:");
	scanf_s("%s", &user->strName, 32);

	printf("������ �Է��ϼ���:");
	scanf_s("%d", &user->nAge);

	printf("������ �Է��ϼ���<����:0,����:1:>");
	scanf_s("%d", &user->nGender);

	user->pNext = NULL;
	user->pNext = g_Head;
	g_Head = user;
	g_nCount++;
	// [g_nCount] = user;
	return;
};
void Search()
{
	char strName[32];
	int temp = 0;

	printf("������� �̸��� �Է����ּ���: ");
	gets(&strName);

	USERDATA* pTmp = g_Head;
	while (pTmp != NULL)
	{
		temp = strcmp(strName, pTmp->strName);
		if (temp == 0)
		{
			printf("(%s, %d, %s(%p))\n",
				pTmp->strName,
				pTmp->nAge,
				pTmp->nGender == 0 ? "����" : "����",
				pTmp->pNext);
		}
		pTmp = pTmp->pNext;
	}
	getch();
}
void PrintAll()
{
	USERDATA* pTmp = g_Head;
	while (pTmp != NULL)
	{
		printf("%s, %d, %s(%p))\n", 
			pTmp->strName, 
			pTmp->nAge, 
			pTmp->nGender==0?"����":"����",
			pTmp->pNext);

			pTmp = pTmp->pNext;
	}
	getch();
}
void Delete()
{
	char strName[32];
	int temp = 0;

	printf("������ �̸��� �Է��ϼ���:");
	gets(&strName);

	USERDATA* pTmp = g_Head;
	USERDATA* Delete = NULL;

	while (pTmp != NULL)
	{
		temp = strcmp(strName, pTmp->strName);
		if (temp == 0)
		{
			Delete->pNext = pTmp->pNext;
			free(pTmp);
			printf("�����Ǿ����ϴ�.");
			getch();
			g_nCount--;
			return;
		}
		Delete = pTmp;
		pTmp = pTmp->pNext;
	}
}
int LoadData(char* szFileName)
{
	//-----------------------------------
	//g_AddrBook --> szFileName
	//-----------------------------------
	//1. ��Ʈ��(����) ����(wb���)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "rb");
	USERDATA* pTmp = g_Head;

	fread(&g_nCount, sizeof(int), 1, stream);//�����б�
	//2. ��Ʈ��(����)���� �б�
	for(int i=0; i<g_nCount;i++)
	{
		pTmp = (USERDATA*)malloc(sizeof(USERDATA)* g_nCount);
		fread(pTmp, sizeof(USERDATA), 1, stream);//���۽����ּ�, ������, ����, ��Ʈ��
		pTmp = pTmp->pNext;
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
	USERDATA* pTmp = g_Head;

	fwrite(&g_nCount, sizeof(int), 1, stream);//�����б�
	//2. ��Ʈ��(����)���� ����
	while(pTmp != NULL)
		//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fwrite(pTmp, sizeof(USERDATA), 1, stream);//���۽����ּ�, ������, ����, ��Ʈ��
		pTmp = pTmp->pNext;
	}
	//3. ��Ʈ��(����) ����
	fclose(stream);

	return 0;
}

void ReleaseList()
{
	USERDATA* pTmp = g_Head;
	USERDATA* pDelete = NULL;

	while (pTmp != NULL) {
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

void main()
{
	int nMenu = 0;
	LoadData(DATA_FILE_NAME);

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
	ReleaseList();
}