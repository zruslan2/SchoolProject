#include "Teacher.h"



Teacher::Teacher(string firstName, string surname, bool sex, date_ birthDay, string password)
	:Human(firstName, surname, sex, birthDay, password)
{
	this->status = "��������";
}

void Teacher::setIdTeacher(int idTeacher)
{
	this->idTeacher = idTeacher;
}

void Teacher::setStatus(string status)
{
	this->status = status;
}

void Teacher::addTest(Test & t)
{
	idTests.push_back(t.getIdTest());
}

void Teacher::info() const
{
	cout << "Id �������������: " << idTeacher << endl;
	Human::info();
	cout << "������: " << status << endl;
}

string Teacher::convertToString()
{
	string res = to_string(idTeacher) + ';';
	res += Human::convertToString();
	res += status + ';';
	return res;
}

void Teacher::readFromString(string & str)
{
	this->idTeacher = stoi(str.substr(0, str.find(';')));
	str = str = str.substr(str.find(';') + 1);
	Human::readFromString(str);
	this->status = str.substr(0, str.find(';'));
}
