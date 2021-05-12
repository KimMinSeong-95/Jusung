// c++project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//using namespace TEST;

void Gugudan()
{
    cout << "Global::Gugudan()" << endl;
}
int g_nDate = 1000;

namespace TEST
{
    int g_nDate = 100;
    void Gugudan(void)
    {
        cout << "TEST::Gugudan()" << endl;
    }
}

void TestFuncRef1(int nParam)
{
    nParam = 100;
}

void TestFuncRef2(int& nParam)
{
    nParam = 100;
}

void TestFuncRef3(int* nParam)
{
    *nParam = 100;
}

int Sum(int x, int y)
{
    return x + y;
}

int Sum(int x, int y, int z)
{
    return x + y + z;
}

double Sum(double x, double y)
{
    return x + y;
}

int TestFunc2(int nParam = 99)
{
    return nParam * 2;
}

int TestFunc3(int a, int b, int c = 99) // 디폴트는 뒤에서 부터 값을 넣어주면 가능하지만, 반대로 앞에서부터는 안됨
{
    return c * 2;
}

inline int add(int a, int b)
{
    return a + b;
}
#define ADD(a,b)((a)+(b))

int main()
{
    //인라인 함수 (vs 매크로 함수)
    {
        cout << add(10, 20) << endl;
        cout << ADD(30, 40) << endl;
    }
    return 0;

    //범위기반 for문
    {
        //C 스타일
        int alist[5] = { 10, 20 , 30, 40 ,50 };
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += alist[i];
            printf("%d. %d\n", i, sum);
        }
        printf("결과 출력 : %d\n", sum);

        //C++ 스타일
        sum = 0;
        for (auto n : alist)
        {
            sum += n;
        }
        cout << "결과 출력 : " << sum << endl;

    }
    return 0;

    //문자열
    {
        char name1[20] = "강호동";
        string name = "홍길동";
        
        cout << name << endl;
        cout << name.size() << endl;

        name = "박태환"; // strcpy();
        if (name == "박태환")//strcmp();
            cout << "이름 일치" << endl;
        else
            cout << "이름 불일치" << endl;

        name += " 만세"; //strcat();
        cout << name << endl;
    }
    return 0;
    //동적 메모리 연산자
    {
        //1.==============================
        int* p1 = new int;
        //int* p1 = malloc(sizeof(int));
        *p1 = 10;
        cout << *p1 << endl;
        delete p1;

        //2.==============================
        int* p2 = new int(100);
        cout << *p2 << endl;
        delete p2;

        //3.==============================
        int* arr = new int[5];
        for (int i = 0; i < 5; i++)
        {
            cout << arr + i << endl;
            arr[i] = i * 10;
            cout << arr[i] << endl;
        }
        delete[] arr;
    }
    return 0;
    //디폴트 매개변수
    {
        int a = TestFunc2(10);
        cout << a << endl;

        int b = TestFunc2();
        cout << b << endl;

        return 0;
    }
    //함수 오버로딩(=다중정의) -> by 네임맹글링 (vs extern "C")
    
    cout << Sum(3, 4) << endl;
    cout << Sum(3, 4, 5) << endl;
    cout << Sum(3.3, 4.4) << endl;

    return 0;

    //Call by Reference
    {
        int nData = 0;

        nData = 0;
        TestFuncRef1(nData);
        cout << "1."<< nData << endl;

        nData = 0;
        TestFuncRef2(nData);
        cout << "2."<< nData << endl;

        return 0;
    }
    
    //포인터 vs 레퍼런스
    int nData = 10;
    int* pt = &nData;//포인터의 선언과 초기화
    const int& ref = nData;//레퍼런스의 선언과 초기화

    cout << nData << endl;
    //ref = 20;
    cout << nData << endl;
    nData = 30;
    cout <<"여기 "<< ref << endl;

    int nAnther = 1000;
    //ref = nAnther;
    //ref++;
    cout << ref << endl;

    return 0;

    //네임스페이스
    Gugudan();//전역함수
    TEST::Gugudan();//TEST::소속함수

    cout << g_nDate << endl;
    cout << ::g_nDate << endl;
    cout << TEST::g_nDate << endl;

    return 0;
     
    //auto 사용
    int a = 10;
    int b(a);// b = a;
    auto c(b);//int로 따라감
    cout << a + b + c << endl;

    return 0;

    // cin/cout 사용
    int nAge;
    cout << "나이를 입력하세요" << endl;
    cin >> nAge;

    char szJob[32];
    cout << "직업를 입력하세요" << endl;
    cin >> szJob;

    string strName; // flow발생 X 알아서 늘어남
    cout << "이름를 입력하세요" << endl;
    cin >> strName;
 
    /// ///////////////////////////////////////
    string nickname = "천재";
    strName = strName + nickname;


    cout << "당신의 이름은 " << strName << "이고, " << "나이는 " << nAge << "살이며, " << "직업은 " << szJob << "입니다." << endl;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
