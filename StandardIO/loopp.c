#include<stdio.h>

//#define for
#ifdef for
int main()
{
	int num, sum = 0, summ = 0;

	printf("���ڸ� �ϳ� �Է��ϼ��� : ");

	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		sum = sum + i;
		if (i % 2 == 0)
			summ = summ + i;
	}
	printf("0���� %d������ ���� : %d\n", num, sum);
	printf("0���� %d������ ¦�� ���� : %d\n", num, summ);

	return 0;
}
#else
int main()
{
	int num, sum = 0, summ = 0, i = 0;

	printf("���ڸ� �ϳ� �Է��ϼ��� : ");

	scanf_s("%d", &num);

	while (i <= num)
	{
		sum = sum + i;
		if (i % 2 == 0)
			summ = summ + i;
		i++;
	}
	printf("0���� %d������ ���� : %d\n", num, sum);
	printf("0���� %d������ ¦�� ���� : %d\n", num, summ);

	return 0;
}
#endif