#pragma once
#include <iostream>
#include "Identity.h"
#include <vector>
#include "computerRoom.h"
#include "orderFile.h"
using namespace std;

class Student:public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���(ѧ�š�����������)
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void OperMenu();

	//����ԤԼ
	void ApplyOrder();

	//�鿴�ҵ�ԤԼ
	void ShowMyOrder();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	void initComputerRoom();
public:
	//ѧ��ѧ��
	int m_Id;

	//��������2    
	vector<ComputerRoom> vCom;

	//ԤԼ״̬
	enum { Failure = -1, Cancel, Audit, Success };
};