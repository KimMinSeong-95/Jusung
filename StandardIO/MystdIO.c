#include<stdio.h>
#pragma once
#define MY_ARRAY
#ifdef MY_ARRAY ///////////////////////////

int stdio_main(void)
{
	printf("Hello Wolrd\n\n");

	int a = 255;
	printf("������ : %d\n", a);
	printf("������ : %#o\n", a);
	printf("�������� : %#x\n", a);

	double b = 89.567;

	printf("%f\n", b);
	printf("%F\n", b);
	printf("%e\n", b);
	printf("%E\n", b);

	printf("a�� �ּ� : %p\n", &a);
	//printf("main�� �ּ� : %p\n", &stdio_main);
	printf("printf�� �ּ� : %p\n", &printf);

	printf("enter a char : ");
	char ch = getchar();
	printf("��� : %d, %c\n", ch, ch);
	printf("�빮�ڷ� ��ȯ : %d, %c\n", ch-32, ch-32);

	return 0;
}
#else ///////////////////////////

int main(void)
{
	printf("Hello, World\n");
	return 0;
}

#endif ///////////////////////////