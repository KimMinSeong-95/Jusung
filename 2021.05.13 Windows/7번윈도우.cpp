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
                MessageBox(hWnd, _T("�޸����� ���� �������ּ���"), _T("�˸�"), MB_OK);
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
        // �޴� ������ ���� �м��մϴ�:
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
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
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