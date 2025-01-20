/*
    기능 1. 계좌계설
    기능 2. 입금
    기능 3. 출금
    기능 4. 전체고객 잔액조회
    
    고객 정보 : 계좌번호, 이름, 잔액
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

enum COMMAND
{
    CREATE = 1,
    DEPOSIT = 2,
    WITHDRAW = 3,
    SHOWINFO = 4,
    SHOWALLINFO = 5,
    EXIT = 6
};
struct Account
{
    int AccountID = 0;
    int Money = 0;
    string Name = "";
};

map<int, Account> AccountList;
vector<int> AccountIDList;

void ShowUserInfo(int id);
void ShowAllUserInfo();
void CreateAccount(string name);
void Deposit(int id, int money);
void WithDraw(int id, int money);

int main()
{
    while(1)
    {

        cout << "====================== MENU ==========================\n";
        cout << "1. 계좌 개설\n";
        cout << "2. 입금\n";
        cout << "3. 출금\n";
        cout << "4. 내 정보 보기\n";
        cout << "5. 전체 정보 보기\n";
        cout << "6. 프로그램 종료\n";
        cout << "======================================================\n";

        int command;
        cin >> command;
        switch (command)
        {
        case CREATE:
            CreateAccount("Aaaa");
            break;
        case DEPOSIT:
            Deposit(0, 10000);
            break;
        case WITHDRAW:
            WithDraw(0, 6000);
            break;
        case SHOWINFO:
            ShowUserInfo(0);
            break;
        case SHOWALLINFO:
            ShowAllUserInfo();
            break;
        case EXIT:
            return 0;
        default:
            break;
        }
    }
}

void CreateAccount(string name)
{
    int id = AccountIDList.size();
    AccountIDList.push_back(id);

    Account newAccount;
    newAccount.Name = name;
    newAccount.AccountID = id;

    AccountList[id] = newAccount;
}
void ShowUserInfo(int id)
{
    cout << "고객의 이름        : " << AccountList[id].Name << "\n";
    cout << "고객의 계좌 번호   : " << AccountList[id].AccountID << "\n";
    cout << "계좌 잔액          : " << AccountList[id].Money << "\n";
    cout << "======================================================\n";
}
void ShowAllUserInfo()
{
    if(AccountIDList.size())
        for (int id : AccountIDList)
            ShowUserInfo(id);
}
void Deposit(int id, int money)
{
    AccountList[id].Money += money;
}
void WithDraw(int id, int money)
{
    if(AccountList[id].Money >= money)
    {
        AccountList[id].Money -= money;
        cout << money << "원 출금이 완료되었습니다.\n";
        cout << "잔액 : " << AccountList[id].Money << "원\n";
        cout << "======================================================\n";
    }
    else
    {   
        cout << "잔액이 부족합니다.\n";
        cout << "잔액 : " << AccountList[id].Money << "원\n";
        cout << "======================================================\n";
    }
}