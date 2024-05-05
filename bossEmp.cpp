//老板员工类
#include "emp.h"

using namespace std;

//老板类方法的实现
Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Boss::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司事务" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}