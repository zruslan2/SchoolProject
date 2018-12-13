#include "Viewer.h"

Viewer::Viewer():sch("ITStep")
{
}

void Viewer::LogIn()
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "Добро пожаловать в ITStep!";
	gotoXY(15, 8);
	yellow();
	cout << "-> Войти";
	white();
	gotoXY(15, 9);
	cout << "   Зарегистрироватся";
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
				yellow(); gotoXY(15, 8); printf("-> Войти");
				white(); gotoXY(15, 9);  printf("   Зарегистрироватся");
			}
			else if (m == 2)
			{
				white(); gotoXY(15, 8); printf("   Войти");
				yellow(); gotoXY(15, 9);  printf("-> Зарегистрироватся");
			}
		}
		else if (code == 72)
		{
			if (m != 1) m -= 1;
			else m = 2;
			if (m == 1)
			{
				yellow(); gotoXY(15, 8); printf("-> Войти");
				white(); gotoXY(15, 9);  printf("   Зарегистрироватся");
			}
			else if (m == 2)
			{
				white(); gotoXY(15, 8); printf("   Войти");
				yellow(); gotoXY(15, 9);  printf("-> Зарегистрироватся");
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
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		gotoXY(15, 8); white();
		string l, p;
		cout << "Фамилия: ";
		gotoXY(24, 8);
		cin >> l;
		gotoXY(15, 9);
		cout << "Пароль: ";
		gotoXY(24, 9);
		p = pasEntry();
		sch.readStudentsFromFile();
		sch.readTeachersFromFile();
		//Student tmp=sch.getStudent(l);
		//Teacher tmp1 = sch.getTeacher(l);
		//gotoXY(15, 12);
		//tmp.info();
		//tmp1.info();
		//tmp.info();
	}
	else if (m == 2)
	{
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";
		gotoXY(15, 8); white();
		cout << "Вы регистриретесь как: ";
		gotoXY(15, 9); yellow();
		cout << "-> Преподователь";
		gotoXY(15, 10); white();
		cout << "   Студент";
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
					yellow(); gotoXY(15, 9); cout << "-> Преподователь";
					white(); gotoXY(15, 10);  cout << "   Студент";
				}
				else if (st == 2)
				{
					white(); gotoXY(15, 9); cout << "   Преподователь";
					yellow(); gotoXY(15, 10);  cout << "-> Студент";
				}
			}
			else if (code == 72)
			{
				if (st != 1) st -= 1;
				else st = 2;
				if (st == 1)
				{
					yellow(); gotoXY(15, 9); cout << "-> Преподователь";
					white(); gotoXY(15, 10);  cout << "   Студент";
				}
				else if (st == 2)
				{
					white(); gotoXY(15, 9); cout << "   Преподователь";
					yellow(); gotoXY(15, 10);  cout << "-> Студент";
				}
			}
			else if (code == 13)
			{				
				k = 1;
			}
		} while (k == 0);
		clearScreen();
		gotoXY(15, 5); green();
		cout << "Добро пожаловать в ITStep!";		
		Human *N = nullptr;
		string fn, sn, pas, pas1;
		bool sex=1;
		int d, m, y;
		gotoXY(15, 8); white();
		cout << "Фамилия: ";
		gotoXY(32, 8); cin >> sn;
		gotoXY(15, 9); white();
		cout << "Имя: ";
		gotoXY(32, 9); cin >> fn;
		gotoXY(15, 10); white();
		cout << "Пол: ";
		gotoXY(15, 11); yellow();
		cout << "-> Мужской";
		gotoXY(15, 12); white();
		cout << "   Женский";
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
					yellow(); gotoXY(15, 11); cout << "-> Мужской";
					white(); gotoXY(15, 12);  cout << "   Женский";
				}
				else if (sex == 0)
				{
					white(); gotoXY(15, 11); cout << "   Мужской";
					yellow(); gotoXY(15, 12);  cout << "-> Женский";
				}
			}
			else if (code == 72)
			{
				if (sex != 0) sex -= 1;
				else sex = 1;
				if (sex == 1)
				{
					yellow(); gotoXY(15, 11); cout << "-> Мужской";
					white(); gotoXY(15, 12);  cout << "   Женский";
				}
				else if (sex == 0)
				{
					white(); gotoXY(15, 11); cout << "   Мужской";
					yellow(); gotoXY(15, 12);  cout << "-> Женский";
				}
			}
			else if (code == 13)
			{
				k = 1;
			}
		} while (k == 0);
		gotoXY(15, 13); white();
		cout << "Дата рождения:";
		gotoXY(15, 14); white();
		cout << "Год: "; 
		gotoXY(32, 14);
		y = intEntry(4,false);		
		gotoXY(15, 15); white();
		cout << "Месяц (цифрами): ";
		gotoXY(32, 15);
		m = intEntry(2, true);
		if (m > 12)m = 12;
		gotoXY(15, 16); white();
		cout << "День: ";
		gotoXY(32, 16);
		d = intEntry(2, true);
		do
		{
			k = 0;
			gotoXY(15, 17); white();
			cout << "                                                                ";
			gotoXY(15, 18); white();
			cout << "                                                                ";
			gotoXY(15, 19); white();
			cout << "                                                                ";
			gotoXY(15, 17); white();
			cout << "*Введите пароль: "; 
			gotoXY(15, 21); white();
			cout << "*Нажмите Tab для просмотра/скрытия пароля";
			gotoXY(32, 17); white();
			pas=pasEntry();
			gotoXY(15, 18); white();
			cout << "*Повторите: "; 
			gotoXY(32, 18); white();
			pas1= pasEntry();
			if (pas1 == pas)
			{
				gotoXY(15, 19); green();
				cout << "Пароль принят!";
				k = 1;
			}
			else
			{
				gotoXY(15, 19); red();
				cout << "Вы не верно ввели пароль";
				Sleep(1000);
			}
		} while (k == 0);
		
		if (st == 1)
		{
			Teacher t;
			t.setFirstName(fn);
			t.setSurname(sn);
			t.setBirthDay(d, m, y);
			t.setSex(sex);
			t.setPassword(pas);
			t.setStatus(sch.getTeacherStatus().operator[](0));
			sch.readTeachersFromFile();
			sch.addTeacher(t);				
			sch.writeTeachersToFile();
		}
		else if (st == 2)
		{
			Student s;
			s.setFirstName(fn);
			s.setSurname(sn);
			s.setBirthDay(d, m, y);
			s.setSex(sex);
			s.setPassword(pas);
			s.setStatus(sch.getStudentStatus().operator[](0));
			sch.readStudentsFromFile();
			sch.addStudent(s);				
			sch.writeStudentsToFile();			
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

void Viewer::gotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}

