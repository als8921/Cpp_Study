#include<iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        void Init(int x, int y)
        {
            xpos = x;
            ypos = y;
        }

        void ShowPointInfo() const
        {
            cout << "[ " << xpos <<", "<< ypos << " ]\n";
        }
};

class Circle
{
    private:
        Point centerpos;
        int radius;
    public:
        void Init(int x, int y, int r)
        {
            centerpos.Init(x, y);
            radius = r;
        }
        void ShowCircleInfo() const
        {
            centerpos.ShowPointInfo();
            cout << "radius : " << radius << "\n";
        }
};


class Ring
{
    private:
        Circle innerCircle;
        Circle outerCircle;
    public:
        void Init(int x1, int y1, int r1, int x2, int y2, int r2)
        {
            innerCircle.Init(x1, y1, r1);
            outerCircle.Init(x2, y2, r2);
        }
        void ShowRingInfo() const
        {
            cout << "innerCircle Info\n";
            innerCircle.ShowCircleInfo();
            cout << "outerCircle Info\n";
            outerCircle.ShowCircleInfo();
        }
};