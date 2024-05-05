//职工管理系统类实现
#include <fstream>
#include "empManager.h"

const string fileName = "empFile.txt";

EmpManager::EmpManager() {
	fstream f1;
	f1.open(fileName, ios::in);

	if (!f1.is_open()) {
		//若文件不存在
		//cout << "文件不存在" << endl;
		this->empNum = 0;
		this->empList = NULL;
		this->isFileEmpty = true;
		f1.close();
		return;
	}

	char ch;
	f1 >> ch;
	if (f1.eof()) {
		//若文件为空
		//cout << "文件为空" << endl;
		this->empNum = 0;
		this->empList = NULL;
		this->isFileEmpty = true;
		f1.close();
		return;
	}

	this->empNum = this->getEmpNum();

	initEmpList(this->empNum);
}

EmpManager::~EmpManager() {
	if (this->empList != NULL) {
		delete[] this->empList;
		this->empList = NULL;
	}
}

void EmpManager::showMenu() {
	//展示菜单
	cout << "**************************" << endl;
	cout << "***** 1.增加职工信息 *****" << endl;
	cout << "***** 2.显示职工信息 *****" << endl;
	cout << "***** 3.删除职工信息 *****" << endl;
	cout << "***** 4.修改职工信息 *****" << endl;
	cout << "***** 5.查找职工信息 *****" << endl;
	cout << "***** 6.按照编号排序 *****" << endl;
	cout << "***** 7.清空所有文档 *****" << endl;
	cout << "***** 0.退出管理程序 *****" << endl;
	cout << "**************************" << endl;
	cout << "请输入您的选择：";
}

void EmpManager::addEmp() {
	//添加员工
	int addNum;
	
	cout << "请输入添加职工数量：" << endl;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = this->empNum + addNum;

		Emp** newSpace = new Emp * [newSize];

		//把老表的数据加入新表
		if (this->empList != NULL) {
			for (int i = 0;i < this->empNum;i++) {
				newSpace[i] = this->empList[i];
			}
		}

		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i+1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i+1 << "个新职工名称：" << endl;
			cin >> name;

			cout << "请选择第" << i+1 << "个职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Emp* e = NULL;
			switch (dSelect)
			{
			case 1:
				e = new Normal(id, name, 1);
				break;
			case 2:
				e = new Manager(id, name, 2);
				break;
			case 3:
				e = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->empNum + i] = e;
		}

		delete[] this->empList;

		this->empList = newSpace;

		this->empNum = newSize;

		this->isFileEmpty = false;

		cout << "成功添加" << addNum << "名职工!" << endl;

		this->save();
	}
	else {
		cout << "输入有误" << endl;
	}

	return;
}

void EmpManager::showEmp() {
	//显示职工信息
	if (this->empList == NULL) {
		cout << "没有员工" << endl;
		return;
	}

	for (int i = 0;i < this->empNum;i++) {
		this->empList[i]->showInfo();
	}
}

void EmpManager::save() {
	//职工信息存磁盘
	fstream f1;

	f1.open(fileName, ios::out);
	
	for (int i = 0;i < this->empNum;i++) {
		f1 << this->empList[i]->id << " "
			<< this->empList[i]->name << " "
			<< this->empList[i]->deptId << " " << endl;
	}

	f1.close();

	cout << "保存成功" << endl;
}

int EmpManager::getEmpNum() {
	//获取员工数量
	fstream f1;
	f1.open(fileName, ios::in);

	int id;
	string name;
	int deptId;

	int num = 0;

	while (f1 >> id && f1 >> name && f1 >> deptId) {
		num++;
	}

	f1.close();
	return num;
}

void EmpManager::initEmpList(int empNum) {
	//初始化员工列表
	fstream f1;
	f1.open(fileName, ios::in);

	int id;
	string name;
	int deptId;

	this->empList = new Emp * [empNum];

	int index = 0;
	while (f1 >> id && f1 >> name && f1 >> deptId) {
		Emp* e = NULL;

		switch (deptId)
		{
		case 1:
			e = new Normal(id, name, 1);
			break;
		case 2:
			e = new Manager(id, name, 2);
			break;
		case 3:
			e = new Boss(id, name, 3);
			break;
		default:
			break;
		}

		this->empList[index] = e;
		index++;
	}

	f1.close();
	return;
}

int EmpManager::isExist(int id) {
	//职工是否存在，存在返回index，不存在返回-1
	for (int i = 0;i < this->empNum;i++) {
		if (this->empList[i]->id == id) {
			return i;
		}
	}
	return -1;
}

