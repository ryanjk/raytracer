#include "Sphere.h"
#include <iostream>

Sphere::Sphere(Vec3 center, double radius, ObjectProperties *objectProperties)
: m_center(center), m_radius(radius)
{
	ISceneObject::setObjectProperties(objectProperties);
}


bool Sphere::rayIntersect(const ViewingRay &viewingRay, double &intersectionPoint)
{
	Vec3 direction = viewingRay.getDirection();
	double sqrD = gmtl::lengthSquared(direction);

	Vec3 temp;
	temp = viewingRay.getOrigin() - m_center; // (e - c)

	double tempDot = gmtl::dot(direction, temp); // d * (e - c)

	double discriminant = gmtl::Math::sqr(tempDot) - sqrD*(gmtl::lengthSquared(temp) - gmtl::Math::sqr(m_radius));

//	std::cout << "(e - c) = " << temp << "|| d * (e - c) = " << tempDot << "|| disc = " << discriminant << std::endl;

	if (discriminant < 0)
	{
		return false;
	}

	else if (discriminant == 0)
	{
		intersectionPoint = -tempDot / sqrD;

		return true;
	}

	else
	{	
		double sqrtDiscriminant = gmtl::Math::sqrt(discriminant);
		double t1 = (-tempDot + sqrtDiscriminant) / sqrD;
		double t2 = (-tempDot - sqrtDiscriminant) / sqrD;
		intersectionPoint = gmtl::Math::Min(t1, t2);
//		std::cout << intersectionPoint << std::endl;

		return true;
	}
}