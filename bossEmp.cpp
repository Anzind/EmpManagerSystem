//�ϰ�Ա����
#include "emp.h"

using namespace std;

//�ϰ��෽����ʵ��
Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾����" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}