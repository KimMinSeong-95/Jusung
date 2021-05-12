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

#pragma pack(push, 1) // 메모리 낭비 X
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

//국영수 총점 평균
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

typedef struct student STUDENT; // 지금부터 struct student를 STUDENT 라고 부른다

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
	//열거형
	{
		enum season{SPRING, SUMER, FALL, WINTER};
		enum week { SON, MON, TWE, WED=5, THU, FRI, SAT }; // 0,1,2,5,6,7

		int mybirth = SPRING;
		int today = THU;
		printf("내 생일은 %d, %d\n", mybirth, today);

		return 0;
	}
	//공용체
	{
		union shape test;
		test.x = 10;
		printf("union %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union %d, %d\n", test.x, test.y);
		printf("union 사이즈 %d\n", sizeof(test));
		printf("union 사이즈 %d\n", sizeof(union shape));


		return 0;
	}

	//구조체의 자기 참조  a->b->c 주소
	{
		worker a = { 1,"홍길동", NULL };
		worker b = { 2,"김민성", NULL };
		worker c = { 3,"석정훈", NULL };
		worker d = { 4,"박현민", NULL };
		worker e = { 5,"손황기", NULL };

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
	

	// 구조체의 포인터
	STUDENT kim = { 10, "김민성", {82, 59, 100} };
	STUDENT* pStu = NULL;
	pStu = &kim;


	pStu->s.sum = pStu->s.kor + pStu->s.eng + pStu->s.math;
	pStu->s.evg = pStu->s.sum / 3;
	printf("%d번 %s 학생의 성적 = 총점 : %d\t 평균 : %.2f\n", kim.no, kim.name, kim.s.sum, kim.s.evg);

	return 0;

	// 중첩 구조체
	/*struct student kim = { 10, "김민성", {82, 59, 100} };

	kim.s.sum = kim.s.kor + kim.s.eng + kim.s.math;
	kim.s.evg = kim.s.sum / 3;
	printf("%d번 %s 학생의 성적 = 총점 : %d\t 평균 : %.2f\n", kim.no, kim.name, kim.s.sum, kim.s.evg);
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
		printf("%d번학생의 성적 = 총점 : %d\t 평균 : %.2f\n", i+1 ,myClass[i].sum, myClass[i].evg);
	}*/


	/*struct score kim = { 95, 50, 89 };
	kim.sum = kim.kor + kim.eng + kim.math;
	kim.evg = kim.sum / 3;
	printf("kim의 성적 총점 : %d \t 평균 : %F\n ", kim.sum, kim.evg);*/

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
	printf("MYPOINT의 사이즈 : %d\n", sizeof(MYPOINT)); //8B
	printf("MYRECT의 사이즈 : %d\n", sizeof(MYRECT)); //16B

	printf("MYDATA의 사이즈 : %d\n", sizeof(struct MYDATA)); //16B
	printf("USEDATA의 사이즈 : %d\n", sizeof(struct USEDATA)); //8B*/

}