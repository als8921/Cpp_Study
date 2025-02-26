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

#include "Account.h"

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

Account *AccountList[100];
int AccountCnt = 0;

void ShowUserInfo();
void ShowAllUserInfo();
void CreateAccount();
void Deposit();
void WithDraw();

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
    int id, money;
    char name[100];
    cout << "[계좌 생성]\n";
    cout << "계좌 번호를 입력해주세요 : "; cin >> id;
    cout << "이름 입력해주세요 : "; cin >> name;
    cout << "금액을 입력해주세요 : "; cin >> money;

    AccountList[AccountCnt++] = new Account(id, money, name);
}

void ShowUserInfo()
{
    int id;
    cout << "[계좌 조회]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    

    for(int i = 0; i < AccountCnt; i++)
    {
        if(AccountList[i]->accountID == id)
        {
            AccountList[i]->ShowUserInfo();
            return;
        }
    }
    cout << "존재하지 않는 계좌번호 입니다.\n";
    cout << "======================================================\n";
}
void ShowAllUserInfo()
{
    for(int i = 0; i < AccountCnt; i++)
    {
        AccountList[i]->ShowUserInfo();
    }
}
void Deposit()
{
    int id, money;
    cout << "[입금]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    cout << "입금할 금액을 입력해주세요 : "; cin >> money;


    for(int i = 0; i < AccountCnt; i++)
    {
        if(AccountList[i]->accountID == id)
        {
            AccountList[i]->Deposit(money);
            return;
        }
    }
    cout << "존재하지 않는 계좌번호 입니다.\n";
    cout << "======================================================\n";
}

void WithDraw()
{
    int id, money;
    cout << "[출금]\n";
    cout << "계좌번호를 입력해주세요 : "; cin >> id;
    cout << "출금할 금액을 입력해주세요 : "; cin >> money;

    for(int i = 0; i < AccountCnt; i++)
    {
        if(AccountList[i]->accountID == id)
        {
            AccountList[i]->WithDraw(money);
            return;
        }
    }
    cout << "존재하지 않는 계좌번호 입니다.\n";
    cout << "======================================================\n";
}