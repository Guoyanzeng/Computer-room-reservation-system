#pragma once
#include <iostream>
#include "identity.h"
#include "orderFile.h"
using namespace std;

class Teacher :public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void OperMenu();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//���ԤԼ
	void ValidOrder();

public:
	int m_EmpId; //��ʦ���
};