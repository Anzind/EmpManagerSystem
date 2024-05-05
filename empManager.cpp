//ְ������ϵͳ��ʵ��
#include <fstream>
#include "empManager.h"

const string fileName = "empFile.txt";

EmpManager::EmpManager() {
	fstream f1;
	f1.open(fileName, ios::in);

	if (!f1.is_open()) {
		//���ļ�������
		//cout << "�ļ�������" << endl;
		this->empNum = 0;
		this->empList = NULL;
		this->isFileEmpty = true;
		f1.close();
		return;
	}

	char ch;
	f1 >> ch;
	if (f1.eof()) {
		//���ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
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
	//չʾ�˵�
	cout << "**************************" << endl;
	cout << "***** 1.����ְ����Ϣ *****" << endl;
	cout << "***** 2.��ʾְ����Ϣ *****" << endl;
	cout << "***** 3.ɾ��ְ����Ϣ *****" << endl;
	cout << "***** 4.�޸�ְ����Ϣ *****" << endl;
	cout << "***** 5.����ְ����Ϣ *****" << endl;
	cout << "***** 6.���ձ������ *****" << endl;
	cout << "***** 7.��������ĵ� *****" << endl;
	cout << "***** 0.�˳�������� *****" << endl;
	cout << "**************************" << endl;
	cout << "����������ѡ��";
}

void EmpManager::addEmp() {
	//���Ա��
	int addNum;
	
	cout << "���������ְ��������" << endl;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = this->empNum + addNum;

		Emp** newSpace = new Emp * [newSize];

		//���ϱ�����ݼ����±�
		if (this->empList != NULL) {
			for (int i = 0;i < this->empNum;i++) {
				newSpace[i] = this->empList[i];
			}
		}

		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect;

			cout << "�������" << i+1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i+1 << "����ְ�����ƣ�" << endl;
			cin >> name;

			cout << "��ѡ���" << i+1 << "��ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

		cout << "�ɹ����" << addNum << "��ְ��!" << endl;

		this->save();
	}
	else {
		cout << "��������" << endl;
	}

	return;
}

void EmpManager::showEmp() {
	//��ʾְ����Ϣ
	if (this->empList == NULL) {
		cout << "û��Ա��" << endl;
		return;
	}

	for (int i = 0;i < this->empNum;i++) {
		this->empList[i]->showInfo();
	}
}

void EmpManager::save() {
	//ְ����Ϣ�����
	fstream f1;

	f1.open(fileName, ios::out);
	
	for (int i = 0;i < this->empNum;i++) {
		f1 << this->empList[i]->id << " "
			<< this->empList[i]->name << " "
			<< this->empList[i]->deptId << " " << endl;
	}

	f1.close();

	cout << "����ɹ�" << endl;
}

int EmpManager::getEmpNum() {
	//��ȡԱ������
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
	//��ʼ��Ա���б�
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
	//ְ���Ƿ���ڣ����ڷ���index�������ڷ���-1
	for (int i = 0;i < this->empNum;i++) {
		if (this->empList[i]->id == id) {
			return i;
		}
	}
	return -1;
}

void EmpManager::deleteEmp() {
	//ɾ��ְ����Ϣ
	if (this->empNum == 0) {
		cout << "û��Ա��" << endl;
		return;
	}

	int id,deleteIndex;

	cout << "������Ҫɾ��ְ���ı�ţ�" << endl;
	cin >> id;

	deleteIndex = isExist(id);

	if (deleteIndex == -1) {
		cout << id << "���Ա����Ϣ�����ڣ�" << endl;
		return;
	}

	if (deleteIndex + 1 != this->empNum) {
		//��Ҫɾ���Ĳ�Ϊ���һλ
		//�ӵ�ǰλ�ú�һλ��ʼÿ����ǰ��һλ
		for (int i = deleteIndex;i < this->empNum - 1;i++) {
			this->empList[i] = this->empList[i + 1];
		}
	}
	this->empNum--;

	cout << "ɾ���ɹ�" << endl;
	if (this->empNum == 0) {
		this->save();
	}

	return;
}

void EmpManager::searchEmp() {
	//����ְ����Ϣ
	if (this->empNum == 0) {
		cout << "û��Ա��" << endl;
		return;
	}

	int id, searchIndex;
	cout << "��������Ҫ���ҵ�Ա����ţ�" << endl;
	cin >> id;

	searchIndex = isExist(id);

	if (searchIndex == -1) {
		cout << id << "���Ա����Ϣ�����ڣ�" << endl;
		return;
	}

	this->empList[searchIndex]->showInfo();
}

void EmpManager::updateEmp() {
	//�޸�ְ����Ϣ
	if (this->empNum == 0) {
		cout << "û��Ա��" << endl;
		return;
	}

	int id,updateIndex;
	cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
	cin >> id;

	updateIndex = isExist(id);
	if (updateIndex == -1) {
		cout << id << "���Ա����Ϣ�����ڣ�" << endl;
		return;
	}

	//�ͷ���Ҫ����λ�õ��ڴ�
	delete this->empList[updateIndex];

	string name;
	int dSelect;

	cout << "������ְ����ţ�" << endl;
	cin >> id;

	cout << "������ְ�����ƣ�" << endl;
	cin >> name;

	cout << "��ѡ��ְ���ĸ�λ��" << endl;
	cout << "1.��ְͨ��" << endl;
	cout << "2.����" << endl;
	cout << "3.�ϰ�" << endl;
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

	cout << "�޸ĳɹ�" << endl;
	this->save();
}

void EmpManager::clearEmp() {
	this->empList = NULL;
	this->empNum = 0;

	cout << "��ճɹ�" << endl;
	this->save();
}

void EmpManager::sort() {
	//���ձ������
	if (this->empNum == 0) {
		cout << "û��Ա��" << endl;
		return;
	}

	int rule;
	cout << "1.����\n2.����\n��ѡ���������" << endl;
	cin >> rule;

	Emp* e = NULL;
	switch (rule)
	{
	case 1: {//��������
		for (int i = 0; i < this->empNum - 1; i++) {
			// �趨һ����ǣ��жϱ��α����Ƿ�����˽���
			bool swapped = false;
			for (int j = 0; j < this->empNum - i - 1; j++) {
				if (this->empList[j]->id > this->empList[j + 1]->id) {
					// ���� arr[j] �� arr[j+1]
					e = this->empList[j];
					this->empList[j] = this->empList[j + 1];
					this->empList[j + 1] = e;

					// ��ʾ�����˽���
					swapped = true;
				}
			}
			// �����һ��û�н�����˵�������Ѿ��������
			if (swapped == false)
				break;
		}
		break;
	}
	case 2: {//��������
		for (int i = 0; i < this->empNum - 1; i++) {
			// �趨һ����ǣ��жϱ��α����Ƿ�����˽���
			bool swapped = false;
			for (int j = 0; j < this->empNum - i - 1; j++) {
				if (this->empList[j]->id < this->empList[j + 1]->id) {
					// ���� arr[j] �� arr[j+1]
					e = this->empList[j];
					this->empList[j] = this->empList[j + 1];
					this->empList[j + 1] = e;

					// ��ʾ�����˽���
					swapped = true;
				}
			}
			// �����һ��û�н�����˵�������Ѿ��������
			if (swapped == false)
				break;
		}
		break;
	}
	default:
		cout << "ѡ�����" << endl;
		return;
	}

	cout << "����ɹ�" << endl;
	this->save();
	return;
}