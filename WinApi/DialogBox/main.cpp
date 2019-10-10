#include<windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInst,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),0,(DlgProc),0);

}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	
		//Добавление компонентов окна.
		break;
	case WM_COMMAND:
		//Обработка событий нажатия на кнопки, текстовые поля и тд
		switch (LOWORD(wParam))
		{
		case IDOK:
			MessageBox(NULL, "Была нажата кнопка Ок.", "Info", MB_OK | MB_ICONINFORMATION);
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return FALSE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return FALSE;
	
	}
	//EndDialog(hwnd, 0);
	return FALSE;
}