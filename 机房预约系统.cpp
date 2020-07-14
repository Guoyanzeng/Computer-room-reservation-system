#include <iostream>
#include "systemclt.h"
using namespace std;

int main() {
	SystemCtl sctl;
	int select = 0;

	while (true) {
		sctl.ShowMenu();
		cin >> select; //�����û�ѡ��

		switch (select) {
		case 1:  //ѧ�����
			sctl.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			sctl.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			sctl.LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			sctl.SystemExit();
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}