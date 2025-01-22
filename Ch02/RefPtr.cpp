#include <iostream>
using namespace std;

int main()
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref=num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << &num << " : " << num << "\n";
    cout << &ref << " : " << ref << "\n";
    cout << &pref << " : " << *pref << "\n";
    cout << &dpref << " : " << **dpref << "\n";
}