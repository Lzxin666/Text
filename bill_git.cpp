#include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//金额数目 
	char type[100];					//种类 (来源)
	char note[100];					//备注 
}collect1[1000],collect2[1000];

 int count1=0,count2=0;						//记录个数 
 
void income()
{
	char date[100],type[100],note[100];		//靠靠靠靠靠�
	double money;//靠靠
	cout<<"****欢迎来到收入的记录****"<<endl;
	cout<<"请输入收入信息："<<endl;
	cout<<"日期(xxxx年xx月xx日)：";
	cin>>date;
	strcpy(collect1[count1].date,date);
	cout<<"金额：";
	cin>>money;
	collect1[count1].money=money;
	cout<<"种类(来源)：";
	cin>>type;
	strcpy(collect1[count1].type,type);
	cout<<"备注："; 
	cin>>note;
	strcpy(collect1[count1].note,note);
	cout<<"收入已成功记录！"<<endl; 
	count1++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****欢迎来到支出的记录****"<<endl;
	cout<<"请输入支出信息："<<endl;
	cout<<"日期(xxxx年xx月xx日)：";
	cin>>date;
	strcpy(collect2[count2].date,date);
	cout<<"金额：";
	cin>>money;
	collect2[count2].money=money;
	cout<<"种类(来源)：";
	cin>>type;
	strcpy(collect2[count2].type,type);
	cout<<"备注：";
	cin>>note;
	strcpy(collect2[count2].note,note);
	cout<<"支出已成功记录！"<<endl; 
	count2++; 
}


void print_bill()
{
    cout << "******账单展示******" << endl;
    cout << "****收入账单****" << endl;
    for(int i = 0; i < count1; i++)
    {
        cout << "日期:" << collect1[i].date 
             << " 金额:" << collect1[i].money 
             << " 种类:" << collect1[i].type 
             << " 备注:" << collect1[i].note << endl; 
    } 
    cout << "****支出账单****" << endl;
    for(int j = 0; j < count2; j++)
    {
        cout << "日期:" << collect2[j].date 
             << " 金额:" << collect2[j].money 
             << " 种类:" << collect2[j].type 
             << " 备注:" << collect2[j].note << endl; 
    }
    
    cout << "******账单查询******" << endl;
    int choice;
    cout << "选择1:选择日期查询" << endl;
    cout << "选择2:选择类型查询" << endl;
    cin >> choice;

    if(choice == 1)
    {
        char queryDate[100];
        cout << "请输入日期进行查询：";
        cin >> queryDate;

        cout << "查询结果:" << endl;
        bool found = false;

        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].date, queryDate) == 0)
            {
                cout << "日期:" << collect1[i].date 
                     << " 金额:" << collect1[i].money 
                     << " 种类:" << collect1[i].type 
                     << " 备注:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].date, queryDate) == 0)
            {
                cout << "日期:" << collect2[j].date 
                     << " 金额:" << collect2[j].money 
                     << " 种类:" << collect2[j].type 
                     << " 备注:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "没有找到相关记录。" << endl;
        }
    }
    else if(choice == 2)
    {
        char queryType[100];
        cout << "请输入类型进行查询：";
        cin >> queryType;

        cout << "查询结果:" << endl;
        bool found = false;
        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].type, queryType) == 0)
            {
                cout << "日期:" << collect1[i].date 
                     << " 金额:" << collect1[i].money 
                     << " 种类:" << collect1[i].type 
                     << " 备注:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].type, queryType) == 0)
            {
                cout << "日期:" << collect2[j].date 
                     << " 金额:" << collect2[j].money 
                     << " 种类:" << collect2[j].type 
                     << " 备注:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "没有找到相关记录。" << endl;
        }
    }
    else
    {
        cout << "无效选择，请重试。" << endl;
    }
}

void menu()
{
	cout<<"**********欢迎使用个人账单管理系统**********"<<endl;
	cout<<"请选择操作"<<endl;
	cout<<"1.收入记录"<<endl;
	cout<<"2.支出记录"<<endl; 
	cout<<"3.账单展示以及账单查询"<<endl;
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
		case 3:
				print_bill();
				cout<<"请按1返回主菜单"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
	}	
	return 0;
}
