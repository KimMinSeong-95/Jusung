#include<stdio.h>
#pragma warning (disable:4996)

int main()
{
	int age;
	char name[20];

	printf("���� �Է� : ");
	scanf("%d", &age);

	//fflush(stdin);
	getchar();

	printf("�̸� �Է� : ");
	gets(name);


	printf("%d %s\n", age, name);

	
	//1. Ű���� -> �����
	/*	char ch = 0;
	while (ch != EOF) 
	{
		ch = getche();
		//putchar(ch);
	}*/

	//2. Ű�굵 -> ����
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

	//3. ���� -> ����/�����
	/*FILE* stream1;
	FILE* stream2;
	int input = 0;

	fopen_s(&stream1, "c:\\temp\\data.txt", "r");
	fopen_s(&stream2, "c:\\temp\\data2.txt", "w");

	while (input != EOF)
	{
		input = fgetc(stream1); // 1�� ���Ͽ��� �б�
		fputc(input, stream2); // 2�� ���Ͽ� ����
		fputc(input, stdout); //����Ϳ� ����
	}

	fclose(stream1);
	fclose(stream2);*/

	//4. Ű����(���ڿ� 1��) -> ����
	/*FILE* stream;
	char buffer[50];

	fopen_s(&stream, "c:\\temp\\data3.txt", "w");

	gets(buffer, stdin);
	fputs(buffer, stream);

	fclose(stream);*/

	//5. 
	/*�̿ϼ�FILE* stream;
	char name[20];
	int kor, eng, math, total;
	
	fopen_s(&stream, "c:\\temp\\data4.txt", "w");
	while (1)
	{
		int out;
		printf("�̸��Է� : ");
		//scanf_s("%s", name, 20);
		gets(name);
		//puts(name);

		printf("��������, ��������, �������� �Է� : ");
		fscanf_s(stdin, "%d %d %d", &kor, &eng, &math);

		total = kor + eng + math;

		fprintf(stdout, "%s %d %d %d %d\n", name, kor, eng, math, total);
		fprintf(stream, "%s %d %d %d %d\n", name, kor, eng, math, total);
	
		printf("�����Ͻðڽ��ϱ�? ���� : 0   ��� : 1 ");
		scanf("%d", &out);
		if (out == 0) break;
	}
	fclose(stream); */

	return 0; 
}