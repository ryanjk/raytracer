#include "Triangle.h"

Triangle::Triangle(Vec3 v1, Vec3 v2, Vec3 v3, ObjectProperties *objectProperties)
{
	ISceneObject::setObjectProperties(objectProperties);

	m_vertices.set(v1, v2, v3);
	computeNormal();
}

Triangle::Triangle(Vertices vertices, ObjectProperties *objectProperties)
{
	ISceneObject::setObjectProperties(objectProperties);
	
	m_vertices = vertices;
}

bool Triangle::rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t)
{
	// e + t*d = a + beta(b - a) + gamma(c - a)

	Mat33 a = createMat33(m_vertices[0] - m_vertices[1], m_vertices[0] - m_vertices[2], viewingRay.getDirection());
	double detA = matrixDeterminant(a);

	Mat33 tMatrix = createMat33(m_vertices[0] - m_vertices[1], m_vertices[0] - m_vertices[2], m_vertices[0] - viewingRay.getOrigin());
	double detT = matrixDeterminant(tMatrix);

	t = detT / detA;

	if (!((lowerLimit <= t) && (t <= upperLimit)))
	{
		return false;
	}

	Mat33 betaMatrix = createMat33(m_vertices[0] - viewingRay.getOrigin(), m_vertices[0] - m_vertices[2], viewingRay.getDirection());
	double detBeta = matrixDeterminant(betaMatrix);

	double beta = detBeta / detA;
	if ((beta < 0) || (1 < beta))
	{
		return false;
	}

	Mat33 gammaMatrix = createMat33(m_vertices[0] - m_vertices[1], m_vertices[0] - viewingRay.getOrigin(), viewingRay.getDirection());
	double detGamma = matrixDeterminant(gammaMatrix);

	double gamma = detGamma / detA;
	if ((gamma < 0) || (gamma > 1 - beta))
	{
		return false;
	}

	return true;
}

Vec3 Triangle::getNormalAt(const Vec3 &surfaceLocation) const
{
	return m_normal;
}

void Triangle::computeNormal()
{
	Vec3 side1 = m_vertices[1] - m_vertices[0];
	Vec3 side2 = m_vertices[2] - m_vertices[0];
	Vec3 normal;

	gmtl::cross(normal, side1, side2);
	gmtl::normalize(normal);

	m_normal = -normal;
}