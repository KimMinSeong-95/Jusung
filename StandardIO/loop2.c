#include<stdio.h>

int main()
{
	int num;

	printf("정수를 입력해주세요 : ");
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
		printf("%d\t", i);

}