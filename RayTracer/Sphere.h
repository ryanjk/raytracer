#ifndef SPHERE_H
#define SPHERE_H

#include "ISceneObject.h"
#include "RaytracerMath.h"

class ObjectProperties;

class Sphere : public ISceneObject {
public:
	Sphere(Vec3 center, double radius, ObjectProperties *objectProperties);

	bool rayIntersect(const ViewingRay &viewingRay, double &intersectionPoint);

private:
	Vec3 m_center;
	double m_radius;
};

#endif