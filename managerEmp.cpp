#include "emp.h"

using namespace std;

//�����෽����ʵ��
Manager::Manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Manager::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ��ɷ������񣬸�Ա��ָ������" << endl;
}

string Manager::getDeptName() {
	return string("����");
}