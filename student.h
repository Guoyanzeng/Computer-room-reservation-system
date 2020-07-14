#pragma once
#include <iostream>
#include "Identity.h"
#include <vector>
#include "computerRoom.h"
#include "orderFile.h"
using namespace std;

class Student:public Identity {
public:
	//默认构造
	Student();

	//有参构造(学号、姓名、密码)
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void OperMenu();

	//申请预约
	void ApplyOrder();

	//查看我的预约
	void ShowMyOrder();

	//查看所有预约
	void ShowAllOrder();

	//取消预约
	void CancelOrder();

	void initComputerRoom();
public:
	//学生学号
	int m_Id;

	//机房容器2    
	vector<ComputerRoom> vCom;

	//预约状态
	enum { Failure = -1, Cancel, Audit, Success };
};