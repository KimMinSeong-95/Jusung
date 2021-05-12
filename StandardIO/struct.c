#include<stdio.h>

typedef struct point
{
	int x,y;
} MYPOINT;

typedef struct rect
{
	int x;
	int y;
	int w;
	int h;

} MYRECT;

typedef int AGE;
typedef struct point MYPOINT;

#pragma pack(push, 1) // �޸� ���� X
struct USEDATA {
	char ch;
	int age;
};//1+4 = 5

struct MYDATA {
	char ch;
	int age;
	double hight;
}; //1+4+8 = 13
#pragma pack(pop) 

//������ ���� ���
struct score {
	int kor;
	int eng;
	int math;

	int sum;
	double evg;

};

struct student
{
	int no;
	char name[20];
	struct score s;
};

typedef struct student STUDENT; // ���ݺ��� struct student�� STUDENT ��� �θ���

struct imploy
{
	int no;
	char name[20];

	struct worker* plink;
};

typedef struct imploy worker;

union shape
{
	int x, y;
};

union differ
{
	char a;
	int b;
	double c;
};

int main()
{
	//������
	{
		enum season{SPRING, SUMER, FALL, WINTER};
		enum week { SON, MON, TWE, WED=5, THU, FRI, SAT }; // 0,1,2,5,6,7

		int mybirth = SPRING;
		int today = THU;
		printf("�� ������ %d, %d\n", mybirth, today);

		return 0;
	}
	//����ü
	{
		union shape test;
		test.x = 10;
		printf("union %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union %d, %d\n", test.x, test.y);
		printf("union ������ %d\n", sizeof(test));
		printf("union ������ %d\n", sizeof(union shape));


		return 0;
	}

	//����ü�� �ڱ� ����  a->b->c �ּ�
	{
		worker a = { 1,"ȫ�浿", NULL };
		worker b = { 2,"��μ�", NULL };
		worker c = { 3,"������", NULL };
		worker d = { 4,"������", NULL };
		worker e = { 5,"��Ȳ��", NULL };

		a.plink = &b;
		b.plink = &c;
		c.plink = &d;
		d.plink = &e;

		worker* pHead = &a;
		while(pHead != NULL)
		{
			printf("[%p] %d %s %p\n", pHead, pHead->no, pHead->name, pHead->plink);
			pHead = pHead->plink;
		}
		return 0;
	}
	

	// ����ü�� ������
	STUDENT kim = { 10, "��μ�", {82, 59, 100} };
	STUDENT* pStu = NULL;
	pStu = &kim;


	pStu->s.sum = pStu->s.kor + pStu->s.eng + pStu->s.math;
	pStu->s.evg = pStu->s.sum / 3;
	printf("%d�� %s �л��� ���� = ���� : %d\t ��� : %.2f\n", kim.no, kim.name, kim.s.sum, kim.s.evg);

	return 0;

	// ��ø ����ü
	/*struct student kim = { 10, "��μ�", {82, 59, 100} };

	kim.s.sum = kim.s.kor + kim.s.eng + kim.s.math;
	kim.s.evg = kim.s.sum / 3;
	printf("%d�� %s �л��� ���� = ���� : %d\t ��� : %.2f\n", kim.no, kim.name, kim.s.sum, kim.s.evg);
	return 0;*/


	/*struct score myClass[5] =
	{
		{ 95, 50, 89 },
		{ 34, 60, 62 },
		{ 68, 70, 81 },
		{ 76, 80, 32 },
		{ 52, 90, 29 },
	};
	
	for (int i=0; i<sizeof(myClass)/sizeof(struct score);i++)
	{
		myClass[i].sum = myClass[i].kor + myClass[i].eng + myClass[i].math;
		myClass[i].evg = myClass[i].sum / 3;
		printf("%d���л��� ���� = ���� : %d\t ��� : %.2f\n", i+1 ,myClass[i].sum, myClass[i].evg);
	}*/


	/*struct score kim = { 95, 50, 89 };
	kim.sum = kim.kor + kim.eng + kim.math;
	kim.evg = kim.sum / 3;
	printf("kim�� ���� ���� : %d \t ��� : %F\n ", kim.sum, kim.evg);*/

	/*AGE kim = 45;
	AGE Lee = 33;

	int a = 100;
	a = 10;

	struct point pt1 = { 10, 20 };
	struct point pt2;
	MYPOINT pt3 = { 111,222 };
	pt2.x = 100;
	pt2.y = 200;

	printf("pt1 : %d, %d\n", pt1.x, pt1.y);
	printf("pt2 : %d, %d\n", pt2.x, pt2.y);

	MYRECT rect1 = { 10, 20,30,40 };
	printf("rect1 : %d, %d, %d, %d\n", rect1.x, rect1.y, rect1.w, rect1.h);
	printf("MYPOINT�� ������ : %d\n", sizeof(MYPOINT)); //8B
	printf("MYRECT�� ������ : %d\n", sizeof(MYRECT)); //16B

	printf("MYDATA�� ������ : %d\n", sizeof(struct MYDATA)); //16B
	printf("USEDATA�� ������ : %d\n", sizeof(struct USEDATA)); //8B*/

}