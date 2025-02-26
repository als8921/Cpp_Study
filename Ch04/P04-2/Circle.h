#include<iostream>
#include "Point.h"
using namespace std;

class Circle
{
    private:
        Point centerpos;
        int radius;
    public:
        Circle(int x, int y, int r)
            :centerpos(x, y), radius(r)
            {

            }
        void ShowCircleInfo() const
        {
            centerpos.ShowPointInfo();
            cout << "radius : " << radius << "\n";
        }
};