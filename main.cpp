#include <windows.h>
#include <tchar.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassName[] = TEXT("Simlpe Window");
TCHAR szWindowName[] = TEXT("Smart Program");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	LPSTR lpszCmdLine, int nCmdShow) {
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassName;
	wcl.hIconSm = NULL;

	if (!RegisterClassEx(&wcl)) {
		return 0;
	}
	hWnd = CreateWindowEx(NULL, szClassName, szWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
		{
			int x, y;
			x = y = 0;
			MoveWindow(hWnd, x, y, 300, 300, TRUE);
			break;
		}
		case VK_LEFT:
		{
			int x, y;
			RECT rect;
			GetWindowRect(hWnd, &rect);
			x = rect.left;
			y = rect.top;
			if (x>0) --x;
			MoveWindow(hWnd, x, y, 300, 300, TRUE);
			break;
		}
		case VK_RIGHT:
		{
			int x, y;
			RECT rect;
			GetWindowRect(hWnd, &rect);
			x = rect.left;
			y = rect.top;
			if (x<1366) ++x;
			MoveWindow(hWnd, x, y, 300, 300, TRUE);
			break;
		}
		case VK_DOWN:
		{
			int x, y;
			RECT rect;
			GetWindowRect(hWnd, &rect);
			x = rect.left;
			y = rect.top;
			if (y<768) ++y;
			MoveWindow(hWnd, x, y, 300, 300, TRUE);
			break;
		}
		case VK_UP:
		{
			int x, y;
			RECT rect;
			GetWindowRect(hWnd, &rect);
			x = rect.left;
			y = rect.top;
			if (y>0) --y;
			MoveWindow(hWnd, x, y, 300, 300, TRUE);
			break;
		}
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}