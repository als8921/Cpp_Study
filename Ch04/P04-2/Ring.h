#include<iostream>
#include "Circle.h"

using namespace std;
class Ring
{
    private:
        Circle innerCircle;
        Circle outerCircle;
    public:
        Ring(int x1, int y1, int r1, int x2, int y2, int r2) : innerCircle(x1, y1, r1), outerCircle(x2, y2, r2)
        {
        
        }
        void ShowRingInfo() const
        {
            cout << "innerCircle Info\n";
            innerCircle.ShowCircleInfo();
            cout << "outerCircle Info\n";
            outerCircle.ShowCircleInfo();
        }
};