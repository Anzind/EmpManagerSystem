#include "emp.h"

using namespace std;

//普通员工类方法的实现
Normal::Normal(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Normal::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理派发的任务" << endl;
}

string Normal::getDeptName() {
	return string("普通员工");
}