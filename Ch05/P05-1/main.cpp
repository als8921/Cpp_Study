#include "NameCard.h"

int main()
{
    NameCard aaa("Lee", "ABC", "010-2222-3333", POS::MANAGER);
    NameCard copy1 = aaa;
    copy1.ShowInfo();
}