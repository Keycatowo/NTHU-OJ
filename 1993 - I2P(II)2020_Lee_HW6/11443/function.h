#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
  /// Shape 3D
	class Shape3D
	{
		double volume;

	public:
		double getVolume();

	protected:
		void setVolume(double volume);
	};

	/// Sphere -> Shape 3D
	class Sphere : public Shape3D
	{
		double radius;
		double pi;

	public:
		Sphere(double, double);
	};

	/// Cone -> Shape 3D
	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};

	/// Cuboid -> Shape 3D
	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;

	public:
		Cuboid(double, double, double);
	};

	/// Cube -> Cuboid -> Shape 3D
	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
}


#endif
