#include <stdio.h>

#define DATA_FILE_NAME "c:\\temp\\addr.dat"
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	  // 이름
	int nAge;			  // 나이
	int nGender;		  // 성별
} USERDATA;

//배열로 처리
#define		MAX_BOOKCOUNT	5
int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];

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
	if (g_nCount > MAX_BOOKCOUNT)
	{
		printf("저장 공간 부족");
		return;
	}

	USERDATA user;

	printf("이름을 입력하세요:");
	gets(&user.strName);

	printf("나이을 입력하세요:");
	scanf_s("%d", &user.nAge);

	printf("성별을 입력하세요<남성:0,여성:1:>");
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

	printf("사용자의 이름을 입력해주세요: ");
	gets(&strName);

	for (i = 0; i < g_nCount; i++)
	{
		temp = strcmp(strName, g_AddrBook[i].strName);//0, -1, 1
		if (temp == 0)//hit
		{
			printf("사용자의 정보를 확인하였습니다. \n 이름 : %s\t나이 : %d\t성별 : %s\n ",
				g_AddrBook[i].strName,
				g_AddrBook[i].nAge,
				g_AddrBook[i].nGender == 0 ? "남성" : "여성");
			break;
		}
	}
	if (temp != 0) 
		printf("검색하신 데이터는 없습니다");
	getch();

}
void PrintAll()
{
	if (g_nCount == 0)
	{
		printf("목록이 없습니다.\n");
		return;
	}

	for (int i = 0; i < g_nCount; i++)
	{
		//printf(" %s\t %d  %d\n",g_AddrBook[i].strName, g_AddrBook[i].nAge, g_AddrBook[i].nGender);
		printf(" %s\t %d  %s\n",
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "남성" : "여성");
	}
	getch();
}
//void Delete()
//{
//	USERDATA temp[MAX_BOOKCOUNT] = { NULL, NULL, NULL };
//	char strName[10];
//	int i, j = 0 , t;
//
//	printf("삭제할 사용자의 이름을 입력해주세요: ");
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
	
	printf("삭제할 사용자의 이름을 입력해주세요: ");
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
		printf("목록이 없습니다.\n");
		return;
	}

	printf("삭제할 이름을 입력하세요:");
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
		printf("사용자 이름이 없습니다\n");
	g_nCount--;
	printf("삭제되었습니다.\n");
	for (int i = 0; i < g_nCount; i++)
	{
		printf("이름: %s\t 나이:%d  성별:%s\n",
			g_AddrBook[i].strName,
			g_AddrBook[i].nAge,
			g_AddrBook[i].nGender == 0 ? "남성" : "여성");
	}
	getch();

}
int LoadData(char* szFileName)
{
	//-----------------------------------
	//g_AddrBook --> szFileName
	//-----------------------------------
	//1. 스트림(파일) 개방(wb모드)
	FILE* stream = NULL;
	fopen_s(&stream, szFileName, "rb");

	//2. 스트림(파일)에서 읽기
    fread(&g_nCount, sizeof(int), 1, stream);//갯수읽기
	for (int i = 0; i < g_nCount; i++)
	//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fread(g_AddrBook + i, sizeof(USERDATA), 1, stream);//버퍼시작주소, 사이즈, 개수, 스트림
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

	//2. 스트림(파일)에서 쓰기
	fwrite(&g_nCount, sizeof(int), 1, stream);//갯수쓰기
	for (int i=0; i< g_nCount; i++)
	//for (int i = 0; i < MAX_BOOKCOUNT; i++)
	{
		fwrite(g_AddrBook + i, sizeof(USERDATA), 1, stream);//버퍼시작주소, 사이즈, 개수, 스트림
	}
	//3. 스트림(파일) 폭파
	fclose(stream);

	return 0;
}

void main()
{
	int nMenu = 0;
	//LoadData(DATA_FILE_NAME);

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
}