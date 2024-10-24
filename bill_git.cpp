#include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//�����Ŀ 
	char type[100];					//���� (��Դ)
	char note[100];					//��ע 
}collect1[1000],collect2[1000];

 int count1=0,count2=0;						//��¼���� 
 
void income()
{
	char date[100],type[100],note[100];		//�����������
	double money;//����
	cout<<"****��ӭ��������ļ�¼****"<<endl;
	cout<<"������������Ϣ��"<<endl;
	cout<<"����(xxxx��xx��xx��)��";
	cin>>date;
	strcpy(collect1[count1].date,date);
	cout<<"��";
	cin>>money;
	collect1[count1].money=money;
	cout<<"����(��Դ)��";
	cin>>type;
	strcpy(collect1[count1].type,type);
	cout<<"��ע��"; 
	cin>>note;
	strcpy(collect1[count1].note,note);
	cout<<"�����ѳɹ���¼��"<<endl; 
	count1++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****��ӭ����֧���ļ�¼****"<<endl;
	cout<<"������֧����Ϣ��"<<endl;
	cout<<"����(xxxx��xx��xx��)��";
	cin>>date;
	strcpy(collect2[count2].date,date);
	cout<<"��";
	cin>>money;
	collect2[count2].money=money;
	cout<<"����(��Դ)��";
	cin>>type;
	strcpy(collect2[count2].type,type);
	cout<<"��ע��";
	cin>>note;
	strcpy(collect2[count2].note,note);
	cout<<"֧���ѳɹ���¼��"<<endl; 
	count2++; 
}


void print_bill()
{
    cout << "******�˵�չʾ******" << endl;
    cout << "****�����˵�****" << endl;
    for(int i = 0; i < count1; i++)
    {
        cout << "����:" << collect1[i].date 
             << " ���:" << collect1[i].money 
             << " ����:" << collect1[i].type 
             << " ��ע:" << collect1[i].note << endl; 
    } 
    cout << "****֧���˵�****" << endl;
    for(int j = 0; j < count2; j++)
    {
        cout << "����:" << collect2[j].date 
             << " ���:" << collect2[j].money 
             << " ����:" << collect2[j].type 
             << " ��ע:" << collect2[j].note << endl; 
    }
    
    cout << "******�˵���ѯ******" << endl;
    int choice;
    cout << "ѡ��1:ѡ�����ڲ�ѯ" << endl;
    cout << "ѡ��2:ѡ�����Ͳ�ѯ" << endl;
    cin >> choice;

    if(choice == 1)
    {
        char queryDate[100];
        cout << "���������ڽ��в�ѯ��";
        cin >> queryDate;

        cout << "��ѯ���:" << endl;
        bool found = false;

        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].date, queryDate) == 0)
            {
                cout << "����:" << collect1[i].date 
                     << " ���:" << collect1[i].money 
                     << " ����:" << collect1[i].type 
                     << " ��ע:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].date, queryDate) == 0)
            {
                cout << "����:" << collect2[j].date 
                     << " ���:" << collect2[j].money 
                     << " ����:" << collect2[j].type 
                     << " ��ע:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "û���ҵ���ؼ�¼��" << endl;
        }
    }
    else if(choice == 2)
    {
        char queryType[100];
        cout << "���������ͽ��в�ѯ��";
        cin >> queryType;

        cout << "��ѯ���:" << endl;
        bool found = false;
        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].type, queryType) == 0)
            {
                cout << "����:" << collect1[i].date 
                     << " ���:" << collect1[i].money 
                     << " ����:" << collect1[i].type 
                     << " ��ע:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].type, queryType) == 0)
            {
                cout << "����:" << collect2[j].date 
                     << " ���:" << collect2[j].money 
                     << " ����:" << collect2[j].type 
                     << " ��ע:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "û���ҵ���ؼ�¼��" << endl;
        }
    }
    else
    {
        cout << "��Чѡ�������ԡ�" << endl;
    }
}

void menu()
{
	cout<<"**********��ӭʹ�ø����˵�����ϵͳ**********"<<endl;
	cout<<"��ѡ�����"<<endl;
	cout<<"1.�����¼"<<endl;
	cout<<"2.֧����¼"<<endl; 
	cout<<"3.�˵�չʾ�Լ��˵���ѯ"<<endl;
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
		case 3:
				print_bill();
				cout<<"�밴1�������˵�"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
	}	
	return 0;
}
