#include "HitRecord.h"

void HitRecord::create(ISceneObject *hitSurface, Vec3 hitPoint)
{
	m_hitSurface = hitSurface;
	m_hitPoint = hitPoint;
	m_normal = m_hitSurface->getNormalAt(hitPoint);
	m_surfaceColour = hitSurface->getObjectProperties()->getColour();
}

ISceneObject *HitRecord::getSurface() const
{
	return m_hitSurface;
}

Vec3 HitRecord::getHitPoint() const
{
	return m_hitPoint;
}

Vec3 HitRecord::getNormal() const
{
	return m_normal;
}

Colour HitRecord::getSurfaceColour() const
{
	return m_surfaceColour;
}