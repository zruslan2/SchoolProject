#pragma once

class Tester
{
	int idStudent;
	int idTest;
	int testResult;
public:
	Tester(int idStudent = 0, int idTest = 0, int testResult = 0);
	void setIdStudent(int idStudent);
	void setIdTest(int idTest);
	void setTestResult(int res);
};

