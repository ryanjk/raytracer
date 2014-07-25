#ifndef SPHERE_H
#define SPHERE_H

#include "ISceneObject.h"
#include "RaytracerMath.h"

class ObjectProperties;

class Sphere : public ISceneObject {
public:
	Sphere(Vec3 center, double radius, ObjectProperties *objectProperties);

	bool rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t);

	Vec3 getNormalAt(const Vec3 &surfaceLocation) const;

private:
	Vec3 m_center;
	double m_radius;
};

#endif