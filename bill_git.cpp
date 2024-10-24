#include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//½ð¶îÊýÄ¿ 
	char type[100];					//ÖÖÀà (À´Ô´)
	char note[100];					//±¸×¢ 
}collect1[1000],collect2[1000];

 int count1=0,count2=0;						//¼ÇÂ¼¸öÊý 
 
void income()
{
	char date[100],type[100],note[100];		//¿¿¿¿¿¿¿¿¿¿¿
	double money;//¿¿¿¿
	cout<<"****»¶Ó­À´µ½ÊÕÈëµÄ¼ÇÂ¼****"<<endl;
	cout<<"ÇëÊäÈëÊÕÈëÐÅÏ¢£º"<<endl;
	cout<<"ÈÕÆÚ(xxxxÄêxxÔÂxxÈÕ)£º";
	cin>>date;
	strcpy(collect1[count1].date,date);
	cout<<"½ð¶î£º";
	cin>>money;
	collect1[count1].money=money;
	cout<<"ÖÖÀà(À´Ô´)£º";
	cin>>type;
	strcpy(collect1[count1].type,type);
	cout<<"±¸×¢£º"; 
	cin>>note;
	strcpy(collect1[count1].note,note);
	cout<<"ÊÕÈëÒÑ³É¹¦¼ÇÂ¼£¡"<<endl; 
	count1++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****»¶Ó­À´µ½Ö§³öµÄ¼ÇÂ¼****"<<endl;
	cout<<"ÇëÊäÈëÖ§³öÐÅÏ¢£º"<<endl;
	cout<<"ÈÕÆÚ(xxxxÄêxxÔÂxxÈÕ)£º";
	cin>>date;
	strcpy(collect2[count2].date,date);
	cout<<"½ð¶î£º";
	cin>>money;
	collect2[count2].money=money;
	cout<<"ÖÖÀà(À´Ô´)£º";
	cin>>type;
	strcpy(collect2[count2].type,type);
	cout<<"±¸×¢£º";
	cin>>note;
	strcpy(collect2[count2].note,note);
	cout<<"Ö§³öÒÑ³É¹¦¼ÇÂ¼£¡"<<endl; 
	count2++; 
}


void print_bill()
{
    cout << "******ÕËµ¥Õ¹Ê¾******" << endl;
    cout << "****ÊÕÈëÕËµ¥****" << endl;
    for(int i = 0; i < count1; i++)
    {
        cout << "ÈÕÆÚ:" << collect1[i].date 
             << " ½ð¶î:" << collect1[i].money 
             << " ÖÖÀà:" << collect1[i].type 
             << " ±¸×¢:" << collect1[i].note << endl; 
    } 
    cout << "****Ö§³öÕËµ¥****" << endl;
    for(int j = 0; j < count2; j++)
    {
        cout << "ÈÕÆÚ:" << collect2[j].date 
             << " ½ð¶î:" << collect2[j].money 
             << " ÖÖÀà:" << collect2[j].type 
             << " ±¸×¢:" << collect2[j].note << endl; 
    }
    
    cout << "******ÕËµ¥²éÑ¯******" << endl;
    int choice;
    cout << "Ñ¡Ôñ1:Ñ¡ÔñÈÕÆÚ²éÑ¯" << endl;
    cout << "Ñ¡Ôñ2:Ñ¡ÔñÀàÐÍ²éÑ¯" << endl;
    cin >> choice;

    if(choice == 1)
    {
        char queryDate[100];
        cout << "ÇëÊäÈëÈÕÆÚ½øÐÐ²éÑ¯£º";
        cin >> queryDate;

        cout << "²éÑ¯½á¹û:" << endl;
        bool found = false;

        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].date, queryDate) == 0)
            {
                cout << "ÈÕÆÚ:" << collect1[i].date 
                     << " ½ð¶î:" << collect1[i].money 
                     << " ÖÖÀà:" << collect1[i].type 
                     << " ±¸×¢:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].date, queryDate) == 0)
            {
                cout << "ÈÕÆÚ:" << collect2[j].date 
                     << " ½ð¶î:" << collect2[j].money 
                     << " ÖÖÀà:" << collect2[j].type 
                     << " ±¸×¢:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "Ã»ÓÐÕÒµ½Ïà¹Ø¼ÇÂ¼¡£" << endl;
        }
    }
    else if(choice == 2)
    {
        char queryType[100];
        cout << "ÇëÊäÈëÀàÐÍ½øÐÐ²éÑ¯£º";
        cin >> queryType;

        cout << "²éÑ¯½á¹û:" << endl;
        bool found = false;
        for(int i = 0; i < count1; i++)
        {
            if(strcmp(collect1[i].type, queryType) == 0)
            {
                cout << "ÈÕÆÚ:" << collect1[i].date 
                     << " ½ð¶î:" << collect1[i].money 
                     << " ÖÖÀà:" << collect1[i].type 
                     << " ±¸×¢:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for(int j = 0; j < count2; j++)
        {
            if(strcmp(collect2[j].type, queryType) == 0)
            {
                cout << "ÈÕÆÚ:" << collect2[j].date 
                     << " ½ð¶î:" << collect2[j].money 
                     << " ÖÖÀà:" << collect2[j].type 
                     << " ±¸×¢:" << collect2[j].note << endl; 
                found = true;
            }
        }

        if (!found) {
            cout << "Ã»ÓÐÕÒµ½Ïà¹Ø¼ÇÂ¼¡£" << endl;
        }
    }
    else
    {
        cout << "ÎÞÐ§Ñ¡Ôñ£¬ÇëÖØÊÔ¡£" << endl;
    }
}

void menu()
{
	cout<<"**********»¶Ó­Ê¹ÓÃ¸öÈËÕËµ¥¹ÜÀíÏµÍ³**********"<<endl;
	cout<<"ÇëÑ¡Ôñ²Ù×÷"<<endl;
	cout<<"1.ÊÕÈë¼ÇÂ¼"<<endl;
	cout<<"2.Ö§³ö¼ÇÂ¼"<<endl; 
	cout<<"3.ÕËµ¥Õ¹Ê¾ÒÔ¼°ÕËµ¥²éÑ¯"<<endl;
}

int main()
{
	int choice,choice1;
Start:
	menu();
	cout<<"ÇëÊäÈëÄãÒªÊ¹ÓÃÓÃµÄ¹¦ÄÜ£º";
	cin>>choice;
	switch(choice) 
	{
		case 1:
				income();
				cout<<"Çë°´1·µ»ØÖ÷²Ëµ¥"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
		case 2:
				expend();
				cout<<"Çë°´1·µ»ØÖ÷²Ëµ¥"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
		case 3:
				print_bill();
				cout<<"Çë°´1·µ»ØÖ÷²Ëµ¥"<<endl;
				cin>>choice1;
				if(choice1==1)
				goto Start;
	}	
	return 0;
}
