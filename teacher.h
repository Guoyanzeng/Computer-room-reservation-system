#pragma once
#include <iostream>
#include "identity.h"
#include "orderFile.h"
using namespace std;

class Teacher :public Identity {
public:
	//默认构造
	Teacher();

	//有参构造 (职工编号，姓名，密码)
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void OperMenu();

	//查看所有预约
	void ShowAllOrder();

	//审核预约
	void ValidOrder();

public:
	int m_EmpId; //教师编号
};