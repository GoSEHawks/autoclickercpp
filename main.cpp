#include<iostream>
#include<Windows.h>

bool bState(false);

void menu(bool bState)
{
	system("cls");
	std::cout << " auto clicker\n";
	std::cout << " press X to start or stop\n";

	if (bState)
	{
		std::cout << "Status: ON\n";
	}
	else
	{
		std::cout << "Status: OFF\n";
	}
}
int main()
{
	menu(bState);
	while (true)
	{
		if (GetAsyncKeyState(0x58) & 1)
		{
			bState = !bState;
			menu(bState);
		}
		if (bState)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		Sleep(10);
	}
	return 0;
}