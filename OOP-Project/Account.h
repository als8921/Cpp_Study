#include <iostream>
#include <cstring>

using namespace std;

class Account
{
    private:
        int money;
        char * name;

    public:
        int accountID;
        Account(int accountID, int money, char *name)
        {
            this->accountID = accountID;
            this->money = money;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }


        inline void ShowUserInfo() const
        {
            cout << "[계좌 조회]\n";

            cout << "고객의 이름        : " << name << "\n";
            cout << "고객의 계좌 번호   : " << accountID << "\n";
            cout << "계좌 잔액          : " << money << "\n";
            cout << "======================================================\n";
        }

        void Deposit(int money)
        {
            this->money += money;

            cout << money << "원 입금이 완료되었습니다.\n";
            cout << "잔액 : " << this->money << "원\n";
            cout << "======================================================\n";
        }

        void WithDraw(int money)
        {
            if(this->money >= money)
            {
                this->money -= money;
                cout << money << "원 출금이 완료되었습니다.\n";
            }
            else
            {   
                cout << "잔액이 부족합니다.\n";
            }
            cout << "잔액 : " << this->money << "원\n";
            cout << "======================================================\n";
        }

        ~Account()
        {
            delete[] name;
        }
};