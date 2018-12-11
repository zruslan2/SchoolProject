#include "Viewer.h"

Viewer::Viewer():sch("ITStep")
{
}

void Viewer::LogIn()
{
	clearScreen();
	GotoXY(15, 5);
	green();
	cout << "����� ���������� � ITStep!";
	GotoXY(15, 8);
	yellow();
	cout << "-> �����";
	white();
	GotoXY(15, 9);
	cout << "   �����������������";
	int r, m = 1, k, code;
	do
	{
		k = 0;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		if (code == 80)
		{
			if (m != 2) m += 1;
			else m = 1;
			if (m == 1)
			{
				yellow(); GotoXY(15, 8); printf("-> �����");
				white(); GotoXY(15, 9);  printf("   �����������������");
			}
			else if (m == 2)
			{
				white(); GotoXY(15, 8); printf("   �����");
				yellow(); GotoXY(15, 9);  printf("-> �����������������");
			}
		}
		else if (code == 72)
		{
			if (m != 1) m -= 1;
			else m = 2;
			if (m == 1)
			{
				yellow(); GotoXY(15, 8); printf("-> �����");
				white(); GotoXY(15, 9);  printf("   �����������������");
			}
			else if (m == 2)
			{
				white(); GotoXY(15, 8); printf("   �����");
				yellow(); GotoXY(15, 9);  printf("-> �����������������");
			}
		}
		else if (code == 13)
		{
			//return m;
			k = 1;
		}
	} while (k == 0);
	if (m == 1)
	{
		clearScreen();
		GotoXY(15, 5);
		green();
		cout << "����� ���������� � ITStep!";
		GotoXY(15, 8);
		white();
		string l, p;
		cout << "�������: ";
		GotoXY(24, 8);
		cin >> l;
		GotoXY(15, 9);
		cout << "������: ";
		GotoXY(24, 9);
		do
		{
			//k = 0;
			code = _getch();
			cout << "*";
			p += code;
			if (code == 13)
				{
					k = 0;
				}
		} while (k == 1);
		sch.readStudentsFromFile("1.txt");
		Student tmp=sch.getStudent(l);
		tmp.info();
	}
}

void Viewer::yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void Viewer::white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void Viewer::red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void Viewer::green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

void Viewer::GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}

