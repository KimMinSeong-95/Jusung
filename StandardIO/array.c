#include<stdio.h>
#define SWAP(a,b) {int t=a; a=b; b=t}

int main()
{
	int alist[4][5] = {
		{10,20,30,40},
		{50,60,70,80},
		{90,100,110,120}
	};
	int xsum, ysum, total = 0;
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", alist[i][j]);
	}
	printf("\n\n");*/


	for (int i = 0; i < 3; i++)
	{
		xsum = 0;
		for (int j = 0; j < 5; j++)
		{
			if (j != 4)
			{
				printf("%d\t", alist[i][j]);
				xsum = xsum + alist[i][j];
			}
			else 
				printf("%d", xsum);
		}
		printf("\n");
	}
	ysum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			ysum = ysum + alist[j][i];
		total = total + ysum;
		if (i == 4)
			printf("%d", total);
		else
			printf("%d\t", ysum);
		ysum = 0;
	}

	/*int arrgrade[2][3] = { 1,2,3,4,5,6 };
	printf("林家 : %d\n", arrgrade);
	printf("林家 : %d\n", arrgrade[0]);
	printf("林家 : %d\n", arrgrade[0][1]);
	printf("林家 : %d\n", arrgrade[1]);
	printf("林家 : %d\n", arrgrade[1][1]);

	printf("林家 : %d\n", *(arrgrade+1));


	printf("林家5: %d\n", *(*(arrgrade + 1) + 1)); //5

	printf("林家4: %d\n", *(*(arrgrade)+1)); //2
	printf("林家5: %d\n", *(*(arrgrade + 1) + 1)); //5*/


	/*int arlumbers[7] = { 10,40,30,20,35,1,-5 };
	int max;

	max = arlumbers[0];
	for (int i = 1; i < sizeof(arlumbers)/ sizeof(int); i++)
	{
		if (max < arlumbers[i])
			max = arlumbers[i];
	}
	printf("MAX : %d\n", max);

	int min;

	min = *arlumbers;
	for (int i = 1; i < sizeof(arlumbers) / sizeof(int); i++)
		if (min > *(arlumbers+i))
			min = *(arlumbers+i);

	printf("MIN : %d\n", min);*/

	/*int arr[3] = { 1, 2, 3 };
	char latter[3] = { 'A', 'B', 'C' };

	for (int i = 0; i < 3; i++)
		printf("arr : %d / %d, latter : %d / %d\n", arr[i], &arr[i], latter[i], &latter[i]);

	printf("林家1 : %d, %d, %d\n", arr, arr + 1, arr + 2);
	printf("林家1 : %d, %d, %d\n", latter, latter + 1, latter + 2);

	printf("蔼1 : %d %d %d\n", *arr, *(arr + 1), *(arr + 2));
	printf("蔼1 : %d %d %d\n", *latter, *(latter + 1), *(latter + 2));
	return 0;*/
}