void EmpManager::deleteEmp() {
	//删除职工信息
	if (this->empNum == 0) {
		cout << "没有员工" << endl;
		return;
	}

	int id,deleteIndex;

	cout << "请输入要删除职工的编号：" << endl;
	cin >> id;

	deleteIndex = isExist(id);

	if (deleteIndex == -1) {
		cout << id << "编号员工信息不存在！" << endl;
		return;
	}

	if (deleteIndex + 1 != this->empNum) {
		//若要删除的不为最后一位
		//从当前位置后一位开始每项往前移一位
		for (int i = deleteIndex;i < this->empNum - 1;i++) {
			this->empList[i] = this->empList[i + 1];
		}
	}
	this->empNum--;

	cout << "删除成功" << endl;
	if (this->empNum == 0) {
		this->save();
	}

	return;
}

void EmpManager::searchEmp() {
	//查找职工信息
	if (this->empNum == 0) {
		cout << "没有员工" << endl;
		return;
	}

	int id, searchIndex;
	cout << "请输入需要查找的员工编号：" << endl;
	cin >> id;

	searchIndex = isExist(id);

	if (searchIndex == -1) {
		cout << id << "编号员工信息不存在！" << endl;
		return;
	}

	this->empList[searchIndex]->showInfo();
}

void EmpManager::updateEmp() {
	//修改职工信息
	if (this->empNum == 0) {
		cout << "没有员工" << endl;
		return;
	}

	int id,updateIndex;
	cout << "请输入需要修改的职工编号：" << endl;
	cin >> id;

	updateIndex = isExist(id);
	if (updateIndex == -1) {
		cout << id << "编号员工信息不存在！" << endl;
		return;
	}

	//释放需要更新位置的内存
	delete this->empList[updateIndex];

	string name;
	int dSelect;

	cout << "请输入职工编号：" << endl;
	cin >> id;

	cout << "请输入职工名称：" << endl;
	cin >> name;

	cout << "请选择职工的岗位：" << endl;
	cout << "1.普通职工" << endl;
	cout << "2.经理" << endl;
	cout << "3.老板" << endl;
	cin >> dSelect;

	Emp* e = NULL;
	switch (dSelect)
	{
	case 1:
		e = new Normal(id, name, 1);
		break;
	case 2:
		e = new Manager(id, name, 2);
		break;
	case 3:
		e = new Boss(id, name, 3);
		break;
	default:
		break;
	}

	this->empList[updateIndex] = e;

	cout << "修改成功" << endl;
	this->save();
}

void EmpManager::clearEmp() {
	this->empList = NULL;
	this->empNum = 0;

	cout << "清空成功" << endl;
	this->save();
}

void EmpManager::sort() {
	//按照编号排序
	if (this->empNum == 0) {
		cout << "没有员工" << endl;
		return;
	}

	int rule;
	cout << "1.正序\n2.倒序\n请选择排序规则：" << endl;
	cin >> rule;

	Emp* e = NULL;
	switch (rule)
	{
	case 1: {//正序排序
		for (int i = 0; i < this->empNum - 1; i++) {
			// 设定一个标记，判断本次遍历是否进行了交换
			bool swapped = false;
			for (int j = 0; j < this->empNum - i - 1; j++) {
				if (this->empList[j]->id > this->empList[j + 1]->id) {
					// 交换 arr[j] 和 arr[j+1]
					e = this->empList[j];
					this->empList[j] = this->empList[j + 1];
					this->empList[j + 1] = e;

					// 表示进行了交换
					swapped = true;
				}
			}
			// 如果这一轮没有交换，说明数组已经排序好了
			if (swapped == false)
				break;
		}
		break;
	}
	case 2: {//倒序排序
		for (int i = 0; i < this->empNum - 1; i++) {
			// 设定一个标记，判断本次遍历是否进行了交换
			bool swapped = false;
			for (int j = 0; j < this->empNum - i - 1; j++) {
				if (this->empList[j]->id < this->empList[j + 1]->id) {
					// 交换 arr[j] 和 arr[j+1]
					e = this->empList[j];
					this->empList[j] = this->empList[j + 1];
					this->empList[j + 1] = e;

					// 表示进行了交换
					swapped = true;
				}
			}
			// 如果这一轮没有交换，说明数组已经排序好了
			if (swapped == false)
				break;
		}
		break;
	}
	default:
		cout << "选择错误！" << endl;
		return;
	}

	cout << "排序成功" << endl;
	this->save();
	return;
}