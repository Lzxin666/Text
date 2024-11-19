#include <iostream>
#include <cstring>
#include <map>
using namespace std;

struct billd {
    char date[100];
    double money;                  // 金额数目 
    char type[100];                // 种类 (来源)
    char note[100];                // 备注 
} collect1[1000], collect2[1000];

int count1 = 0, count2 = 0;      // 记录个数 
double monthlyBudget = 0;        // 每月预算
double totalExpend = 0;          // 当前已支出总额

void income() {
    char date[100], type[100], note[100];
    double money;
    cout << "****欢迎来到收入的记录****" << endl;
    cout << "请输入收入信息：" << endl;
    cout << "日期(xxxx年xx月xx日)：";
    cin >> date;
    strcpy(collect1[count1].date, date);
    cout << "金额：";
    cin >> money;
    collect1[count1].money = money;
    cout << "种类(来源)：";
    cin >> type;
    strcpy(collect1[count1].type, type);
    cout << "备注："; 
    cin >> note;
    strcpy(collect1[count1].note, note);
    cout << "收入已成功记录！" << endl; 
    count1++; 
}

void expend() {
    char date[30], type[50], note[50];
    double money;
    cout << "****欢迎来到支出的记录****" << endl;
    cout << "请输入支出信息：" << endl;
    cout << "日期(xxxx年xx月xx日)：";
    cin >> date;
    strcpy(collect2[count2].date, date);
    cout << "金额：";
    cin >> money;
    collect2[count2].money = money;
    totalExpend += money;  // 增加支出总额
    cout << "种类(来源)：";
    cin >> type;
    strcpy(collect2[count2].type, type);
    cout << "备注：";
    cin >> note;
    strcpy(collect2[count2].note, note);
    cout << "支出已成功记录！" << endl; 
    count2++; 
}

void set_budget() {
    cout << "请输入您的预算金额：";
    cin >> monthlyBudget;
    cout << "预算已成功设置！当前预算为：" << monthlyBudget << endl;
}

void show_budget() {
    double remainingBudget = monthlyBudget - totalExpend;
    cout << "当前剩余预算为：" << remainingBudget << endl;
}

void print_bill() {
    cout << "******账单展示******" << endl;
    cout << "****收入账单****" << endl;
    for (int i = 0; i < count1; i++) {
        cout << "日期:" << collect1[i].date 
             << " 金额:" << collect1[i].money 
             << " 种类:" << collect1[i].type 
             << " 备注:" << collect1[i].note << endl; 
    }
    cout << "****支出账单****" << endl;
    for (int j = 0; j < count2; j++) {
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

    if (choice == 1) {
        char queryDate[100];
        cout << "请输入日期进行查询：";
        cin >> queryDate;

        cout << "查询结果:" << endl;
        bool found = false;

        for (int i = 0; i < count1; i++) {
            if (strcmp(collect1[i].date, queryDate) == 0) {
                cout << "日期:" << collect1[i].date 
                     << " 金额:" << collect1[i].money 
                     << " 种类:" << collect1[i].type 
                     << " 备注:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for (int j = 0; j < count2; j++) {
            if (strcmp(collect2[j].date, queryDate) == 0) {
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
    else if (choice == 2) {
        char queryType[100];
        cout << "请输入类型进行查询：";
        cin >> queryType;

        cout << "查询结果:" << endl;
        bool found = false;
        for (int i = 0; i < count1; i++) {
            if (strcmp(collect1[i].type, queryType) == 0) {
                cout << "日期:" << collect1[i].date 
                     << " 金额:" << collect1[i].money 
                     << " 种类:" << collect1[i].type 
                     << " 备注:" << collect1[i].note << endl; 
                found = true;
            }
        }
        for (int j = 0; j < count2; j++) {
            if (strcmp(collect2[j].type, queryType) == 0) {
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
    else {
        cout << "无效选择，请重试。" << endl;
    }
}

void monthly_statistics() {
    char month[7];  // 用于输入月份，如 "2024年04月"
    double totalIncome = 0, totalExpend = 0;
    map<string, double> incomeByCategory, expendByCategory;  // 分类别统计收入和支出

    cout << "请输入需要统计的月份（格式：xxxx年xx月）：";
    cin >> month;

    // 统计收入
    for (int i = 0; i < count1; i++) {
        if (strncmp(collect1[i].date, month, 7) == 0) {  // 比较年份和月份
            totalIncome += collect1[i].money;
            incomeByCategory[collect1[i].type] += collect1[i].money;
        }
    }

    // 统计支出
    for (int j = 0; j < count2; j++) {
        if (strncmp(collect2[j].date, month, 7) == 0) {  // 比较年份和月份
            totalExpend += collect2[j].money;
            expendByCategory[collect2[j].type] += collect2[j].money;
        }
    }

    cout << "月度统计结果 (" << month << "):" << endl;
    cout << "总收入: " << totalIncome << endl;
    cout << "总支出: " << totalExpend << endl;
   // 输出收入按类别统计
cout << "收入按类别统计: " << endl;
for (map<string, double>::iterator it = incomeByCategory.begin(); it != incomeByCategory.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

// 输出支出按类别统计
cout << "支出按类别统计: " << endl;
for (map<string, double>::iterator it = expendByCategory.begin(); it != expendByCategory.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

}

void menu() {
    cout << "**********欢迎使用个人账单管理系统**********" << endl;
    cout << "请选择操作" << endl;
    cout << "1.收入记录" << endl;
    cout << "2.支出记录" << endl;
    cout << "3.账单展示以及账单查询" << endl;
    cout << "4.设置预算" << endl;
    cout << "5.查看剩余预算" << endl;
    cout << "6.月度统计" << endl;
}

int main() {
    int choice, choice1;
Start:
    menu();
    cout << "请输入你要使用的功能：";
    cin >> choice;
    switch (choice) {
        case 1:
            income();
            cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
        case 2:
            expend();
            cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
        case 3:
            print_bill();
            cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
        case 4:
            set_budget();
            cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
        case 5:
            show_budget();
            cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
        default:
            cout << "无效选择，请重试。" << endl;
            break;
        case 6:
			monthly_statistics();
			cout << "请按1返回主菜单" << endl;
            cin >> choice1;
            if (choice1 == 1) goto Start;
            break;
    }
    return 0;
}
