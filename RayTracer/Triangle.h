#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ISceneObject.h"

typedef gmtl::Vec<Vec3, 3U> Vertices;

class Triangle : public ISceneObject {
public:
	Triangle(Vec3 v1, Vec3 v2, Vec3 v3, ObjectProperties *objectProperties);
	Triangle(Vertices vertices, ObjectProperties *objectProperties);

	bool rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t);

	Vec3 getNormalAt(const Vec3 &surfaceLocation) const;
private:
	Vertices m_vertices = { Vec3(0, 0, 0), Vec3(0, 0, 0), Vec3(0, 0, 0) };
	Vec3 m_normal;
	void computeNormal();
};

#endif