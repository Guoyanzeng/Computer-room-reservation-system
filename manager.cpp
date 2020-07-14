#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager() {

}

//�вι���
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������  ��ȡ�����ļ��� ѧ������ʦ����Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	this->initComputerRoom();
}

//ѡ��˵�
void Manager::OperMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::AddPerson() {
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName; //Ҫ�򿪵��ļ���
	string tip;      //��ʾid��
	string errorTip; //�ظ�������ʾ
	ofstream ofs;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ� ";
			errorTip = "ѧ���ظ�������������!";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "������ְ����ţ�";
			errorTip = "ְ�����ظ�������������!";
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name, pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->CheckRepeat(id, select);
		if (ret)//���ظ�
			cout << errorTip << endl;
		else
			break;
	}


	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//��ÿ��������˺�ʱ�����³�ʼ������
	this->initVector();
}


void PrintStudent(Student& s) {
	cout << "ѧ�ţ� " << s.m_Id << " ������ " << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::ShowPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			cout << "����ѧ����Ϣ���£� " << endl;
			for_each(vStu.begin(), vStu.end(), PrintStudent);
			break;
		}
		else if (select == 2) {
			cout << "������ʦ��Ϣ���£� " << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else {
			cout << "����ѡ���������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::ShowComputer() {
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "������ţ� " << it->m_ComId << " ������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::CleanFile() {
	cout << "�Ƿ�ȷ���������ԤԼ��" << endl;
	cout << "1.����" << endl;
	cout << "2.ȷ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
		return;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "����ԤԼ��ճɹ���" << endl;
	system("pause");
	system("cls");
}


//��ʼ��ѧ��/��ʦ��Ϣ
void Manager::initVector() {
	this->vStu.clear();
	this->vTea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student t_s;
	while (ifs >> t_s.m_Id && ifs >> t_s.m_Name && ifs >> t_s.m_Pwd) {
		this->vStu.push_back(t_s);
	}
	//cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t_t;
	while (ifs >> t_t.m_EmpId && ifs >> t_t.m_Name && ifs >> t_t.m_Pwd) {
		vTea.push_back(t_t);
	}
	//cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close();
}

//��ʼ��������Ϣ
void Manager::initComputerRoom() {
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

//�����ӵ�ID�Ƿ��ظ�
bool Manager::CheckRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (it->m_Id == id)
				return true;
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (it->m_EmpId == id)
				return true;
		}
	}
	return false;
}