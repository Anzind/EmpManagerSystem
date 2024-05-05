#pragma once
#include <iostream>

using namespace std;

class Emp {
	//职工抽象类
public:
	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

	int id;	//职工编号
	string name;	//职工姓名
	int deptId;	//职工部门编号
};

class Normal :public Emp {
	//普通员工类
public:
	Normal(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};

class Manager :public Emp {
	//经理员工类
public:
	Manager(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};

class Boss :public Emp {
	//老板员工类
public:
	Boss(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};