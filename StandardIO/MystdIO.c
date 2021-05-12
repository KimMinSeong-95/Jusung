#include<stdio.h>
#pragma once
#define MY_ARRAY
#ifdef MY_ARRAY ///////////////////////////

int stdio_main(void)
{
	printf("Hello Wolrd\n\n");

	int a = 255;
	printf("십진수 : %d\n", a);
	printf("팔진수 : %#o\n", a);
	printf("십육진수 : %#x\n", a);

	double b = 89.567;

	printf("%f\n", b);
	printf("%F\n", b);
	printf("%e\n", b);
	printf("%E\n", b);

	printf("a의 주소 : %p\n", &a);
	//printf("main의 주소 : %p\n", &stdio_main);
	printf("printf의 주소 : %p\n", &printf);

	printf("enter a char : ");
	char ch = getchar();
	printf("결과 : %d, %c\n", ch, ch);
	printf("대문자로 변환 : %d, %c\n", ch-32, ch-32);

	return 0;
}
#else ///////////////////////////

int main(void)
{
	printf("Hello, World\n");
	return 0;
}

#endif ///////////////////////////