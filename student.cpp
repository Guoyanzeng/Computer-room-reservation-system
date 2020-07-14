#include "student.h"

//Ĭ�Ϲ���
Student::Student() {

}

//�вι���(ѧ�š�����������)
Student::Student(int id, string name, string pwd) {

	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	this->initComputerRoom();
}

//�˵�����
void Student::OperMenu() {
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//����ԤԼ
void Student::ApplyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0; //����
	int interval = 0; //ʱ���
	int room = 0; //�������

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;

		cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;

		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "�Ż���������" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3)
			break;

		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << Audit << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::ShowMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "ԤԼ���ڣ� ��" << of.m_OrderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_OrderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_OrderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "-1") {
				status += "���δͨ����ԤԼʧ��";
			}
			else {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::ShowAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << of.m_OrderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_OrderData[i]["stuId"];
		cout << " ������" << of.m_OrderData[i]["stuName"];
		cout << " ������" << of.m_OrderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_OrderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "-1") {
			status += "���δͨ����ԤԼʧ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::CancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	map<int, int> comparison;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2") {
				comparison.insert(make_pair(index, i));
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_OrderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_OrderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_OrderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_OrderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= index) {
			if (select == 0)
				break;
			else {
				of.m_OrderData[comparison[select]]["status"] = "0";
				of.UpdateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
	comparison.clear();
}

void Student::initComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "��������Ϊ��" << vCom.size() << endl;
}