#include <iostream>
#include "systemclt.h"
using namespace std;

int main() {
	SystemCtl sctl;
	int select = 0;

	while (true) {
		sctl.ShowMenu();
		cin >> select; //接受用户选择

		switch (select) {
		case 1:  //学生身份
			sctl.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			sctl.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			sctl.LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			sctl.SystemExit();
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}