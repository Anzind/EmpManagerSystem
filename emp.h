#pragma once
#include <iostream>

using namespace std;

class Emp {
	//ְ��������
public:
	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

	int id;	//ְ�����
	string name;	//ְ������
	int deptId;	//ְ�����ű��
};

class Normal :public Emp {
	//��ͨԱ����
public:
	Normal(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};

class Manager :public Emp {
	//����Ա����
public:
	Manager(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};

class Boss :public Emp {
	//�ϰ�Ա����
public:
	Boss(int id, string name, int deptId);

	virtual void showInfo();

	virtual string getDeptName();
};