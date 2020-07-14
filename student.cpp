#include "student.h"

//默认构造
Student::Student() {

}

//有参构造(学号、姓名、密码)
Student::Student(int id, string name, string pwd) {

	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	this->initComputerRoom();
}

//菜单界面
void Student::OperMenu() {
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： ";
}

//申请预约
void Student::ApplyOrder() {
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0; //日期
	int interval = 0; //时间段
	int room = 0; //机房编号

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;

		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;

		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "号机房容量：" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3)
			break;

		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;
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

//查看我的预约
void Student::ShowMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "预约日期： 周" << of.m_OrderData[i]["date"];
			cout << " 时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_OrderData[i]["roomId"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (of.m_OrderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_OrderData[i]["status"] == "-1") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Student::ShowAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "、 ";

		cout << "预约日期： 周" << of.m_OrderData[i]["date"];
		cout << " 时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_OrderData[i]["stuId"];
		cout << " 姓名：" << of.m_OrderData[i]["stuName"];
		cout << " 机房：" << of.m_OrderData[i]["roomId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_OrderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "-1") {
			status += "审核未通过，预约失败";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//取消预约
void Student::CancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;
	map<int, int> comparison;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2") {
				comparison.insert(make_pair(index, i));
				cout << index++ << "、 ";
				cout << "预约日期： 周" << of.m_OrderData[i]["date"];
				cout << " 时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_OrderData[i]["roomId"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (of.m_OrderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_OrderData[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= index) {
			if (select == 0)
				break;
			else {
				of.m_OrderData[comparison[select]]["status"] = "0";
				of.UpdateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
	comparison.clear();
}

void Student::initComputerRoom() {
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