#include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//金额数目 
	char type[100];					//种类 (来源)
	char note[100];					//备注 
}collect[1000];

 int count=0;						//记录个数 
 
void income()
{
	char date[100],type[100],note[100];
	double money;
	cout<<"****欢迎来到收入的记录****"<<endl;
	cout<<"请输入收入信息："<<endl;
	cout<<"日期(xxxx年xx月xx日)：";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"金额：";
	cin>>money;
	collect[count].money=money;
	cout<<"种类(来源)：";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"备注："; 
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"收入已成功记录！"<<endl; 
	count++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****欢迎来到支出的记录****"<<endl;
	cout<<"请输入支出信息："<<endl;
	cout<<"日期(xxxx年xx月xx日)：";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"金额：";
	cin>>money;
	collect[count].money=money;
	cout<<"种类(来源)：";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"备注：";
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"支出已成功记录！"<<endl; 
	count++; 
}

void menu()
{
	cout<<"**********欢迎使用个人账单管理系统**********"<<endl;
	cout<<"请选择操作"<<endl;
	cout<<"1.收入记录"<<endl;
	cout<<"2.支出记录"<<endl; 
}

int main()
{
	int choice,choice1;
Start:
	menu();
	cout<<"请输入你要使用用的功能：";
	cin>>choice;
	switch(choice) 
	{
		case 1:
				income();
				cout<<"请按1返回主菜单"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
		case 2:
				expend();
				cout<<"请按1返回主菜单"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
	}	
	return 0;
}
