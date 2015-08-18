@@ -0,0 +1,46 @@
#include "Input.h"

static HWND Dota2Hwnd = FindWindow(NULL, "DOTA 2");

void Click(WORD x, WORD y, int times, int type)
{
	if (type == 0)
	{
		LPARAM lParam = MAKELPARAM(x, y);
		for (int i = 0; i < times; i++)
		{
			PostMessage(Dota2Hwnd, WM_MOUSEMOVE, 0, lParam);
			PostMessage(Dota2Hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
			PostMessage(Dota2Hwnd, WM_LBUTTONUP, 0, lParam);
			Sleep(10);
		}
	}
	else
	{
		LPARAM lParam = MAKELPARAM(x, y);
		for (int i = 0; i < times; i++)
		{
			PostMessage(Dota2Hwnd, WM_MOUSEMOVE, 0, lParam);
			PostMessage(Dota2Hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);
			PostMessage(Dota2Hwnd, WM_RBUTTONUP, 0, lParam);
			Sleep(10);
		}
	}
}

void SendKey(DWORD vkey)
{
	WORD wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
	PostMessage(Dota2Hwnd, WM_KEYDOWN, vkey, 1 | (wScan << 16));
	PostMessage(Dota2Hwnd, WM_KEYUP, vkey, 1 | (wScan << 16) | (3 << 30));
	Sleep(10);
}

void CallMissing(DWORD delay)
{
	for (;;)
	{
		SendKey(0x57);
		Sleep(delay);
	}
}
