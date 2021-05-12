#include<stdio.h>

//#define for
#ifdef for
int main()
{
	int num, sum = 0, summ = 0;

	printf("숫자를 하나 입력하세요 : ");

	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		sum = sum + i;
		if (i % 2 == 0)
			summ = summ + i;
	}
	printf("0부터 %d까지의 합은 : %d\n", num, sum);
	printf("0부터 %d까지의 짝수 합은 : %d\n", num, summ);

	return 0;
}
#else
int main()
{
	int num, sum = 0, summ = 0, i = 0;

	printf("숫자를 하나 입력하세요 : ");

	scanf_s("%d", &num);

	while (i <= num)
	{
		sum = sum + i;
		if (i % 2 == 0)
			summ = summ + i;
		i++;
	}
	printf("0부터 %d까지의 합은 : %d\n", num, sum);
	printf("0부터 %d까지의 짝수 합은 : %d\n", num, summ);

	return 0;
}
#endif