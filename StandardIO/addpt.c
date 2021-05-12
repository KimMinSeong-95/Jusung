#include<stdio.h>

#define swap(a,b) {int t=aaa;aaa=bbb;bbb=t;} //call by value

int Add(int x, int y)
{
	int sum = x + y;
	return sum;
}

int sub(int x, int y)
{
	int sum = x - y;
	return sum;
}

void count()
{
	static int ct = 0; //한번만 실행 정적변수
	ct++;
	printf("불린 횟수 : %d\n", ct);
}

int facto(int x)
{
	int total = 1;
	for (int i = 1; i <= x; i++) 
	{
		total = total * i;
	}
	printf("%d\n", total);
	return total;
}
void self_service()
{
	printf("self_service");
	//self_service();
}
int facto_self(int x)
{
	if (x <= 1)
		return 1;
	else
		return x * facto_self(x - 1);
}
void swap2(int* x, int* y)//call by address
{
	printf("\tswap전 : %d, %d\n", *x, *y);
	int temp;
	temp = *x; *x = *y; *y = temp;
	printf("\tswap후 : %d, %d\n", *x, *y);

}

void swap3(int x, int y)//call by reference
{
	printf("\tswap전 : %d, %d\n", x, y);
	int temp;
	temp = x; x = y; y = temp;
	printf("\tswap후 : %d, %d\n", x, y);

}


int main()
{
	int aaa = 10;
	int bbb = 20;

	printf("swap호출 전 : %d, %d\n", aaa, bbb);
	swap2(10, 20);
	printf("swap호출 후 : %d, %d\n", aaa, bbb);

	int (*p1)(int, int) = NULL;
	p1 = Add;

	int ret1 = p1(10, 60);
	printf("%d\n", ret1);

	p1 = sub;
	int ret2 = p1(10, 60);
	printf("%d\n", ret2);

	void (*p2)() = NULL;
	p2 = self_service;
	p2();


	return 0;
	//count();
	//count();
	//count();

	facto(6);
	printf("%d",facto_self(5));
	self_service();
	//int a = 10;
	//int b = 20;

	//int c = Add(a, b);
	//printf("%d", c);

	return 0;
}