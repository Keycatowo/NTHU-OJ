#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape 
	{	
	public:
		double getArea();
		double getPerimeter();
	
	protected:
		void setArea(double a);
		void setPerimeter(double p);
			
	private:
		double area;
		double perimeter;
	};

	class Triangle : public Shape
	{
	public:
		Triangle(double edge1, double edge2, double edge3);
		
	private:
		double edge1;
		double edge2;
		double edge3;
		
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle(double width, double height);
		
	private:
		double width;
		double height;
	};

	class Circle : public Shape
	{
	public:
		Circle(double radius, double pi);
		
	private:
		double radius;
		double pi;
	};
}


#endif
