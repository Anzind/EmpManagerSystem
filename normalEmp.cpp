#include "emp.h"

using namespace std;

//��ͨԱ���෽����ʵ��
Normal::Normal(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Normal::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ����ɷ�������" << endl;
}

string Normal::getDeptName() {
	return string("��ͨԱ��");
}