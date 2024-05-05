//ְ������ϵͳ��
#pragma once
#include <iostream>
#include "emp.h"

using namespace std;

class EmpManager {
public:
	EmpManager();

	~EmpManager();

	void showMenu();	//չʾ�˵�

	void addEmp();	//����ְ����Ϣ

	void showEmp();	//��ʾְ����Ϣ

	void save();	//ְ����Ϣ�����

	int getEmpNum();	//��ȡԱ������

	void initEmpList(int empNum);	//��ʼ��Ա���б�

	int isExist(int id);	//ְ���Ƿ���ڣ����ڷ���index�������ڷ���-1

	void deleteEmp();	//ɾ��ְ����Ϣ

	void searchEmp();	//����ְ����Ϣ

	void updateEmp();	//�޸�ְ����Ϣ

	void clearEmp();	//��������ĵ�

	void sort();	//���ձ������

	bool isFileEmpty;	//�ļ��Ƿ�Ϊ��

	int empNum;	//ְ������

	Emp** empList;	//ְ���б�
};