COORD Viewer::getPos()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD coord;

	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		coord.X = csbi.dwCursorPosition.X;
		coord.Y = csbi.dwCursorPosition.Y;
		return coord;
	}
	else
	{
		coord.X = 0;
		coord.Y = 0;
		return coord;
	}
}

string Viewer::pasEntry()
{
	string str;
	COORD c;
	bool fl=false;
	int code, k;
	do
	{
		k = 1;
		code = _getch();		
		if (code == 8)
		{
			c = getPos();
			gotoXY(c.X - 1, c.Y);
			cout << " ";
			gotoXY(c.X - 1, c.Y);
			str.pop_back();
		}
		if (code == 9)
		{
			if (fl == false)
				fl = true;
			else
			{
				fl = false;
			}
		}			
		if (code != 13&& code!=9&&code!=8)
		{
			if (fl == false)
			{
				c = getPos();
				gotoXY(c.X - str.size(), c.Y);
				for(int i=0;i<str.size();i++)
					cout << "*";
				cout << "*";
			}				
			else
			{
				c = getPos();
				gotoXY(c.X - str.size(), c.Y);
				cout << str;
				cout << (char)code;
			}
			str += code;
		}			
		if (code == 13)
		{
			k = 0;
		}
	} while (k == 1);
	return str;
}

int Viewer::intEntry(int c, bool e)
{
	int code, rs;
	string is;
	for (int i = 0; i < c; i++)
	{
		code = _getch();
		if (code == 13 && e == true)
		{
			break;
		}
		else if (code < 48 || code > 57 && code!= 13)
		{
			code = _getch();
			i--;
		}
		else if (code >= 48 || code <= 57 && code != 13)
		{
			is += code;
			cout << (char)code;
		}
	}
	rs = stoi(is);
	return rs;
}
