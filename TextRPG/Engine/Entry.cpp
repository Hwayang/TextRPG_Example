#include <Windows.h>

namespace Engine
{
    LRESULT CALLBACK Procedure(HWND const, UINT const, WPARAM const, LPARAM const);
}

/*
    호출 규약(Calling Convention)

       cdecl : 일반 함수
     stdcall : Windows API 함수
    thiscall : 멤버 함수
*/

/*
    소스 코드 주석 언어(Source Code Annotation Language, SAL)

    _In_     : 유의미한 포인터
    _In_opt_ : 무관
*/

/* Register → Create → Show → Run (→ Close → Destroy → Unregister) */

//SAL : Source code Annotation Language

int APIENTRY WinMain
(
    _In_     HINSTANCE const hInstance,
    _In_opt_ HINSTANCE const hPrevInstance,
    _In_     LPSTR     const lpCmdLine,
    _In_     int       const nShowCmd
)
{
    HWND hWindow = HWND();
    {
        WNDCLASSEX Class = WNDCLASSEX();

        Class.cbSize        = sizeof(WNDCLASSEX);
        Class.lpfnWndProc   = Engine::Procedure;
        Class.hInstance     = hInstance;
        Class.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
        Class.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        Class.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
        Class.lpszClassName = "Window";
        Class.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);

        RegisterClassEx(&Class);
    }
    {
        CREATESTRUCT Window = CREATESTRUCT();

        /*
             BYTE : unsigned char  (1 Byte)
             WORD : unsigned short (2 Byte)
            DWORD : unsigned long  (4 Byte)
        */

        Window.lpszClass = "Window";
        Window.lpszName  = "Game";
        Window.style     = WS_CAPTION | WS_SYSMENU;
        Window.cx        = 1280;
        Window.cy        = 720;
        Window.hInstance = hInstance;

        {
            RECT Rect = RECT();

            Rect.left   = 0;
            Rect.top    = 0;
            Rect.right  = Window.cx;
            Rect.bottom = Window.cy;

            AdjustWindowRectEx(&Rect, Window.style, static_cast<bool>(Window.hMenu), Window.dwExStyle);

            Window.cx = Rect.right  - Rect.left;
            Window.cy = Rect.bottom - Rect.top;

            Window.x = (GetSystemMetrics(SM_CXSCREEN) - Window.cx) / 2;
            Window.y = (GetSystemMetrics(SM_CYSCREEN) - Window.cy) / 2;
        }

        hWindow = CreateWindowEx
        (
            Window.dwExStyle,
            Window.lpszClass,
            Window.lpszName,
            Window.style,
            Window.x,
            Window.y,
            Window.cx,
            Window.cy,
            Window.hwndParent,
            Window.hMenu,
            Window.hInstance,
            Window.lpCreateParams
        );

        ShowWindow(hWindow, SW_RESTORE);
    }
    {
        MSG Message = MSG();

        while(true)
        {
            if(PeekMessage(&Message, HWND(), WM_NULL, WM_NULL, PM_REMOVE))
            {
                if(Message.message == WM_QUIT)
                    return static_cast<int>(Message.wParam);

                DispatchMessage(&Message);
            }
            else
            {
                SendMessage(hWindow, WM_APP, 0, 0);
            }
        }
    }
}