//#include "Question.h"
#include <Windows.h>
#include "Test.h"
#include "Teacher.h"
#include "School.h"
#include <iterator>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Question q;
	q.setQuesText("��� ������������� ������?");
	q.addAnswerChoice("1. ���-���");
	q.addAnswerChoice("2. ���");
	q.addAnswerChoice("3. ��-���");
	q.addRightAnswers(1);
	q.addRightAnswers(3);

	Question q2;
	q2.setQuesText("��� ����� ������?");
	q2.addAnswerChoice("1. ������");
	q2.addAnswerChoice("2. �����");
	q2.addAnswerChoice("3. ������������");
	q2.addRightAnswers(2);

	Question q3;
	q3.setQuesText("��� ����� �����?");
	q3.addAnswerChoice("1. ������");
	q3.addAnswerChoice("2. �����");
	q3.addAnswerChoice("3. ������������");
	q3.addRightAnswers(1);

	Test tt("��������");
	tt.addQuestion(q);
	tt.addQuestion(q2);
	tt.addQuestion(q3);

	Test tt2("��������");
	tt2.readFromFile("3.txt");
	tt2.print();
	//tt2.writeToFile("tests\\1.txt");

	/*tt.delQuestion(3);

	cout << tt[1];

	Test tt2(456);
	tt2.addQuestion(q3);

	tt2.print();*/

	/*vector<string> vv = q.getAnswerChoice();
	vector<int> x = q.getRightAnswers();
	ostream_iterator<int> os(cout, "\n");
	copy(begin(x), end(x), os);*/

	/*Teacher t(14, "������", "��������", 0, date_(22, 5, 1983));
	t.setStatus("������");
	t.info();
	cout << t.convertToString();*/

	/*Teacher t1(14, "������", "��������", 0, date_(22, 5, 1983));
	Teacher t2(12, "�����", "����������", 0, date_(26, 5, 1983));
	Teacher t3(15, "�����", "���������", 1, date_(18, 6, 1970));

	School sh("ITSTEP");
	sh.addTeacher(t1);
	sh.addTeacher(t2);
	sh.addTeacher(t3);
	sh.delTeacher(11);
	cout << sh.getCntTeachers();*/

	//sh.getTeacher(12).info();

	/*int ch;
	int res;
	while (true) {
	res = 0;
	cout << "0 - exit, 1 - pass test\n";
	system("cls");
	cin >> ch;
	if (ch == 0) break;
	if (ch == 1) {
	for (auto i = tt.getBeginTestQuestions(); i != tt.getEndTestQuestions(); i++)
	{
	cout << tt[i->first];
	cout << "���� �������� ������� (0 - exit):\n";
	vector<int> myAnswers;
	int ans;
	while (true) {
	cin >> ans;
	if (ans == 0) break;
	myAnswers.push_back(ans);
	}
	sort(begin(myAnswers), end(myAnswers));
	if (tt[i->first].getRightAnswers() == myAnswers) res++;
	}
	cout << "���� ���������: " << res << endl;
	}
	}*/










	system("pause");
	return 0;
}