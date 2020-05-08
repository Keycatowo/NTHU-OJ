#include <iostream>
#include <string>
#include <vector>
#include "function.h"
using namespace std;

namespace oj
{
    Point::Point(int x_coord, int y_coord): x(x_coord), y(y_coord) {}

    Shape::Shape(): area(0) {}

	Shape::~Shape(){}

    Rectangle::Rectangle(): width(0), height(0) {}

    Circle::Circle(): radius(0) {}
}

int main()
{
  freopen("input.txt","r",stdin);
	using namespace oj;

    int ans = 0;
    string shape;
    vector<Shape*> shapeList;

    while(cin >> shape) {
        if(shape == "R") {
            Rectangle *rect = new Rectangle();
            rect->draw();
            shapeList.push_back(rect);
            //cout << "Rect: " << rect->getArea() << endl;
        }
        else if(shape == "C") {
            Circle *cir = new Circle();
            cir->draw();
            shapeList.push_back(cir);
            //cout << "Cir: " << cir->getArea() << endl;
        }
    }

    while(!shapeList.empty()) {
        ans += shapeList.back()->getArea();
		delete shapeList.back();
        shapeList.pop_back();
    }
    cout << ans << endl;

    return 0;
}
