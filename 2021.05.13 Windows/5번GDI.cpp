// WindowsProject.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//
//#define ON_MAIN
#ifdef ON_MAIN

#include "framework.h"
#include "WindowsProject.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
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

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�:
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
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
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
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

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
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    if(0) // StockObject ���
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        HBRUSH MyBr = (HBRUSH)GetStockObject(GRAY_BRUSH);
        HBRUSH OldBr = (HBRUSH)SelectObject(hdc, MyBr);
        Rectangle(hdc, 300, 300, 500, 500);

    /*    HBRUSH MyBr2 = (HBRUSH)GetStockObject(BLACK_BRUSH);
        OldBr = (HBRUSH)SelectObject(hdc, MyBr2);*/

        SelectObject(hdc, OldBr);

        Rectangle(hdc, 50, 50, 200, 200);
        EndPaint(hWnd, &ps);
    }
    if (1) //������ �귯�� ����
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        //HBRUSH RedBr = CreateSolidBrush(RGB(200, 250, 70));
        HBRUSH RedBr = CreateHatchBrush(HS_FDIAGONAL,RGB(255, 0, 0));
        HBRUSH OldBr = (HBRUSH)SelectObject(hdc, RedBr);
        Rectangle(hdc, 300, 300, 500, 500);

        SelectObject(hdc, OldBr);

        Rectangle(hdc, 50, 50, 200, 200);
        EndPaint(hWnd, &ps);
    }
    if (0) //������ �� ����
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        HPEN MyPen = CreatePen(PS_DASHDOT, 1, RGB(0, 169, 255));
        HPEN OldPen = (HPEN)SelectObject(hdc, MyPen);
        Rectangle(hdc, 300, 300, 500, 500);

        SelectObject(hdc, OldPen);

        Rectangle(hdc, 50, 50, 200, 200);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_MOUSEMOVE:
    {
        HDC hdc;
        hdc = GetDC(hWnd);

        int x, y, r;

        x = rand() % 640;
        y = rand() % 480;
        r = rand() % 10 + 10;

        HBRUSH RedBr = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        HBRUSH OldBr = (HBRUSH)SelectObject(hdc, RedBr);

        HPEN MyPen = CreatePen(PS_DOT, 1, RGB(rand() % 256, rand() % 256, rand() % 256));
        HPEN OldPen = (HPEN)SelectObject(hdc, MyPen);

        Ellipse(hdc, x-y, x-y, 1000, 500);

        SelectObject(hdc, OldBr);
        SelectObject(hdc, OldPen);

        ReleaseDC(hWnd, hdc);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        InvalidateRect(hWnd, NULL, TRUE); 
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

#endif