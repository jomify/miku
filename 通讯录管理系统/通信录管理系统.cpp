#include<iostream>
#include<string>
using namespace std;
void showmenu() {
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 16; b++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << "**1,�����ϵ��**" << endl;
	cout << "**2,��ʾ��ϵ��**" << endl;
	cout << "**3,ɾ����ϵ��**" << endl;
	cout << "**4,������ϵ��**" << endl;
	cout << "**5.�޸���ϵ��**" << endl;
	cout << "**6,�����ϵ��**" << endl;
	cout << "**0,�˳�ͨѶ¼**" << endl;
	for (int d = 0; d < 2; d++) {
		for (int v = 0; v < 16; v++) {
			cout << "*";
		}
		cout << endl;
	}
	





	



}
struct people {
	string name;
	int age;
	bool male;//1,�У�2��Ů

	string number;
	string location;
};
#define MAX 1000

struct addressbooks {

	people personarray[MAX];//��ϵ�˵�����

	int m_size;


};



void addperson(addressbooks* abs) {//�����ϵ��

	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ��ټ���
	if (abs->m_size == MAX) {

		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].name = name;//����Ϣ����ṹ�壻
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personarray[abs->m_size].age = age;
		bool male;
		cout << "�������Ա�" << endl;
		cout << "1Ϊ�У�0ΪŮ" << endl;
		cin >> male;
		abs->personarray[abs->m_size].male = male;
		string number;
		cout << "������绰����" << endl;
		cin >> number;
		abs->personarray[abs->m_size].number = number;
		string location;
		cout << "�������ַ" << endl;
		cin >> location;
		abs->personarray[abs->m_size].location = location;
		abs->m_size++;//���¼Ʋ���
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}




}

void showmenu(addressbooks* ads) {
	if (ads->m_size == 0) {

		cout << "��ǰ����ϵ��" << endl;
	}
	else {
		for (int a = 0; a < ads->m_size; a++) {
			cout << ads->personarray[a].name <<"\t";
			cout << ads->personarray[a].age << "\t";
			cout << (ads->personarray[a].male == 1 ? "��" : "Ů" )<< "\t";
			cout << ads->personarray[a].number << "\t";
			cout << ads->personarray[a].location << "\t";
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	
}


int exist(addressbooks* abs, string name) {
	for (int a = 0; a < abs->m_size; a++) {
		if (abs->personarray[a].name == name) {
			return a;
		}
	}
	return -1;
}


void delectperson(addressbooks* abs) {
	string name;
	cout << "������Ҫɾ�����˵�����" << endl;
	cin >> name;
	int E = exist(abs, name);
	cout << (E == -1 ? "����ϵ��" : "��ǰ��ϵ��Ϊ�� " + to_string(E) + " λ") << endl;
	//ɾ����������������������ǰ�ƶ�������ͨѶ¼�м�¼����Ա��������1�������ɣ�
	if (E!=-1) {
		for (int a = E; a < abs->m_size; a++) {
			abs->personarray[a] = abs->personarray[a + 1];
		}
		cout << "�Ѿ��ɹ�ɾ����ϵ��" << endl;
	}
	abs->m_size--;
	
	system("pause");
	system("cls");

}
int chack(addressbooks* abs,string name) {
	
	for (int a = 0; a < abs->m_size; a++) {
		if (abs->personarray[a].name == name) {
			return a;
			cout << "�Ѿ��ҵ���ϵ��" <<"Ϊ��"<<a<<"λ" << endl;
		}
	}
	
	cout << "��ǰͨѶ¼δ�д���" << endl;
	return -1;
}

void showpeople(addressbooks* abs) {
	string name;
	cout << "����������Ҫ���ҵ���ϵ��" << endl;
	cin >> name;
	int v = chack(abs, name);
	if (v != -1) {
		cout << abs->personarray[v].name << "\t";
		cout << abs->personarray[v].age << "\t";
		cout << ((abs->personarray[v].male) = 1 ? "��" : "Ů") << "\t";
		cout << abs->personarray[v].number << "\t";
		cout << abs->personarray[v].location << "\n";
	}
	

	system("pause");
	system("cls");


}

void show1();



void exchange(addressbooks* abs) {
	string name;
	cout << "����������Ҫ�޸ĵ���Ա����" << endl;
	cin >> name;
	int v = chack(abs, name);
	system("pause");
	system("cls");
	if (v != -1) {
		cout << "��ѡ��Ҫ�޸ĵ���Ŀ" << endl;
		int b = 0;
		while (true) {
			show1();
			cin >> b;
			switch (b) {
			case 1:
				cin >> abs->personarray[v].age;
				system("cls");
				break;
				
			case 2:
				cin>> abs->personarray[v].name;
				system("cls");
				break;
				
			case 3:
				cin>> abs->personarray[v].location;
				
				system("cls");
				break;
				
			case 4:
				cin >> abs->personarray[v].male;
				system("pause");
				system("cls");
				break;
				
			case 5:
				cin >> abs->personarray[v].number;
				system("pause");
				system("cls");
				break;
				
			case 6:
				system("pause");
				system("cls");
				break;
				
			default:
				cout << "�����������������" << endl;
				break;
			}
			


		}
		
		system("cls");
	}
}



void show1() {
	cout << "1,age\n";
	cout << "2,name\n";
	cout << "3,location\n";
	cout << "4,male\n";
	cout << "5,number\n";
	cout << "6,�ص�������\n";
}


void cleanperson(addressbooks*abs) {
	abs->m_size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}



















int main() {
	



	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	

	while (true) {
		showmenu();
		int seclect;
		cin >> seclect;
		switch (seclect) {
		case 1:
			addperson(&abs);//���õ�ַ����
			break;
		case 2:
			showmenu(&abs);
			break;
		case 3:
		{
			delectperson(&abs);
			break;
		}//��case�����Ҫ������ת��Ϊ���봮��
		case 4:
			showpeople(&abs);
			break;
		case 5:
			exchange(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		
	}
	






}