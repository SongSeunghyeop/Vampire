// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//Git 
#include "framework.h"
#include "Client.h"
#include "Myapplication.h"
#include "myResourceManager.h"
#include "mySceneManager.h"
#include <crtdbg.h>
//----DEBUG MEMORY
#ifdef _DEBUG
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__ )
#endif
//----
#define _CRTDBG_MAP_ALLOC
#define MAX_LOADSTRING 100
// 전역 변수: 
HINSTANCE hInst;                                                            // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                             // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];              // 기본 창 클래스 이름입니다.

my::Application myapplication; // 이 코드 모듈에 포함된 함수의 선언을 전달합니다(전방선언):

ATOM                              MyRegisterClass(HINSTANCE hInstance);
BOOL                              InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK     About(HWND, UINT, WPARAM, LPARAM);

//메인 시작
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                                         _In_opt_ HINSTANCE hPrevInstance,
                                         _In_ LPWSTR    lpCmdLine,
                                         _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //_crtBreakAlloc = 290;

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    //윈도우 정보 등록 
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    //윈도우 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    //단축키 / 리소스뷰 - Accelator에서 확인 가능
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));
    MSG msg;

    // 기본 메시지 루프입니다:  
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) // 메세지 유무 지속적으로 확인
        {
            if (WM_QUIT == msg.message) // 메세지가 종료메세지이면 break;
            {
                break;
            }
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 방향키 메세지가 입력되면 WndProc로 이동 // 실행할게 없으므로 지나감
                                                                                                           // while문 다시 돌때는 else로 이동
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            myapplication.Run(); // 메세지가 없으면 실행
        }
    }

    my::SceneManager::Release();
    my::ResourceManager::Release();

    if (WM_QUIT == msg.message) {  }
    return (int) msg.wParam;
}
//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex; //  구조체

    wcex.cbSize =                sizeof(WNDCLASSEX);
    wcex.style =                   CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc =      WndProc;
    wcex.cbClsExtra =          0;
    wcex.cbWndExtra =        0;
    wcex.hInstance =            hInstance;
    wcex.hIcon =                   LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor =               LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  =   (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName =   NULL;
    wcex.lpszClassName  =  szWindowClass;
    wcex.hIconSm =              LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
//
//   함수: InitInstance(HINSTANCE, int)
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//   주석:
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, L"Vampire Survivors", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   
   ShowWindow(hWnd, nCmdShow); // 윈
   UpdateWindow(hWnd);

   myapplication.Initialize(hWnd); // 씬 전체 resize, 각 씬마다 레이어 resize, 플레이어 레이어에 드래곤 생성

   return TRUE;
}
//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//  용도: 주 창의 메시지를 처리합니다.
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam); // 특별히 사용자가 작성하지 않은 함수가 필요할 경우 윈도우 제공 함수를 사용할 것
            }
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
// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
