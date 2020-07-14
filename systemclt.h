#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class SystemCtl {
public:
	void ShowMenu();
	void SystemExit();
	void LoginIn(string fileName, int type);
	void ManagerMenu(Identity*& manager);
	void StudentMenu(Identity*& student);
	void TeacherMenu(Identity*& teacher);
};