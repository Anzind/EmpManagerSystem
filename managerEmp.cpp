#include "emp.h"

using namespace std;

//经理类方法的实现
Manager::Manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void Manager::showInfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板派发的任务，给员工指派任务" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}