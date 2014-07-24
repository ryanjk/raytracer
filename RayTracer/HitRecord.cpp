#include "HitRecord.h"

void HitRecord::create(ISceneObject *hitSurface, Vec3 hitPoint)
{
	m_hitSurface = hitSurface;
	m_hitPoint = hitPoint;
	m_normal = m_hitSurface->getNormalAt(hitPoint);
}

ISceneObject *HitRecord::getSurface()
{
	return m_hitSurface;
}

Vec3 HitRecord::getHitPoint()
{
	return m_hitPoint;
}

Vec3 HitRecord::getNormal()
{
	return m_normal;
}