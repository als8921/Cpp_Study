#include <iostream>
#include <cstring>
using namespace std;


enum POS
{
    CLERK,
    SENIOR,
    ASSIST,
    MANAGER
};

class NameCard
{
    private:
        char *name;
        char *company;
        char *phoneNumber;
        POS pos;
    public:
        NameCard(const char *_name, const char *_company, const char *_phoneNumber, POS _pos) : pos(_pos)
        {
            name = new char[strlen(_name) + 1];
            company = new char[strlen(_company) + 1];
            phoneNumber = new char[strlen(_phoneNumber) + 1];

            strcpy(name, _name);
            strcpy(company, _company);
            strcpy(phoneNumber, _phoneNumber);
        }
        void ShowPosition(POS pos) const
        {
            switch (pos)
            {
            case POS::CLERK:
                cout << "직급 : CLERK\n";
                break;
            
            case POS::SENIOR:
                cout << "직급 : SENIOR\n";
                break;
    
            case POS::ASSIST:
                cout << "직급 : ASSIST\n";
                break;
    
            case POS::MANAGER:
                cout << "직급 : MANAGER\n";
                break;
            
            default:
                break;
            }
        }

        void ShowInfo() const
        {
            cout << "이름 : " << name << "\n";
            cout << "회사 : " << company << "\n";
            cout << "전화번호 : " << phoneNumber << "\n";
            ShowPosition(pos);
        }
};