//职工管理系统类
#pragma once
#include <iostream>
#include "emp.h"

using namespace std;

class EmpManager {
public:
	EmpManager();

	~EmpManager();

	void showMenu();	//展示菜单

	void addEmp();	//增加职工信息

	void showEmp();	//显示职工信息

	void save();	//职工信息存磁盘

	int getEmpNum();	//获取员工数量

	void initEmpList(int empNum);	//初始化员工列表

	int isExist(int id);	//职工是否存在，存在返回index，不存在返回-1

	void deleteEmp();	//删除职工信息

	void searchEmp();	//查找职工信息

	void updateEmp();	//修改职工信息

	void clearEmp();	//清空所有文档

	void sort();	//按照编号排序

	bool isFileEmpty;	//文件是否为空

	int empNum;	//职工数量

	Emp** empList;	//职工列表
};