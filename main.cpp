#include <iostream>
#include <string>
#include "empManager.h"
#include "emp.h"

using namespace std;

int main() {
	int select;
	EmpManager em;

	while (true) {

		em.showMenu();
		cin >> select;

		switch (select)
		{
		case 1: {
			//cout << "增加职工信息！！" << endl;
			em.addEmp();

			system("pause");
			system("cls");
			break;
		}
		case 2: {
			//cout << "显示职工信息！！" << endl;
			em.showEmp();

			system("pause");
			system("cls");
			break;
		}
		case 3: {
			//cout << "删除职工信息！！" << endl;
			em.deleteEmp();

			system("pause");
			system("cls");
			break;
		}
		case 4: {
			//cout << "修改职工信息！！" << endl;
			em.updateEmp();

			system("pause");
			system("cls");
			break;
		}
		case 5: {
			//cout << "查找职工信息！！" << endl;
			em.searchEmp();

			system("pause");
			system("cls");
			break;
		}
		case 6: {
			//cout << "按照编号排序！！" << endl;
			em.sort();
			em.showEmp();

			system("pause");
			system("cls");
			break;
		}
		case 7: {
			//cout << "清空所有文档！！" << endl;
			em.clearEmp();

			system("pause");
			system("cls");
			break;
		}
		case 0: {
			cout << "正在准备退出程序。。。" << endl;

			exit(0);
			break;
		}
		default: {
			cout << "无效选择" << endl;

			system("pause");
			system("cls");
			break;
		}
		}
	}

	return 0;
}