#ifndef FUNCTION_H
#define FUNCTION_H
#include <vector>
#define PI 3

namespace oj
{
  /// Point
	struct Point
	{
		Point(int, int);
        int x;
        int y;
    };

  /// Shape
	class Shape
	{
	public:
		Shape();
		inline int getArea() const
		{
			return area;
		}
        virtual void draw() = 0;
		virtual ~Shape();

	protected:
        std::vector<Point> points;
		int area;
	};

  /// Rectangle -> Shape
	class Rectangle : public Shape
	{
	public:
		Rectangle();
        void draw();

	private:
		int width;
		int height;
	};

  /// Circle -> Shape
	class Circle : public Shape
	{
	public:
		Circle();
        void draw();

	private:
		int radius;
	};
}

#endif
