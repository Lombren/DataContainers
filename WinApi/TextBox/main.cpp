#include<windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hText1;
HWND hText2;
CHAR s_text1[] = "";
CHAR s_text2[] = "";


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hText1 = GetDlgItem(hwnd, IDC_EDIT1);
		hText2 = GetDlgItem(hwnd, IDC_EDIT2);

		SendMessage(hText1, WM_SETTEXT, 0, (LPARAM)s_text1);
		SetFocus(hText1);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDYES:
			SendMessage(hText1, WM_GETTEXT, (WPARAM)255, (LPARAM)s_text1);
			SendMessage(hText2, WM_SETTEXT, 0, (LPARAM)s_text1);
			break;
		case IDCANCEL:
			goto close;
			break;
		}
		break;
	case WM_CLOSE:
		close:
		EndDialog(hwnd, 0);
		goto end;
	}

	end:
		return FALSE;
}