#include "orderFile.h"

//���캯��

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

	string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

	map<string, string> t_m;
	while (ifs >> date && ifs >> interval && ifs >> stuId &&
		ifs >> stuName && ifs >> roomId && ifs >> status) {
		//���Դ���
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/


		//��ȡ����
		SplitStr(t_m, date);

		//��ȡʱ���
		SplitStr(t_m, interval);

		//��ȡѧ�����
		SplitStr(t_m, stuId);

		//��ȡѧ������
		SplitStr(t_m, stuName);

		//��ȡ�������
		SplitStr(t_m, roomId);

		//��ȡԤԼ״̬
		SplitStr(t_m, status);

		this->m_OrderData.insert(make_pair(this->m_Size, t_m));
		this->m_Size++;
		t_m.clear();
	}
	ifs.close();
	//���Դ���
	/*for (map<int, map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++) {
		cout << "key = " << it->first << " value = "  << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << mit->first << " " << mit->second << " ";
		}
		cout << endl;
	}*/
}

//����ԤԼ��¼
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
