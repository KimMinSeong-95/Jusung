#include<stdio.h>
#pragma warning (disable:4996)

int main()
{
	int age;
	char name[20];

	printf("나이 입력 : ");
	scanf("%d", &age);

	//fflush(stdin);
	getchar();

	printf("이름 입력 : ");
	gets(name);


	printf("%d %s\n", age, name);

	
	//1. 키보드 -> 모니터
	/*	char ch = 0;
	while (ch != EOF) 
	{
		ch = getche();
		//putchar(ch);
	}*/

	//2. 키브도 -> 파일
	/*FILE* stream;
	char ch = 0;
	fopen_s(&stream, "c:\\temp\\data.txt", "wt");
	while (ch != EOF)//Ctrl+Z(-1)
	{
		//ch = getchar();
		ch =fgetc(stdin);

		putchar(ch);
		fputc(ch, stream);
	}
	fclose(stream);*/

	//3. 파일 -> 파일/모니터
	/*FILE* stream1;
	FILE* stream2;
	int input = 0;

	fopen_s(&stream1, "c:\\temp\\data.txt", "r");
	fopen_s(&stream2, "c:\\temp\\data2.txt", "w");

	while (input != EOF)
	{
		input = fgetc(stream1); // 1번 파일에서 읽기
		fputc(input, stream2); // 2번 파일에 쓰기
		fputc(input, stdout); //모니터에 쓰기
	}

	fclose(stream1);
	fclose(stream2);*/

	//4. 키보드(문자열 1개) -> 파일
	/*FILE* stream;
	char buffer[50];

	fopen_s(&stream, "c:\\temp\\data3.txt", "w");

	gets(buffer, stdin);
	fputs(buffer, stream);

	fclose(stream);*/

	//5. 
	/*미완성FILE* stream;
	char name[20];
	int kor, eng, math, total;
	
	fopen_s(&stream, "c:\\temp\\data4.txt", "w");
	while (1)
	{
		int out;
		printf("이름입력 : ");
		//scanf_s("%s", name, 20);
		gets(name);
		//puts(name);

		printf("국어점수, 영어점수, 수학점수 입력 : ");
		fscanf_s(stdin, "%d %d %d", &kor, &eng, &math);

		total = kor + eng + math;

		fprintf(stdout, "%s %d %d %d %d\n", name, kor, eng, math, total);
		fprintf(stream, "%s %d %d %d %d\n", name, kor, eng, math, total);
	
		printf("종료하시겠습니까? 종료 : 0   계속 : 1 ");
		scanf("%d", &out);
		if (out == 0) break;
	}
	fclose(stream); */

	return 0; 
}