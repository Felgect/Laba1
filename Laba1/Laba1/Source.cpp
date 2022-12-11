#include <iostream>

#include <tchar.h>

#include <conio.h>

#include <windows.h>

#include <locale>

#include <VersionHelpers.h>

#define cout wcout

using namespace std;

int main(int argc, _TCHAR* argv[])

{

	setlocale(LC_ALL, "rus");

	cout.imbue(locale("rus_rus.1251"));

	WCHAR str[4096];

	DWORD sz = 4096;

	GetUserName(str, &sz); //имя пользователя

	cout << "User name: " << str << endl;

	GetComputerName(str, &sz);//имя компьютера

	cout << "Computer name: " << str << endl;

	GetUserName(str, &sz);//имя пользователя

	cout << "User name: " << str << endl;

	GetSystemDirectory(str, 4096); //Путь к системной папке

	cout << "The path to the system folder: " << str << endl;

	GetWindowsDirectory(str, 4096);//Путь к папке Windows

	cout << "The path to the windows folder: " << str << endl;

	GetTempPath(4096, str);//Путь к временной папке

	cout << "The path to the temporary folder: " << str << endl;

	OSVERSIONINFO osversion;

	memset(&osversion, 0, sizeof(OSVERSIONINFO));

	osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	//GetVersionEx(&osversion);

	if (!IsWindows10OrGreater()) { cout << "Not win10" << endl; }

	else { cout << "Windows 10" << endl; }

	cout << "System metrics:" << endl

		//Системные метрики

		<< "Screen Resolution: " << GetSystemMetrics(0)

		//Разрешение экрана

		<< "x" << GetSystemMetrics(1) << endl;


	ACCESSTIMEOUT param;

	param.cbSize = sizeof(ACCESSTIMEOUT);

	UINT uiParam = sizeof(param);

	SystemParametersInfo(SPI_GETACCESSTIMEOUT, 0, &param, 0);

	cout << endl << "System Parameters:\nThe SPI_GETACCESSTIMEOUT parameter: " << uiParam << endl;// Временные интервалы

	//Системные параметры:\параметр ВРЕМЕНИ ОЖИДАНИЯ доступа SPI_GET:

	ANIMATIONINFO param2;
	param2.cbSize = sizeof(ANIMATIONINFO);
	UINT uiParam2 = sizeof(param2);
	SystemParametersInfo(SPI_GETANIMATION, 0, &param2, 0);

	cout << "The SPI_GETANIMATION parameter: " << uiParam2 << endl; //Данные об анимации
	unsigned int param3;

	SystemParametersInfo(SPI_GETBEEP, 0, &param3, 0);
	cout << "Indication of the resolution of audio signals: " << param3 << endl;

	ICONMETRICS param4;
	param4.cbSize = sizeof(ICONMETRICS);
	UINT uiParam4 = sizeof(param4);

	SystemParametersInfo(SPI_GETICONMETRICS, 0, &param4, 0);

	cout << "A flag that gives information about the characteristics of icons: " << uiParam4 << endl;

	int n[] = { COLOR_3DDKSHADOW, COLOR_3DDKSHADOW };

	COLORREF color = GetSysColor(n[0]);
	COLORREF color2 = GetSysColor(n[1]);
	unsigned long p[] = { color, color2 };

	COLORREF newcolor[] = { RGB(150, 75, 0), RGB(0, 0, 255) };

	SetSysColors(2, n, newcolor);

	cout << "The color of the shadow for the elements has been changed.\nPress any key to return to the original state.";

	_getch();

	SetSysColors(2, n, p);
	SYSTEMTIME var1, var2;
	GetLocalTime(&var1);

	GetSystemTime(&var2);

	cout << "\n\nTime information:\nLocal Time: date " << var1.wDay << "." << var1.wMonth << L"." << var1.wYear << " time " << var1.wHour << ":" << var1.wMinute

		<< "\nSystem time: "

		<< "date " << var2.wDay << "." << var2.wMonth << "." << var2.wYear << " time " << var2.wHour << ":" << var2.wMinute << endl;

	cout << "\n\n Individual task\n";

	RECT mem;

	return 0;

}