#include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//�����Ŀ 
	char type[100];					//���� (��Դ)
	char note[100];					//��ע 
}collect[1000];

 int count=0;						//��¼���� 
 
void income()
{
	char date[100],type[100],note[100];
	double money;
	cout<<"****��ӭ��������ļ�¼****"<<endl;
	cout<<"������������Ϣ��"<<endl;
	cout<<"����(xxxx��xx��xx��)��";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"��";
	cin>>money;
	collect[count].money=money;
	cout<<"����(��Դ)��";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"��ע��"; 
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"�����ѳɹ���¼��"<<endl; 
	count++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****��ӭ����֧���ļ�¼****"<<endl;
	cout<<"������֧����Ϣ��"<<endl;
	cout<<"����(xxxx��xx��xx��)��";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"��";
	cin>>money;
	collect[count].money=money;
	cout<<"����(��Դ)��";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"��ע��";
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"֧���ѳɹ���¼��"<<endl; 
	count++; 
}

void menu()
{
	cout<<"**********��ӭʹ�ø����˵�����ϵͳ**********"<<endl;
	cout<<"��ѡ�����"<<endl;
	cout<<"1.�����¼"<<endl;
	cout<<"2.֧����¼"<<endl; 
}

int main()
{
	int choice,choice1;
Start:
	menu();
	cout<<"��������Ҫʹ���õĹ��ܣ�";
	cin>>choice;
	switch(choice) 
	{
		case 1:
				income();
				cout<<"�밴1�������˵�"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
		case 2:
				expend();
				cout<<"�밴1�������˵�"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
	}	
	return 0;
}
