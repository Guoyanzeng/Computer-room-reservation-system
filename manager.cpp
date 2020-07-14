#include "manager.h"

//默认构造
Manager::Manager() {

}

//有参构造
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器  获取所有文件中 学生、老师的信息
	this->initVector();

	//初始化机房信息
	this->initComputerRoom();
}

//选择菜单
void Manager::OperMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号  
void Manager::AddPerson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName; //要打开的文件名
	string tip;      //提示id号
	string errorTip; //重复错误提示
	ofstream ofs;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "请输入学号： ";
			errorTip = "学号重复，请重新输入!";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入职工编号：";
			errorTip = "职工号重复，请重新输入!";
			break;
		}
		else {
			cout << "输入有误请重新输入" << endl;
		}
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name, pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->CheckRepeat(id, select);
		if (ret)//有重复
			cout << errorTip << endl;
		else
			break;
	}


	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//在每次添加新账号时，重新初始化容器
	this->initVector();
}


void PrintStudent(Student& s) {
	cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::ShowPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;
	while (true) {
		cin >> select;
		if (select == 1) {
			cout << "所有学生信息如下： " << endl;
			for_each(vStu.begin(), vStu.end(), PrintStudent);
			break;
		}
		else if (select == 2) {
			cout << "所有老师信息如下： " << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else {
			cout << "输入选择有误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::ShowComputer() {
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::CleanFile() {
	cout << "是否确认清空所有预约？" << endl;
	cout << "1.返回" << endl;
	cout << "2.确认" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
		return;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "所有预约清空成功！" << endl;
	system("pause");
	system("cls");
}


//初始化学生/教师信息
void Manager::initVector() {
	this->vStu.clear();
	this->vTea.clear();

	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Student t_s;
	while (ifs >> t_s.m_Id && ifs >> t_s.m_Name && ifs >> t_s.m_Pwd) {
		this->vStu.push_back(t_s);
	}
	//cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t_t;
	while (ifs >> t_t.m_EmpId && ifs >> t_t.m_Name && ifs >> t_t.m_Pwd) {
		vTea.push_back(t_t);
	}
	//cout << "当前教师数量为： " << vTea.size() << endl;
	ifs.close();
}

//初始化机房信息
void Manager::initComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "机房数量为：" << vCom.size() << endl;
}

//检查添加的ID是否重复
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