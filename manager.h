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
	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void OperMenu();

	//����˺�  
	void AddPerson();

	//�鿴�˺�
	void ShowPerson();

	//�鿴������Ϣ
	void ShowComputer();

	//���ԤԼ��¼
	void CleanFile();

	//��ʼ������
	void initVector();

	//��ʼ��������Ϣ
	void initComputerRoom();

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool CheckRepeat(int id, int type);

public:
	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};