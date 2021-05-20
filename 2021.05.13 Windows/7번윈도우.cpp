// WindowsProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
//#define ON_MAIN
#ifdef ON_MAIN

#include "framework.h"
#include "WindowsProject.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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

    return RegisterClassExW(&wcex);
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
HBRUSH NowBrush;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HBRUSH hRed, hGreen, hBlue, hRandColor;
    int x = rand()% 256;
    int y = rand() % 256;
    int z = rand() % 256;

    switch (message)
    {
    case WM_CREATE:
        static HBRUSH rBrush = CreateSolidBrush(RGB(255, 0, 0));
        static HBRUSH gBrush = CreateSolidBrush(RGB(0, 255, 0));
        static HBRUSH bBrush = CreateSolidBrush(RGB(0, 0, 255));
        static HBRUSH hRandColor = CreateSolidBrush(RGB(x,y,z));
        NowBrush = hRandColor;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
        case VK_UP:
            SetWindowPos(hWnd, NULL, 0, 0, 100, 100, SWP_NOSIZE | SWP_NOZORDER);
            break;
        case VK_DOWN:
            SetWindowPos(hWnd, NULL, 100, 100, 500, 500, SWP_NOSIZE | SWP_NOZORDER);
            break;
            //case VK_LEFT:
            //    HDC hdc;
            //    hdc = GetDC(hWnd);

            //    HBRUSH hRandColor = CreateSolidBrush(RGB(x, y, z));
            //    HBRUSH OldBr = (HBRUSH)SelectObject(hdc, hRandColor);
            //    SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)OldBr);
            //    
            //    SelectObject(hdc, OldBr);
            //    ReleaseDC(hWnd, hdc);
            //    InvalidateRect(hWnd, NULL, TRUE);
            //} 
        case VK_LEFT:

            if (NowBrush == rBrush)
                NowBrush = gBrush;
            else if (NowBrush == gBrush)
                NowBrush = bBrush;
            else if (NowBrush == bBrush)
                NowBrush = rBrush;

            SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)NowBrush);
            InvalidateRect(hWnd, NULL, TRUE);

            break;
        }
    break;
    case WM_CHAR:
        if ((TCHAR)wParam == 'n')
        {
            HWND hNote;
            hNote = FindWindow(_T("NotePad"), NULL);
            if (hNote)
            {
                SendMessage(hNote, WM_CLOSE, 0, 0);
            }
            else
            {
                MessageBox(hWnd, _T("메모장을 먼저 실행해주세요"), _T("알림"), MB_OK);
            }
        }
    case WM_LBUTTONDOWN:
        SetWindowPos(hWnd, HWND_TOPMOST, 100, 100, 500, 500, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);
    break;
    case WM_RBUTTONDOWN:
        SetWindowPos(hWnd, HWND_NOTOPMOST, 100, 100, 500, 500, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);
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
    }
    return 0;
}

#endif