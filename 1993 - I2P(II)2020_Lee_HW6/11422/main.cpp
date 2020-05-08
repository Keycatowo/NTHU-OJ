#include <iostream>
#include <string>
#include "function.h"
using namespace std;

namespace oj
{
    void Shape::setArea(double a)
    {
        area = a;
    }

    void Shape::setPerimeter(double p)
    {
        perimeter = p;
    }

    double Shape::getArea()
    {
        return area;
    }

    double Shape::getPerimeter()
    {
        return perimeter;
    }
}


int main(void)
{
    freopen("input.txt","r",stdin);
    using namespace oj;

    string s;
    double a, b, c;
    double totalArea = 0.0, totalPerimeter = 0.0;

    while(cin >> s) {
        if(s == "Triangle") {
            cin >> a >> b >> c;
            Triangle T(a, b, c);
            totalArea += T.getArea();
            totalPerimeter += T.getPerimeter();
        }
        if(s == "Rectangle") {
            cin >> a >> b;
            Rectangle R(a, b);
            totalArea += R.getArea();
            totalPerimeter += R.getPerimeter();
        }
        if(s == "Circle") {
            cin >> a >> b;
            Circle C(a, b);
            totalArea += C.getArea();
            totalPerimeter += C.getPerimeter();
        }
    }

    cout << totalArea << endl;
    cout << totalPerimeter << endl;


    return 0;
}
