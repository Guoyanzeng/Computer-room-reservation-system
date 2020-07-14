#include "systemclt.h"

void SystemCtl::ShowMenu() {
	cout << "======================  ��ӭ����510����ԤԼϵͳ  =====================" << endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

void SystemCtl::SystemExit() {
	cout << "��ӭ��һ��ʹ��" << endl;
	system("pause");
	exit(0);
}

void SystemCtl::LoginIn(string fileName, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name, pwd;
	if (type == 1) {
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ����¼��֤
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				this->StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��¼��֤
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			/*cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;*/
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ����Ӳ˵�
				this->TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

void SystemCtl::ManagerMenu(Identity*& manager) {
	while (true) {
		manager->OperMenu();

		Manager* man = dynamic_cast<Manager*>(manager);

		int select = 0;
		cin >> select;
		if (select == 1) {  //����˺�
			man->AddPerson();
		}
		else if (select == 2) { //�鿴�˺�
			man->ShowPerson();
		}
		else if (select == 3) { //�鿴����
			man->ShowComputer();
		}
		else if (select == 4) { //���ԤԼ
			man->CleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void SystemCtl::StudentMenu(Identity*& student) {
	while (true) {
		student->OperMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1: //����ԤԼ
			stu->ApplyOrder();
			break;
		case 2://�鿴����ԤԼ
			stu->ShowMyOrder();
			break;
		case 3: //�鿴����ԤԼ
			stu->ShowAllOrder();
			break;
		case 4://ȡ��ԤԼ
			stu->CancelOrder();
			break;
		case 0: {
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}

void SystemCtl::TeacherMenu(Identity*& teacher) {
	while (true) {
		teacher->OperMenu();
		Teacher* tea = dynamic_cast<Teacher*>(teacher);
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			tea->ShowAllOrder();
			break;
		case 2:
			tea->ValidOrder();
			break;
		case 0: {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}