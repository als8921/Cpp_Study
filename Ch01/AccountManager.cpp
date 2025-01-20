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

void ShowUserInfo();
void ShowUserInfo(int id);
void ShowAllUserInfo();
void CreateAccount();
void Deposit();
void WithDraw();
bool IsExistAccount(int id);

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
        cout << "선택 : ";
        cin >> command;
        switch (command)
        {
        case CREATE:
            CreateAccount();
            break;
        case DEPOSIT:
            Deposit();
            break;
        case WITHDRAW:
            WithDraw();
            break;
        case SHOWINFO:
            ShowUserInfo();
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

void CreateAccount()
{
    string name;
    cout << "[계좌 생성]\n";
    cout << "이름 입력해주세요 : "; cin >> name;
    int id = AccountIDList.size();
    AccountIDList.push_back(id);

    Account newAccount;
    newAccount.Name = name;
    newAccount.AccountID = id;

    AccountList[id] = newAccount;

    cout << "고객의 이름        : " << AccountList[id].Name << "\n";
    cout << "고객의 계좌 번호   : " << AccountList[id].AccountID << "\n";
    cout << "계좌 잔액          : " << AccountList[id].Money << "\n";
    cout << "======================================================\n";
}
void ShowUserInfo()
{
    int id;
    cout << "[계좌 조회]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    if(!IsExistAccount(id)) return;

    cout << "고객의 이름        : " << AccountList[id].Name << "\n";
    cout << "고객의 계좌 번호   : " << AccountList[id].AccountID << "\n";
    cout << "계좌 잔액          : " << AccountList[id].Money << "\n";
    cout << "======================================================\n";
}
void ShowUserInfo(int id)
{
    cout << "[계좌 조회]\n";

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
void Deposit()
{
    int id, money;
    cout << "[입금]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    cout << "입금할 금액을 입력해주세요 : "; cin >> money;
    AccountList[id].Money += money;


    cout << money << "원 입금이 완료되었습니다.\n";
    cout << "잔액 : " << AccountList[id].Money << "원\n";
    cout << "======================================================\n";
}
void WithDraw()
{
    int id, money;
    cout << "[출금]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    cout << "출금할 금액을 입력해주세요 : "; cin >> money;
    if(AccountList[id].Money >= money)
    {
        AccountList[id].Money -= money;
        cout << money << "원 출금이 완료되었습니다.\n";
    }
    else
    {   
        cout << "잔액이 부족합니다.\n";
    }
    cout << "잔액 : " << AccountList[id].Money << "원\n";
    cout << "======================================================\n";
}

bool IsExistAccount(int id)
{
    for(int _id : AccountIDList)
        if(_id == id) return true;

    
    cout << "존재하지 않는 계좌번호 입니다.\n";
    return false;
}