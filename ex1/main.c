#include <windows.h>
#include <stdio.h>

LRESULT 
CALLBACK WindowProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
);


int 
WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)	{
	WNDCLASS wndcls;
	HWND hwnd;
	MSG msg;

	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WindowProc;
	wndcls.lpszClassName = "firstWin32";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);

	hwnd = CreateWindow(
		"firstWin32",
		"First Win32 Application",
		WS_OVERLAPPEDWINDOW,
		10, 10,
		640, 480,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT 
CALLBACK WindowProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
)	{
	char		szChar[20];
	HDC			hdc;
	PAINTSTRUCT	ps;

	switch (uMsg)	{
	case WM_CHAR:			// keydown
		sprintf(szChar, "char is %d", wParam);
		MessageBox(hwnd, szChar, "First Win32 Application", 0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "Mouse clicked!", "First Win32 Application", 0);
			
		hdc = GetDC(hwnd);

		TextOut(hdc, 0, 50, "Win32 Window", strlen("Win32 Window"));
		
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		TextOut(hdc, 0, 0, "Message WM_PAINT", strlen("Message WM_PAINT"));
		
		EndPaint(hwnd, &ps);
		return 0;
	case WM_CLOSE:
		if (IDYES == 
				MessageBox(
					hwnd, 
					"Are you sure to close this window?", 
					"First Win32 Application",
					MB_YESNO))	{
			DestroyWindow(hwnd);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
