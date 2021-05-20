// WindowsProject.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//
#define ON_MAIN
#ifdef ON_MAIN

#include "framework.h"
#include "WindowsProject.h"

#define MAX_LOADSTRING 100
#define WM_CHECKBINGO   WM_USER + 1

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
BOOL g_bMyTurn = TRUE;//������ O , ���� X
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
    // ���ϵ� ������ Ŭ����
    wcex.lpfnWndProc = ChildProc;
    wcex.lpszClassName = IpszClass;
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    RegisterClassExW(&wcex);

    return 0;
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
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
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

       //���� �ٵ���
       for (int i = 0; i < 3; i++)

           switch ((int)GetProp(g_hChildWnd[x][i], TEXT("������")))
           {
               case  bingoMINE:
                   A++;
                   break;

               case  bingoYOURS:
                   B++;
                   break;
           }
       //���κ���
       if (A == 3 )
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[x][i], TEXT("������"), (HANDLE)bingoMyBINGO);

       else if(B == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[x][i], TEXT("������"), (HANDLE)bingoYourBINGO);

       A = 0;
       B = 0;

       for (int i = 0; i < 3; i++)
           switch ((int)GetProp(g_hChildWnd[i][y], TEXT("������")))
           {
           case  bingoMINE:
               A++;
               break;

           case  bingoYOURS:
               B++;
               break;
           }
       // �밢�� x == y , (x+y)/2 == 1
       //���κ���
       if (A == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[i][y], TEXT("������"), (HANDLE)bingoMyBINGO);

       else if (B == 3)
           for (int i = 0; i < 3; i++)
               SetProp(g_hChildWnd[i][y], TEXT("������"), (HANDLE)bingoYourBINGO);

       InvalidateRect(hWnd, NULL, TRUE);
       ����
       /*nBingoCount = 0;
       for (int i = 0; i < MAX; i++)
       {
           int tmp = (int)GetProp(g_hChildWnd[x][i], _T("������"));
           if (tmp == a)
               nBingoCount++;
       }
       if (nBingoCount == 3)
       {
           for (int i = 0; i < MAX; i++)
           {
               SetProp(g_hChildWnd[x][i], _T("������"), (HANDLE)(BingX + 1));//enum
               InvalidateRect(g_hChildWnd[x][i], NULL, TRUE);
           }
       }
       //����
       nBingoCount = 0;
       for (int i = 0; i < MAX; i++)
       {
           int tmp = (int)GetProp(g_hChildWnd[i][y], _T("������"));
           if (tmp == a)
               nBingoCount++;
       }
       if (nBingoCount == 3)
       {
           for (int i = 0; i < MAX; i++)
           {
               SetProp(g_hChildWnd[i][y], _T("������"), (HANDLE)(BingX + 1));//enum
               InvalidateRect(g_hChildWnd[i][y], NULL, TRUE);
           }
       }*/
    }
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

        return 0;
    }
}
LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int nProp;
    switch (message)
    {
    case WM_CREATE:
        SetProp(hWnd, TEXT("������"), (HANDLE)bingoNONE);//init

        break;

    case WM_LBUTTONDOWN:
        nProp = (int)GetProp(hWnd, TEXT("������"));
        if (nProp == bingoNONE)
        {
            if (g_bMyTurn == TRUE)
                SetProp(hWnd, TEXT("������"), (HANDLE)bingoMINE);
            else //if(g_bMyTurn == FALSE)
                SetProp(hWnd, TEXT("������"), (HANDLE)bingoYOURS);

            InvalidateRect(hWnd, NULL, TRUE);
            g_bMyTurn = !g_bMyTurn;

            //�θ� �����쿡�� ����üũ�� ��û�Ѵ�
            nProp = (int)GetProp(hWnd, TEXT("������"));
            SendMessage(g_hMainWnd, WM_CHECKBINGO, (WPARAM)hWnd, nProp);
        }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        nProp = (int)GetProp(hWnd, TEXT("������"));
        if (nProp == bingoNONE) {
            Rectangle(hdc, 10, 10, 90, 90);
        }
        else if (nProp == bingoMINE)
        {
            Ellipse(hdc, 10, 10, 90, 90);
        }
        else if (nProp == bingoMyBINGO)
        {
            //������ �׸�
            HBRUSH RedBr = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH OldBr = (HBRUSH)SelectObject(hdc, RedBr);
            Rectangle(hdc, 10, 10, 90, 90);
            SelectObject(hdc, OldBr);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 20, 30, _T("���� ����"), 5);

            DeleteObject(RedBr);
        }
        else if (nProp == bingoYOURS)
        {       
            MoveToEx(hdc, 10, 10, NULL); LineTo(hdc, 90, 90);
            MoveToEx(hdc, 10, 90, NULL); LineTo(hdc, 90, 10);
        }
        else if (nProp == bingoYourBINGO)
        {
            //�Ķ��� �׸�
            HBRUSH BlueBr = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH OldBr = (HBRUSH)SelectObject(hdc, BlueBr);

            Rectangle(hdc, 10, 10, 90, 90);
            SelectObject(hdc, OldBr);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 20, 30, _T("���� ����"), 5);

            DeleteObject(BlueBr);
        }
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        RemoveProp(hWnd, TEXT("������"));
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        return 0;
    }
}

#endif