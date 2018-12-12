#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Tester.h"
#include "ListTests.h"
#include <fstream>
class School
{
	string schoolName;
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Tester> testers; //++
	vector<ListTests> listTests; //++
	vector<string> studentStatus = { "����������", "�������", "���������" }; //++
	vector<string> teacherStatus = { "��������", "�� ��������" }; //++
public:
	School(string schoolName);

	void setSchoolName(string schoolName);
	string getSchoolName()const { return schoolName; }

	void addStudent(Student& st);
	void delStudent(int idStudent);
	void addTeacher(Teacher& t);
	void delTeacher(int idTeacher);
	void addTester(Tester& t); //++
	void addListTests(ListTests& lt); //++
	const vector<Student>& getStudentsList()const { return students; }
	const vector<Teacher>& getTeachersList()const { return teachers; }
	const Student& getStudent(int idStudent)const;
	const Student& getStudent(string surname)const;
	const Teacher& getTeacher(int idTeacher) const;
	const Teacher& getTeacher(string surname) const;
	int getCntStudents()const { return students.size(); }
	int getCntTeachers()const { return teachers.size(); }
	const vector<string>& getStudentStatus()const { return studentStatus; } //++
	const vector<string>& getTeacherStatus()const { return teacherStatus; } //++

	void writeStudentsToFile(); //++
	void writeTeachersToFile(); //++
	void writeTestersToFile(); //++
	void writeListTestsToFile(); //++

	void readStudentsFromFile(); //++
	void readTeachersFromFile(); //++
	void readTestersFromFile(); //++
	void readListTestsFromFile(); //++
};