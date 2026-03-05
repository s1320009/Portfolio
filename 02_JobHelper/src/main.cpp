#include <Windows.h>

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            TextOutA(hdc, 10, 10, "Hello, GUI!", 11);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProcA(hwnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow
) {
    // ウィンドウクラスの登録
    WNDCLASSA wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "JobHelperClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassA(&wc)) {
        return 1;
    }

    // ウィンドウの作成
    HWND hwnd = CreateWindowA(
        "JobHelperClass",
        "Job Helper Application",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) {
        return 1;
    }

    // ウィンドウを表示
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // メッセージループ
    MSG msg = {};
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return (int)msg.wParam;
}