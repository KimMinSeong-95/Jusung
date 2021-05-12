#include <stdio.h>

#define DATA_FILE_NAME "c:\\temp\\addr.dat"
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	  // 이름
	int nAge;			  // 나이
	int nGender;		  // 성별

	struct _USERDATA* pNext;
} USERDATA;

//배열로 처리
#define	MAX_BOOKCOUNT	5
int	g_nCount = 0;
USERDATA g_AddrBook[MAX_BOOKCOUNT];
USERDATA* g_Head = NULL;

int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("전화번호부(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제 \t [0] 종료\n");
	printf("===================================================\n");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);
	getchar();//버퍼에 남은 엔터 제거용
	return nInput;
}
void Add()
{
	USERDATA* user = NULL;
	user = (USERDATA*)malloc(sizeof(USERDATA));

	printf("이름을 입력하세요:");
	scanf_s("%s", &user->strName, 32);

	printf("나이을 입력하세요:");
	scanf_s("%d", &user->nAge);

	printf("성별을 입력하세요<남성:0,여성:1:>");
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

	printf("사용자의 이름을 입력해주세요: ");
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
				pTmp->nGender == 0 ? "남성" : "여성",
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
			pTmp->nGender==0?"남성":"여성",
			pTmp->pNext);

			pTmp = pTmp->pNext;
	}
	getch();
}
void Delete()
{
	char strName[32];
	int temp = 0;

	printf("삭제할 이름을 입력하세요:");
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
			printf("삭제되었습니다.");
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
	//1. 스트림(파일) 개방(wb모드)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "rb");
	USERDATA* pTmp = g_Head;

	fread(&g_nCount, sizeof(int), 1, stream);//갯수읽기
	//2. 스트림(파일)에서 읽기
	for(int i=0; i<g_nCount;i++)
	{
		pTmp = (USERDATA*)malloc(sizeof(USERDATA)* g_nCount);
		fread(pTmp, sizeof(USERDATA), 1, stream);//버퍼시작주소, 사이즈, 개수, 스트림
		pTmp = pTmp->pNext;
	}
	//3. 스트림(파일) 폭파

	fclose(stream);

	return 0;
}
int SaveData(char* szFileName)
{
	//-----------------------------------
	//g_AddrBook --> szFileName
	//-----------------------------------
	//1. 스트림(파일) 개방(wb모드)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "wb");
	USERDATA* pTmp = g_Head;

	fwrite(&g_nCount, sizeof(int), 1, stream);//갯수읽기
	//2. 스트림(파일)에서 쓰기
	while(pTmp != NULL)
		//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fwrite(pTmp, sizeof(USERDATA), 1, stream);//버퍼시작주소, 사이즈, 개수, 스트림
		pTmp = pTmp->pNext;
	}
	//3. 스트림(파일) 폭파
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

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add : 이름, 나이, 성별을 입력받아 친구를 추가하는 함수
			Add();
			break;

		case 2:		  // Search : 이름을 입력받아 검색하고, 검색된 결과를 보여주는 함수
			Search();
			break;

		case 3:		 // Print all : 전화부에 들어있는 모든 데이터를 화면에 출력하는 함수
			PrintAll();
			break;

		case 4:
			Delete();
			break;
		}
	}
	SaveData(DATA_FILE_NAME); // 파일에 저장하기
	ReleaseList();
}