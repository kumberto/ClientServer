// EventAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>

HANDLE h = INVALID_HANDLE_VALUE;

DWORD WINAPI ClientTread(LPVOID arg)
{
	DWORD res = WaitForSingleObject(h, INFINITE);
	ResetEvent(h);

	HANDLE h2 = OpenEventA(EVENT_MODIFY_STATE, TRUE, "MyServer");
	SetEvent(h2);

	res = WaitForSingleObject(h, INFINITE);
	ResetEvent(h);

	std::cout << "Response server";

	return 0;
}

int main()
{
	h = CreateEventA(0, FALSE, FALSE, "MyClient");

	HANDLE tClient = CreateThread(0, 0, ClientTread, 0, 0, 0);

	WaitForSingleObject(tClient, INFINITE);
	return 0;
}
