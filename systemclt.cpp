#include "systemclt.h"

void SystemCtl::ShowMenu() {
	cout << "======================  欢迎来到510机房预约系统  =====================" << endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
}

void SystemCtl::SystemExit() {
	cout << "欢迎下一次使用" << endl;
	system("pause");
	exit(0);
}

void SystemCtl::LoginIn(string fileName, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name, pwd;
	if (type == 1) {
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	if (type == 1) {
		//学生登录验证
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				this->StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师登录验证
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			/*cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;*/
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "老师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师身份子菜单
				this->TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败!" << endl;

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
		if (select == 1) {  //添加账号
			man->AddPerson();
		}
		else if (select == 2) { //查看账号
			man->ShowPerson();
		}
		else if (select == 3) { //查看机房
			man->ShowComputer();
		}
		else if (select == 4) { //清空预约
			man->CleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
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
		case 1: //申请预约
			stu->ApplyOrder();
			break;
		case 2://查看自身预约
			stu->ShowMyOrder();
			break;
		case 3: //查看所有预约
			stu->ShowAllOrder();
			break;
		case 4://取消预约
			stu->CancelOrder();
			break;
		case 0: {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "输入有误，请重新输入" << endl;
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}