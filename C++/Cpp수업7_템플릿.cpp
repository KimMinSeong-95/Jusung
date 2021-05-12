#include<iostream>
using namespace std;

#define ON_MAIN
#ifdef ON_MAIN

//int mymax(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//char mymax(char x, char y)
//{
//	return x > y ? x : y;
//}
//
//double mymax(double x, double y)
//{
//	return x > y ? x : y;
//}

//함수 템플릿의 정의
template <typename T> T mymax(T x, T y)
{
	return x > y ? x : y;
}
template <typename T> T SWAP(T a, T b)
{
	T t = a; a = b; b = t;
	cout << a << " <--> " <<  b << endl;

	return 0;
}

int main()
{
	cout << mymax(10, 20) << endl;
	cout << mymax(3.14, 0.2) << endl;
	cout << mymax('A', 'B') << endl;

	cout << mymax<int>(10, 13.14) << endl;
	cout << mymax<double>(10, 13.14) << endl;

	SWAP(10, 20);
	SWAP(3.14, 0.2);
	SWAP('A', 'B');

	return 0;
}
#endif