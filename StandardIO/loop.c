#include<stdio.h>

int main()
{
	int num;

	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		for(int j = 1; j <= i; j++)
			printf("%d ", j);
		printf("\n");
	}

	for (int i = 0; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
	
	for (int i = 0; i <= num; i++)
	{
		for (int j = num; j > i; j--)
			printf(" ");
		for (int z = 0; z < i; z++)
			printf("*");
		printf("\n");
	}



}