#ifndef Quad_H
#define Quad_H

#include "ISceneObject.h"
#include "Triangle.h"

typedef gmtl::Vec<Triangle, 2> Triangles;

class Quad : public ISceneObject {
public:
	Quad(Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4, ObjectProperties *objectProperties);
	Quad(Vec3 center, Vec3 normal, double radius, ObjectProperties *objectProperties);

	bool rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t);

	Vec3 getNormalAt(const Vec3 &surfaceLocation) const;
private:
	Triangles m_triangles = { Triangle(), Triangle() };
	Vec3 m_normal;
	void initializeNormal();
};

#endif