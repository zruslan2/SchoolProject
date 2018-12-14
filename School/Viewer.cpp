#include "Viewer.h"

Viewer::Viewer():sch("ITStep")
{

}

void Viewer::LogIn()
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "����� ���������� � ITStep!";
	gotoXY(15, 8);
	vector<string> st1 = { "�����", "�����������������" };
	int m = 1, k;
	m = choice(st1, 15, 8);	
	if (m == 1)
	{
		clearScreen();
		gotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";
		vector<string> st = { "�������������", "�������", "�������������" };
		int v = choice(st, 15, 8);
		string l, p;
		if (v == 3)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "����� ���������� � ITStep!";
			gotoXY(15, 8); white();			
			cout << "�������: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "������: ";
			gotoXY(24, 9);
			p = pasEntry();
			if (l == "�������������"&&p == "111")
			{
				menuA();
			}
			else
			{
				gotoXY(15, 10); red();
				cout << "������� ��� ������ �� �����" << endl;
				Sleep(2000);
				LogIn();
			}
		}
		else if (v == 1)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "����� ���������� � ITStep!";
			gotoXY(15, 8); white();
			cout << "�������: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "������: ";
			gotoXY(24, 9);
			p = pasEntry();
			sch.readTeachersFromFile();
			try
			{
				Teacher tmp1 = sch.getTeacher(l);
				if (tmp1.getPassword() == p)
				{
					menuT(tmp1.getIdTeacher());
					//return tmp1.getIdTeacher();
				}
			}
			catch (...)
			{
				gotoXY(15, 10); red();
				cout << "������������� �� ������" << endl;
				Sleep(2000);
				LogIn();
			}
		}
		else if (v == 2)
		{
			clearScreen();
			gotoXY(15, 5); green();
			cout << "����� ���������� � ITStep!";
			gotoXY(15, 8); white();
			cout << "�������: ";
			gotoXY(24, 8);
			cin >> l;
			gotoXY(15, 9);
			cout << "������: ";
			gotoXY(24, 9);
			p = pasEntry();
			sch.readStudentsFromFile();
			try
			{
				Student tmp = sch.getStudent(l);
				if (tmp.getPassword() == p)
				{
					menuS(tmp.getIdStudent());
					//return tmp.getIdStudent();
				}
			}
			catch (...)
			{
				gotoXY(15, 10); red();
				cout << "C������ �� ������" << endl;
				Sleep(2000);
				LogIn();
			}			
		}		
	}
	else if (m == 2)
	{
		clearScreen();
		gotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";
		gotoXY(15, 8); white();
		cout << "�� �������������� ���: ";
		gotoXY(15, 9); yellow();
		int st = 1;
		vector<string> st2 = { "�������������", "�������" };
		st = choice(st2, 15, 9);		
		clearScreen();
		gotoXY(15, 5); green();
		cout << "����� ���������� � ITStep!";			
		string fn, sn, pas, pas1;
		bool sex=1;
		int d, m, y;
		gotoXY(15, 8); white();
		cout << "�������: ";
		gotoXY(32, 8); cin >> sn;
		gotoXY(15, 9); white();
		cout << "���: ";
		gotoXY(32, 9); cin >> fn;
		gotoXY(15, 10); white();
		cout << "���: ";
		vector<string> st3 = { "�������", "�������" };
		int s = choice(st3, 15, 11);
		sex = s - 1;
		gotoXY(15, 13); white();
		cout << "���� ��������:";
		gotoXY(15, 14); white();
		cout << "���: "; 
		gotoXY(32, 14);
		y = intEntry(4,false);		
		gotoXY(15, 15); white();
		cout << "����� (�������): ";
		gotoXY(32, 15);
		m = intEntry(2, true);
		if (m > 12)m = 12;
		gotoXY(15, 16); white();
		cout << "����: ";
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
			cout << "*������� ������: "; 
			gotoXY(15, 21); white();
			cout << "*������� Tab ��� ���������/������� ������";
			gotoXY(32, 17); white();
			pas=pasEntry();
			gotoXY(15, 18); white();
			cout << "*���������: "; 
			gotoXY(32, 18); white();
			pas1= pasEntry();
			if (pas1 == pas)
			{
				gotoXY(15, 19); green();
				cout << "������ ������!";
				k = 1;
			}
			else
			{
				gotoXY(15, 19); red();
				cout << "�� �� ����� ����� ������";
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

int Viewer::choice(vector<string> ch, int x, int y)
{
	int choice=1, x1=x, y1=y, k, code;
	x1 = x; y1 = y;
	for (int i = 1; i <= ch.size(); i++)
	{
		gotoXY(x1, y1);
		if (i == choice)
		{
			yellow();
			cout << "-> " + ch[i - 1];
		}
		else
		{
			white();
			cout << "   " + ch[i - 1];
		}
		y1++;
	}
	do
	{
		k = 1;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		if (code == 80)
		{
			if (choice != ch.size()) choice += 1;
			else choice = 1;
			x1 = x; y1 = y;
			for (int i = 1; i <= ch.size(); i++)
			{
				gotoXY(x1, y1);
				if (i == choice)
				{
					yellow();
					cout << "-> " + ch[i - 1];
				}
				else
				{
					white();
					cout << "   " + ch[i - 1];
				}
				y1++;
			}
		}
		else if (code == 72)
		{
			if (choice != 1) choice -= 1;
			else choice = ch.size();
			x1 = x; y1 = y;
			for (int i = 1; i <= ch.size(); i++)
			{
				gotoXY(x1, y1);
				if (i == choice)
				{
					yellow();
					cout << "-> " + ch[i - 1];
				}
				else
				{
					white();
					cout << "   " + ch[i - 1];
				}
				y1++;
			}
		}
		else if (code == 13)
		{
			k = 1;
			return choice;
		}
	} while (k == 1);	
}

void Viewer::menuA()
{
	clearScreen();
	cout << "Admin";
}

void Viewer::menuT(int id)
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "����� ���������� � ITStep!";
	gotoXY(15, 8);
	vector<string> st1 = { "�������� ����", "������ ������", "������ ���������", "�����" };
	int m = 1;
	m = choice(st1, 15, 8);
	if (m == 4)
	{
		LogIn();
	}
	else if (m == 1)
	{
		addTest(id);
	}
	else if (m == 2)
	{

	}
	else if (m == 3)
	{

	}
}

void Viewer::menuS(int id)
{
	clearScreen();
	gotoXY(15, 5);
	green();
	cout << "����� ���������� � ITStep!";
	gotoXY(15, 8);
	vector<string> st1 = { "������ ����", "���������� �����", "�����" };
	int m = 1;
	m = choice(st1, 15, 8);
	if (m == 3)
	{
		LogIn();
	}
	else if (m == 1)
	{
		clearScreen();
		gotoXY(15, 5);
		green();
		cout << "����� ���������� � ITStep!";
		gotoXY(15, 8); white();		
		sch.readListTestsFromFile();
		vector<string> lt;
		for (auto i : sch.getListTests())
		{
			lt.push_back(i.getTestName());
		}
		int ti = choice(lt, 15, 8);
		Test t;
		t.readFromFile(ti);
		clearScreen();
		gotoXY(15, 5);
		green();
		cout << t.operator[](1).getQuesText()<<endl;
		gotoXY(15, 8); white();		
		const vector<string> ans = t.operator[](1).getAnswerChoice();
		int i = choice(ans, 15, 8);
		
		//ans = t.operator[](1).getAnswer();
	}
	else if (m == 2)
	{

	}

}

void Viewer::addTest(int id) //++
{
	clearScreen();
	gotoXY(15, 5); green();
	cout << "���������� ������ �����!";
	gotoXY(15, 8); white();
	string nameTest;
	cout << "���� �����:";
	gotoXY(32, 8);
	cin.get();
	getline(cin, nameTest);
	Test t(nameTest);
	cout << t.getIdTest();
	Sleep(4000);
	t.setIdCreator(id);
	int cnt = 1;
	while (true)
	{
		while (cnt < 3)
		{
			addQuesToTest(t);
			cnt++;
		}
		clearScreen();
		gotoXY(15, 8); white();
		cout << "�������� ��� ������?";
		vector<string> v = { "��", "���" };
		int s = choice(v, 15, 9);
		if (s == 2)
			break;
		if (s == 1)
		{
			addQuesToTest(t);
		}
	}
	int x = sch.getCntListTests();
	t.setIdTest(++x);
	t.setTestMaxResult(t.sumRightAnswers());
	clearScreen();
	gotoXY(15, 5); green();
	cout << "���� ������!";
	gotoXY(15, 8); white();
	cout << "��������� ���� � ����?";
	vector<string> v = { "��","���" };
	int s = choice(v, 15, 9);
	if (s == 1)
	{
		//string name = "tests\\" + to_string(t.getIdTest());
		t.writeToFile();
	}
	ListTests lt(t.getIdTest(), t.getTestName(), t.getIdCreator());
	sch.addListTests(lt);
}

void Viewer::addQuesToTest(Test& t) //++
{
	clearScreen();
	gotoXY(15, 5);
	cout << "���������� ������ �������!";
	gotoXY(15, 8); white();
	string quesText;
	cout << "�������� ������:";
	gotoXY(32, 8);
	cin.get();
	getline(cin, quesText);
	Question q(quesText);	
	int k = 1;
	while (true)
	{
		while (k < 3)
		{
			addAnswers(q, k);
			k++;
		}
		clearScreen();
		gotoXY(15, 8); white();
		cout << "�������� ��� ������� ������?";
		vector<string> v = { "��", "���" };
		int s = choice(v, 15, 9);
		if (s == 2) {
			if (q.getCntRightAnswers() != 0)
				break;
			else
			{
				clearScreen();
				gotoXY(15, 8);
				cout << "�� �� �������� �� ������ ����������� ������. ������� ������";
				k = 1;
				Sleep(1000);
				continue;
			}
		}
		if (s == 1)
		{
			addAnswers(q, k);
			k++;
		}
	}
	t.addQuestion(q);
}

void Viewer::addAnswers(Question & q, int quesNum) //++
{
	string answer;
	clearScreen();
	gotoXY(15, 8); white();
	cout << "������� ������:";
	gotoXY(32, 8);
	cin.get();
	getline(cin, answer);
	gotoXY(15, 9);
	cout << "�������� �� ���� ������� ������ ����������?";
	vector<string> vs = { "��","���" };
	int ss = choice(vs, 15, 10);
	if (ss == 1)
		q.addRightAnswers(quesNum);
	q.addAnswerChoice(answer);
}