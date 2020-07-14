#pragma once
#include<iostream>
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <algorithm>
using namespace std;

class Manager :public Identity {
public:
	//默认构造
	Manager();

	//有参构造  管理员姓名，密码
	Manager(string name, string pwd);

	//选择菜单
	virtual void OperMenu();

	//添加账号  
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房信息
	void ShowComputer();

	//清空预约记录
	void CleanFile();

	//初始化容器
	void initVector();

	//初始化机房信息
	void initComputerRoom();

	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool CheckRepeat(int id, int type);

public:
	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};