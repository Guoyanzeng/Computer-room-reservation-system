#pragma once
#include<iostream>
using namespace std;
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"

class OrderFile {
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void UpdateOrder();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_OrderData;

public:
	//ԤԼ��¼����
	int m_Size;
};