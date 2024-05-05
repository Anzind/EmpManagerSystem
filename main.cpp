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
			//cout << "����ְ����Ϣ����" << endl;
			em.addEmp();

			system("pause");
			system("cls");
			break;
		}
		case 2: {
			//cout << "��ʾְ����Ϣ����" << endl;
			em.showEmp();

			system("pause");
			system("cls");
			break;
		}
		case 3: {
			//cout << "ɾ��ְ����Ϣ����" << endl;
			em.deleteEmp();

			system("pause");
			system("cls");
			break;
		}
		case 4: {
			//cout << "�޸�ְ����Ϣ����" << endl;
			em.updateEmp();

			system("pause");
			system("cls");
			break;
		}
		case 5: {
			//cout << "����ְ����Ϣ����" << endl;
			em.searchEmp();

			system("pause");
			system("cls");
			break;
		}
		case 6: {
			//cout << "���ձ�����򣡣�" << endl;
			em.sort();
			em.showEmp();

			system("pause");
			system("cls");
			break;
		}
		case 7: {
			//cout << "��������ĵ�����" << endl;
			em.clearEmp();

			system("pause");
			system("cls");
			break;
		}
		case 0: {
			cout << "����׼���˳����򡣡���" << endl;

			exit(0);
			break;
		}
		default: {
			cout << "��Чѡ��" << endl;

			system("pause");
			system("cls");
			break;
		}
		}
	}

	return 0;
}