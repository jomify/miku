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
	cout << "**1,添加联系人**" << endl;
	cout << "**2,显示联系人**" << endl;
	cout << "**3,删除联系人**" << endl;
	cout << "**4,查找联系人**" << endl;
	cout << "**5.修改联系人**" << endl;
	cout << "**6,清空联系人**" << endl;
	cout << "**0,退出通讯录**" << endl;
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
	bool male;//1,男，2，女

	string number;
	string location;
};
#define MAX 1000

struct addressbooks {

	people personarray[MAX];//联系人的数组

	int m_size;


};



void addperson(addressbooks* abs) {//添加联系人

	//判定通讯录是否已满，如果满了就不再加入
	if (abs->m_size == MAX) {

		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[abs->m_size].name = name;//将信息存入结构体；
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personarray[abs->m_size].age = age;
		bool male;
		cout << "请输入性别" << endl;
		cout << "1为男，0为女" << endl;
		cin >> male;
		abs->personarray[abs->m_size].male = male;
		string number;
		cout << "请输入电话号码" << endl;
		cin >> number;
		abs->personarray[abs->m_size].number = number;
		string location;
		cout << "请输入地址" << endl;
		cin >> location;
		abs->personarray[abs->m_size].location = location;
		abs->m_size++;//更新计步器
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}




}

void showmenu(addressbooks* ads) {
	if (ads->m_size == 0) {

		cout << "当前无联系人" << endl;
	}
	else {
		for (int a = 0; a < ads->m_size; a++) {
			cout << ads->personarray[a].name <<"\t";
			cout << ads->personarray[a].age << "\t";
			cout << (ads->personarray[a].male == 1 ? "男" : "女" )<< "\t";
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
	cout << "请输入要删除的人的姓名" << endl;
	cin >> name;
	int E = exist(abs, name);
	cout << (E == -1 ? "无联系人" : "当前联系人为第 " + to_string(E) + " 位") << endl;
	//删除方法，将其后面的数据向前移动并且让通讯录中记录的人员个数做—1操作即可；
	if (E!=-1) {
		for (int a = E; a < abs->m_size; a++) {
			abs->personarray[a] = abs->personarray[a + 1];
		}
		cout << "已经成功删除联系人" << endl;
	}
	abs->m_size--;
	
	system("pause");
	system("cls");

}
int chack(addressbooks* abs,string name) {
	
	for (int a = 0; a < abs->m_size; a++) {
		if (abs->personarray[a].name == name) {
			return a;
			cout << "已经找到联系人" <<"为第"<<a<<"位" << endl;
		}
	}
	
	cout << "当前通讯录未有此人" << endl;
	return -1;
}

void showpeople(addressbooks* abs) {
	string name;
	cout << "请输入您想要查找的联系人" << endl;
	cin >> name;
	int v = chack(abs, name);
	if (v != -1) {
		cout << abs->personarray[v].name << "\t";
		cout << abs->personarray[v].age << "\t";
		cout << ((abs->personarray[v].male) = 1 ? "男" : "女") << "\t";
		cout << abs->personarray[v].number << "\t";
		cout << abs->personarray[v].location << "\n";
	}
	

	system("pause");
	system("cls");


}

void show1();



void exchange(addressbooks* abs) {
	string name;
	cout << "请输入您想要修改的人员姓名" << endl;
	cin >> name;
	int v = chack(abs, name);
	system("pause");
	system("cls");
	if (v != -1) {
		cout << "请选择要修改的项目" << endl;
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
				cout << "输入出错请重新输入" << endl;
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
	cout << "6,回到主界面\n";
}


void cleanperson(addressbooks*abs) {
	abs->m_size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}



















int main() {
	



	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;
	

	while (true) {
		showmenu();
		int seclect;
		cin >> seclect;
		switch (seclect) {
		case 1:
			addperson(&abs);//利用地址传递
			break;
		case 2:
			showmenu(&abs);
			break;
		case 3:
		{
			delectperson(&abs);
			break;
		}//在case语句中要将代码转化为代码串；
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		
	}
	






}