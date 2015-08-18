@@ -0,0 +1,74 @@
#include "Config.h"
#include "Input.h"
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	GetConfig();
	Sleep(3000);
	if (DOTA_SPAM_MISSING)
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CallMissing, (WORD*)5000, 0, NULL);
	if (DOTA_FEED_ALL == true)
	{
		for (;;)
		{
			Click(Store[0], Store[1], 1, 0);
			Sleep(500);
			Click(Play[0], Play[1], 1, 0);
			Sleep(500);
			Click(FindMatch[0], FindMatch[1], 1, 0);
			Sleep(500);
			Click(AcceptMatch[0], AcceptMatch[1], 1, 0);
			Sleep(500);
			Click(LockHero[0], LockHero[1], 1, 0);
			Sleep(500);
			SendKey(DOTA_KEY_SELECT_HERO);
			Sleep(100);
			SendKey(DOTA_KEY_ATTACK);
			Click(Mid[0], Mid[1], 1, 0);
			Sleep(500);
			Click(Leave[0], Leave[1], 1, 0);
			if (DOTA_FEED_COURIERS)
			{
				Sleep(500);
				Click(Shop[0], Shop[1], 1, 0);
				Sleep(500);
				Click(Courier[0], Courier[1], 1, 1);
				Sleep(500);
				Click(Shop[0], Shop[1], 1, 0);
				Sleep(500);
				SendKey(DOTA_KEY_SELECT_HERO);
				Sleep(100);
				SendKey(0x5A); // z
				Sleep(100);
				SendKey(0x58); // x
				Sleep(100);
				SendKey(0x43); // c
				Sleep(100);
				SendKey(0x56); // v
				Sleep(100);
				SendKey(0x42); // b
				Sleep(100);
				SendKey(0x4E); // n
				Sleep(500);
				SendKey(DOTA_KEY_SELECT_COURIER);
				Sleep(100);
				Click(Mid[0], Mid[1], 1, 1);
			}
			Sleep(10000);
		}
	}
	else
	{
		for (;;)
		{
			SendKey(DOTA_KEY_ATTACK);
			Sleep(100);
			Click(Mid[0], Mid[1], 1, 0);
			Sleep(5000);
		}
	}
	return 0;
}
