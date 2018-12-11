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
			k = 1;
		}
	} while (k == 0);
	if (m == 1)
	{
		clearScreen();
		GotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";
		GotoXY(15, 8); white();
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
		//tmp.info();
	}
	else if (m == 2)
	{
		clearScreen();
		GotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";
		GotoXY(15, 8); white();
		cout << "�� �������������� ���: ";
		GotoXY(15, 9); yellow();
		cout << "-> �������������";
		GotoXY(15, 10); white();
		cout << "   �������";
		int st=1;
		do
		{
			k = 0;
			code = _getch();
			if (code == 224 || code == 0)
				code = _getch();
			if (code == 80)
			{
				if (st != 2) st += 1;
				else st = 1;
				if (st == 1)
				{
					yellow(); GotoXY(15, 9); cout << "-> �������������";
					white(); GotoXY(15, 10);  cout << "   �������";
				}
				else if (st == 2)
				{
					white(); GotoXY(15, 9); cout << "   �������������";
					yellow(); GotoXY(15, 10);  cout << "-> �������";
				}
			}
			else if (code == 72)
			{
				if (st != 1) st -= 1;
				else st = 2;
				if (st == 1)
				{
					yellow(); GotoXY(15, 9); cout << "-> �������������";
					white(); GotoXY(15, 10);  cout << "   �������";
				}
				else if (st == 2)
				{
					white(); GotoXY(15, 9); cout << "   �������������";
					yellow(); GotoXY(15, 10);  cout << "-> �������";
				}
			}
			else if (code == 13)
			{				
				k = 1;
			}
		} while (k == 0);
		clearScreen();
		GotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";		
		Human *N = nullptr;
		string fn, sn, pas, pas1;
		bool sex=1;
		int d, m, y;
		GotoXY(15, 8); white();
		cout << "�������: ";
		cin >> sn;
		GotoXY(15, 9); white();
		cout << "���: ";
		cin >> fn;
		GotoXY(15, 10); white();
		cout << "���: ";
		GotoXY(15, 11); yellow();
		cout << "-> �������";
		GotoXY(15, 12); white();
		cout << "   �������";
		do
		{
			k = 0;
			code = _getch();
			if (code == 224 || code == 0)
				code = _getch();
			if (code == 80)
			{
				if (sex != 1) sex += 1;
				else sex = 0;
				if (sex == 1)
				{
					yellow(); GotoXY(15, 11); cout << "-> �������";
					white(); GotoXY(15, 12);  cout << "   �������";
				}
				else if (sex == 0)
				{
					white(); GotoXY(15, 11); cout << "   �������";
					yellow(); GotoXY(15, 12);  cout << "-> �������";
				}
			}
			else if (code == 72)
			{
				if (sex != 0) sex -= 1;
				else sex = 1;
				if (sex == 1)
				{
					yellow(); GotoXY(15, 11); cout << "-> �������";
					white(); GotoXY(15, 12);  cout << "   �������";
				}
				else if (sex == 0)
				{
					white(); GotoXY(15, 11); cout << "   �������";
					yellow(); GotoXY(15, 12);  cout << "-> �������";
				}
			}
			else if (code == 13)
			{
				k = 1;
			}
		} while (k == 0);
		GotoXY(15, 13); white();
		cout << "���� ��������:";
		GotoXY(15, 14); white();
		cout << "���: "; cin >> y;
		GotoXY(15, 15); white();
		cout << "����� (�������): "; cin >> m;
		GotoXY(15, 16); white();
		cout << "����: "; cin >> d;
		GotoXY(15, 17); white();
		cout << "������� ������: "; cin >> pas;
		GotoXY(15, 18); white();
		cout << "���������: "; cin >> pas1;
		if (pas1 == pas)
		{
			GotoXY(15, 19); green();
			cout << "������ ������!";
		}
		else
		{
			GotoXY(15, 19); red();
			cout << "�� �� ����� ����� ������";
		}
		if (st == 1)
		{
			N = new Teacher();
		}
		else if (st == 2)
		{
			N = new Student();
		}
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

