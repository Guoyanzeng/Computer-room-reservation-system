#include "orderFile.h"

//构造函数

void SplitStr(map<string, string>& m, string str) {
	int pos = str.find(":");
	if (pos != -1) {
		string key, value;
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos - 1);
		/*cout << "key = " << key << endl;
		cout << "value = " << value << endl;*/
		m.insert(make_pair(key, value));
	}
}

OrderFile::OrderFile() {

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

	map<string, string> t_m;
	while (ifs >> date && ifs >> interval && ifs >> stuId &&
		ifs >> stuName && ifs >> roomId && ifs >> status) {
		//测试代码
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/


		//截取日期
		SplitStr(t_m, date);

		//截取时间段
		SplitStr(t_m, interval);

		//截取学生编号
		SplitStr(t_m, stuId);

		//截取学生姓名
		SplitStr(t_m, stuName);

		//截取机房编号
		SplitStr(t_m, roomId);

		//截取预约状态
		SplitStr(t_m, status);

		this->m_OrderData.insert(make_pair(this->m_Size, t_m));
		this->m_Size++;
		t_m.clear();
	}
	ifs.close();
	//测试代码
	/*for (map<int, map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++) {
		cout << "key = " << it->first << " value = "  << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << mit->first << " " << mit->second << " ";
		}
		cout << endl;
	}*/
}

//更新预约记录
void OrderFile::UpdateOrder() {
	if (this->m_Size == 0){
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++){
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}

	ofs.close();
}
