#include<windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInst,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	MessageBox(NULL, "Hello! It's my first window in winApi", "Hello WinAPI", MB_OK | MB_ICONINFORMATION);
	int answer = MessageBox(NULL, "�� ������ ������� WinApi?", "WinAPI", MB_YESNOCANCEL | MB_ICONQUESTION | MB_DEFBUTTON3 | MB_SYSTEMMODAL);
	if (answer == IDYES)
	{
		MessageBox(NULL, "��������� � ��������!", "���������", MB_OK | MB_ICONINFORMATION);
	}
	else if(answer==IDNO)
	{
		MessageBox(NULL, "����� � ������ ���������!", "���������", MB_OK | MB_ICONINFORMATION);
	}

}