include <iostream>
#include <cstring>
using namespace std;

struct bill
{
	char date[100];
	double money;					//½ð¶îÊýÄ¿ 
	char type[100];					//ÖÖÀà (À´Ô´)
	char note[100];					//±¸×¢ 
}collect[1000];

 int count=0;						//¼ÇÂ¼¸öÊý 
 
void income()
{
	char date[100],type[100],note[100];		//¿¿¿¿¿¿¿¿¿¿¿
	double money;//¿¿¿¿
	cout<<"****»¶Ó­À´µ½ÊÕÈëµÄ¼ÇÂ¼****"<<endl;
	cout<<"ÇëÊäÈëÊÕÈëÐÅÏ¢£º"<<endl;
	cout<<"ÈÕÆÚ(xxxxÄêxxÔÂxxÈÕ)£º";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"½ð¶î£º";
	cin>>money;
	collect[count].money=money;
	cout<<"ÖÖÀà(À´Ô´)£º";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"±¸×¢£º"; 
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"ÊÕÈëÒÑ³É¹¦¼ÇÂ¼£¡"<<endl; 
	count++; 
} 

void expend()
{
	char date[30],type[50],note[50];
	double money;
	cout<<"****»¶Ó­À´µ½Ö§³öµÄ¼ÇÂ¼****"<<endl;
	cout<<"ÇëÊäÈëÖ§³öÐÅÏ¢£º"<<endl;
	cout<<"ÈÕÆÚ(xxxxÄêxxÔÂxxÈÕ)£º";
	cin>>date;
	strcpy(collect[count].date,date);
	cout<<"½ð¶î£º";
	cin>>money;
	collect[count].money=money;
	cout<<"ÖÖÀà(À´Ô´)£º";
	cin>>type;
	strcpy(collect[count].type,type);
	cout<<"±¸×¢£º";
	cin>>note;
	strcpy(collect[count].note,note);
	cout<<"Ö§³öÒÑ³É¹¦¼ÇÂ¼£¡"<<endl; 
	count++; 
}

void menu()
{
	cout<<"**********»¶Ó­Ê¹ÓÃ¸öÈËÕËµ¥¹ÜÀíÏµÍ³**********"<<endl;
	cout<<"ÇëÑ¡Ôñ²Ù×÷"<<endl;
	cout<<"1.ÊÕÈë¼ÇÂ¼"<<endl;
	cout<<"2.Ö§³ö¼ÇÂ¼"<<endl; 
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
	}	
	return 0;
}
