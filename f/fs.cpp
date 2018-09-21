#include "stdafx.h"
#include "FuckTheMouse.h"
#include "ClockR.h"

HINSTANCE hinst;


int showWindow(int nCmdShow);
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hinst = hInstance;
	showWindow(nCmdShow);
	return 0;
}


HWND constructWindow(WNDCLASSEX wcx, MSG& msg, BOOL& fGotMesssage)
{
	//WNDCLASSEX wcx;
	HWND hwnd;
	//MSG msg;
	//BOOL fGotMessage;
	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = MainWndProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hinst;
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.lpszMenuName = NULL;
	wcx.lpszClassName = L"MainClass";
	wcx.hIconSm = (HICON)LoadImage(hinst, MAKEINTRESOURCE(5), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	
	RegisterClassEx(&wcx);

	hwnd = CreateWindow(L"FTM", L"Fuck The Mouse", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 200, 100, (HWND)NULL, (HMENU)NULL, hinst, (LPVOID)NULL);
	return hwnd;
}

int showWindow(int nCmdShow)
{
	MSG msg;
	BOOL b;
	HWND hwnd = constructWindow(WNDCLASSEX(), msg, b);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while ((b = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && b != -1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		ExitThread(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}