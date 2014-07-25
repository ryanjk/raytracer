#include "Quad.h"

Quad::Quad(Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4, ObjectProperties *objectProperties)
{
	m_triangles[0] = Triangle(v1, v2, v3, objectProperties);
	m_triangles[1] = Triangle(v3, v4, v1, objectProperties);

	ISceneObject::setObjectProperties(objectProperties);

	initializeNormal();
}

Quad::Quad(Vec3 center, Vec3 normal, double radius, ObjectProperties *objectProperties)
{

}

bool Quad::rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t)
{
	bool hit = false;
	unsigned int currentTriangle = 0;
	while (!hit && currentTriangle < 2)
	{
		hit = m_triangles[currentTriangle].rayIntersect(viewingRay, lowerLimit, upperLimit, t);
		currentTriangle++;
	}

	return hit;
}

Vec3 Quad::getNormalAt(const Vec3 &surfaceLocation) const
{
	return m_normal;
}

void Quad::initializeNormal()
{
	m_normal = m_triangles[0].getNormalAt({ 0, 0, 0 });
}


