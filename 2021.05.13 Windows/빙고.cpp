// WindowsProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define ON_MAIN
#ifdef ON_MAIN

#include "framework.h"
#include "WindowsProject.h"

#define MAX_LOADSTRING 100
#define WM_CHECKBINGO   WM_USER + 1

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
BOOL g_bMyTurn = TRUE;//마이턴 O , 유턴 X
BOOL bEllipse = TRUE;
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR IpszClass = TEXT("ChildWnd");
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

enum modelBINGO {
    bingoNONE,
    bingoMINE,
    bingoMyBINGO,
    bingoYOURS,
    bingoYourBINGO
};
#define MAX 3
HWND g_hMainWnd;
HWND g_hChildWnd[MAX][MAX] = { 0, };

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
HWND hC1, hC2;
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    //===========================================
    // 차일드 윈도우 클래스
    wcex.lpfnWndProc = ChildProc;
    wcex.lpszClassName = IpszClass;
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    RegisterClassExW(&wcex);

    return 0;
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
    g_hMainWnd = hWnd;
    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
int nCount = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                g_hChildWnd[x][y] = CreateWindow(IpszClass, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
                                    x * 100, y * 100, 100, 100, hWnd, (HMENU)NULL, hInst, NULL);
            }
        }        
        break;

    case WM_CHECKBINGO:
    {
       int x = 0;
       int y = 0;

       int nBingoCount;
       HWND BingX = (HWND)wParam;
       int a = (int)lParam;

       for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
               if (g_hChildWnd[i][j] == BingX)
               {
                   x = i;
                   y = j;
               }

       int A = 0;
       int B = 0;

       //가로 다돌기
       for (int i = 0; i < 3; i++)

           switch ((int)GetProp(g_hChildWnd[x][i], TEXT("빙고모드")))
           {
               case  bingoMINE:
                   A++;
                   break;

               case  bingoYOURS:
                   B++;
                   break;
           }
       //세로빙고
       if (A == 3 )
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[x][i], TEXT("빙고모드"), (HANDLE)bingoMyBINGO);

       else if(B == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[x][i], TEXT("빙고모드"), (HANDLE)bingoYourBINGO);

       A = 0;
       B = 0;

       for (int i = 0; i < 3; i++)
           switch ((int)GetProp(g_hChildWnd[i][y], TEXT("빙고모드")))
           {
           case  bingoMINE:
               A++;
               break;

           case  bingoYOURS:
               B++;
               break;
           }
       // 대각선 x == y , (x+y)/2 == 1
       //가로빙고
       if (A == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[i][y], TEXT("빙고모드"), (HANDLE)bingoMyBINGO);

       else if (B == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[i][y], TEXT("빙고모드"), (HANDLE)bingoYourBINGO);

       InvalidateRect(hWnd, NULL, TRUE);
       세로
       /*nBingoCount = 0;
       for (int i = 0; i < MAX; i++)
       {
           int tmp = (int)GetProp(g_hChildWnd[x][i], _T("빙고모드"));
           if (tmp == a)
               nBingoCount++;
       }
       if (nBingoCount == 3)
       {
           for (int i = 0; i < MAX; i++)
           {
               SetProp(g_hChildWnd[x][i], _T("빙고모드"), (HANDLE)(BingX + 1));//enum
               InvalidateRect(g_hChildWnd[x][i], NULL, TRUE);
           }
       }
       //가로
       nBingoCount = 0;
       for (int i = 0; i < MAX; i++)
       {
           int tmp = (int)GetProp(g_hChildWnd[i][y], _T("빙고모드"));
           if (tmp == a)
               nBingoCount++;
       }
       if (nBingoCount == 3)
       {
           for (int i = 0; i < MAX; i++)
           {
               SetProp(g_hChildWnd[i][y], _T("빙고모드"), (HANDLE)(BingX + 1));//enum
               InvalidateRect(g_hChildWnd[i][y], NULL, TRUE);
           }
       }*/
    }
    break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            // DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);

        return 0;
    }
}
LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int nProp;
    switch (message)
    {
    case WM_CREATE:
        SetProp(hWnd, TEXT("빙고모드"), (HANDLE)bingoNONE);//init

        break;

    case WM_LBUTTONDOWN:
        nProp = (int)GetProp(hWnd, TEXT("빙고모드"));
        if (nProp == bingoNONE)
        {
            if (g_bMyTurn == TRUE)
                SetProp(hWnd, TEXT("빙고모드"), (HANDLE)bingoMINE);
            else //if(g_bMyTurn == FALSE)
                SetProp(hWnd, TEXT("빙고모드"), (HANDLE)bingoYOURS);

            InvalidateRect(hWnd, NULL, TRUE);
            g_bMyTurn = !g_bMyTurn;

            //부모 윈도우에게 빙고체크를 요청한다
            nProp = (int)GetProp(hWnd, TEXT("빙고모드"));
            SendMessage(g_hMainWnd, WM_CHECKBINGO, (WPARAM)hWnd, nProp);
        }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        nProp = (int)GetProp(hWnd, TEXT("빙고모드"));
        if (nProp == bingoNONE) {
            Rectangle(hdc, 10, 10, 90, 90);
        }
        else if (nProp == bingoMINE)
        {
            Ellipse(hdc, 10, 10, 90, 90);
        }
        else if (nProp == bingoMyBINGO)
        {
            //빨간색 네모
            HBRUSH RedBr = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH OldBr = (HBRUSH)SelectObject(hdc, RedBr);
            Rectangle(hdc, 10, 10, 90, 90);
            SelectObject(hdc, OldBr);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 20, 30, _T("나의 빙고"), 5);

            DeleteObject(RedBr);
        }
        else if (nProp == bingoYOURS)
        {       
            MoveToEx(hdc, 10, 10, NULL); LineTo(hdc, 90, 90);
            MoveToEx(hdc, 10, 90, NULL); LineTo(hdc, 90, 10);
        }
        else if (nProp == bingoYourBINGO)
        {
            //파란색 네모
            HBRUSH BlueBr = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH OldBr = (HBRUSH)SelectObject(hdc, BlueBr);

            Rectangle(hdc, 10, 10, 90, 90);
            SelectObject(hdc, OldBr);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 20, 30, _T("나의 빙고"), 5);

            DeleteObject(BlueBr);
        }
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        RemoveProp(hWnd, TEXT("빙고모드"));
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        return 0;
    }
}

#endif